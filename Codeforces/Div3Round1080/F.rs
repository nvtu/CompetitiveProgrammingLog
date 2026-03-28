#![allow(dead_code)]
use std::cmp::max;
use std::io::{self, BufRead};
use std::str::FromStr;

struct Scanner<R> {
    reader: R,
    buffer: Vec<u8>,
    pos: usize,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader: reader,
            buffer: Vec::new(),
            pos: 0,
        }
    }

    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if self.pos >= self.buffer.len() {
                self.buffer.clear();
                self.reader.read_until(b'\n', &mut self.buffer).unwrap();
                self.pos = 0;
            }
            while self.pos < self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {
                self.pos += 1;
            }
            if self.pos < self.buffer.len() {
                let start: usize = self.pos;
                while self.pos < self.buffer.len() && !self.buffer[self.pos].is_ascii_whitespace() {
                    self.pos += 1;
                }
                return std::str::from_utf8(&self.buffer[start..self.pos])
                    .unwrap()
                    .parse::<T>()
                    .ok()
                    .unwrap();
            }
        }
    }

    fn next_values<T: FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}

#[derive(Clone, Copy, Debug)]
struct Parabola {
    a: f32,
    b: f32,
    c: f32,
}

fn compare(p1: Parabola, p2: Parabola) -> i32 {
    let p: Parabola = Parabola {
        a: p1.a - p2.a,
        b: p1.b - p2.b,
        c: p1.c - p2.c,
    };
    if p.a == 0.0 {
        if p.b == 0.0 {
            if p.c < 0.0 {
                return -1;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    }
    let delta: f32 = p.b * p.b - 4.0 * p.a * p.c;
    if delta < 0.0 {
        if p.a < 0.0 {
            return -1;
        }
        return 1;
    }
    return 0;
}

fn dfs(u: usize, edges: &Vec<Vec<usize>>, visited: &mut [bool], ans: &mut [usize]) -> usize {
    if visited[u] {
        return ans[u];
    }
    visited[u] = true;
    let mut max_len: usize = 0;
    for &v in &edges[u] {
        max_len = max(max_len, dfs(v, edges, visited, ans));
    }
    ans[u] = max(ans[u], max_len + 1);
    ans[u]
}

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let mut points: Vec<Parabola> = Vec::with_capacity(n);
    for _ in 0..n {
        points.push(Parabola {
            a: sc.next(),
            b: sc.next(),
            c: sc.next(),
        });
    }
    let mut dp_start: Vec<usize> = vec![0; n + 1];
    let mut dp_end: Vec<usize> = vec![0; n + 1];
    let mut visited: Vec<bool> = vec![false; n + 1];
    let mut edges: Vec<Vec<usize>> = vec![vec![]; n + 1];
    let mut edges_r: Vec<Vec<usize>> = vec![vec![]; n + 1];
    for i in 0..n {
        for j in i + 1..n {
            let comp: i32 = compare(points[i], points[j]);
            if comp < 0 {
                edges[i + 1].push(j + 1);
                edges_r[j + 1].push(i + 1);
            } else if comp > 0 {
                edges[j + 1].push(i + 1);
                edges_r[i + 1].push(j + 1);
            }
        }
    }
    for i in 1..n + 1 {
        dfs(i, &edges, &mut visited, &mut dp_start);
    }
    visited = vec![false; n + 1];
    for i in 1..=n {
        dfs(i, &edges_r, &mut visited, &mut dp_end);
    }
    for i in 1..n + 1 {
        print!("{} ", dp_start[i] + dp_end[i] - 1);
    }
    println!("");
}

fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let mut t: usize = sc.next();
    while t > 0 {
        t -= 1;
        solve(&mut sc);
    }
}
