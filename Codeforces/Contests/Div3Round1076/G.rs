#![allow(dead_code)]
use std::io::{ self, BufRead, Write };
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
                return std::str
                    ::from_utf8(&self.buffer[start..self.pos])
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

fn dfs(node: usize, edges: &[Vec<usize>], visited: &mut [bool], h: &mut Vec<usize>) {
    visited[node] = true;
    h.push(node);
    for &v in &edges[node] {
        if !visited[v] {
            dfs(v, edges, visited, h);
        }
    }
}

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let mut edges: Vec<Vec<usize>> = vec![vec![]; n + 1];
    let mut visited: Vec<bool> = vec![false; n+1];
    let mut h: Vec<usize> = Vec::new();
    for _ in 0..n - 1 {
        let u: usize = sc.next();
        let v: usize = sc.next();
        edges[u].push(v);
        edges[v].push(u);
    }
    dfs(1, &edges, &mut visited, &mut h);
    for i in (0..n - 1).step_by(2) {
        println!("? {} {}", h[i], h[i + 1]);
        io::stdout().flush().unwrap();
        let mut res: i32 = sc.next();
        if res == 1 {
            println!("? {} {}", h[i], h[i]);
            io::stdout().flush().unwrap();
            res = sc.next();
            println!("! {}", if res == 1 { h[i] } else { h[i + 1] });
            return;
        }
    }
    println!("! {}", h[n - 1]);
    io::stdout().flush().unwrap();
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
