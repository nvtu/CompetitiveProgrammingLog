#![allow(dead_code)]
use std::collections::VecDeque;
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

fn dfs(
    u: usize,
    a: &[usize],
    edges: &[Vec<usize>],
    visited: &mut [bool],
    removed: &[bool],
    sz: &mut [usize],
    bad: &mut [usize],
) {
    visited[u] = true;
    for &v in &edges[u] {
        if !visited[v] && !removed[v] && a[v] == 1 {
            dfs(v, a, edges, visited, removed, sz, bad);
            if sz[v] % 2 == 0 {
                bad[u] += 1;
            } else {
                bad[v] += 1;
            }
            sz[u] += sz[v];
        }
    }
}

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let mut a: Vec<usize> = vec![0; n + 1];
    let mut visited: Vec<bool> = vec![false; n + 1];
    let mut edges: Vec<Vec<usize>> = vec![vec![]; n + 1];
    let mut sz: Vec<usize> = vec![1; n + 1];
    let mut removed: Vec<bool> = vec![false; n + 1];
    let mut s: Vec<usize> = vec![0; n + 1];
    let mut bad: Vec<usize> = vec![0; n + 1];
    for i in 1..n + 1 {
        a[i] = sc.next();
        a[i] %= 2;
    }
    for _ in 0..n - 1 {
        let u: usize = sc.next();
        let v: usize = sc.next();
        edges[u].push(v);
        edges[v].push(u);
        s[u] += a[v];
        s[v] += a[u];
    }
    let mut ans: Vec<usize> = Vec::new();
    for i in 1..n + 1 {
        if a[i] == 0 {
            if s[i] % 2 == 1 {
                ans.push(i);
                removed[i] = true;
            } else if s[i] == 0 {
                println!("NO");
                return;
            }
        }
    }

    let mut q: VecDeque<usize> = VecDeque::new();
    for u in 1..n + 1 {
        if !removed[u] && !visited[u] && a[u] == 1 {
            dfs(u, &a, &edges, &mut visited, &mut removed, &mut sz, &mut bad);
            if sz[u] % 2 == 0 {
                println!("NO");
                return;
            }
        }
    }

    for u in 1..n + 1 {
        if !removed[u] && bad[u] == 0 && s[u] % 2 == 0 && a[u] == 1 {
            q.push_back(u);
        }
    }

    while !q.is_empty() {
        let u: usize = q.pop_front().unwrap();
        ans.push(u);
        removed[u] = true;
        for &v in &edges[u] {
            if !removed[v] {
                s[v] -= a[u];
                if a[v] == 0 && s[v] % 2 == 1 && !removed[v] {
                    ans.push(v);
                    removed[v] = true;
                }
            }
        }
        for &v in &edges[u] {
            if !removed[v] && a[v] == 1 {
                bad[v] -= 1;
                if bad[v] == 0 {
                    q.push_back(v);
                }
            }
        }
    }

    println!("YES");
    for &u in &ans {
        print!("{} ", u);
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
