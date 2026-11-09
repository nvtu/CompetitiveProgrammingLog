#![allow(dead_code)]
use std::io::{ self, BufRead };
use std::str::FromStr;
use std::cmp::{ min, max };

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

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let a: (i64, i64) = (sc.next(), sc.next());
    let b: (i64, i64) = (sc.next(), sc.next());
    let mut p: Vec<(i64, i64)> = vec![(0, 0); n];
    for i in 0..n {
        p[i].0 = sc.next();
    }
    for i in 0..n {
        p[i].1 = sc.next();
    }
    p.sort_unstable();
    p.push((0, 0));
    let mut mmin: i64 = i64::MAX;
    let mut mmax: i64 = 0;
    let mut pizza: Vec<Vec<i64>> = Vec::new();
    let mut ans: i64 = p[0].0 - a.0 + b.0 - p[n - 1].0;

    pizza.push([a.1, a.1].to_vec());
    for i in 1..n + 1 {
        mmin = min(mmin, p[i - 1].1);
        mmax = max(mmax, p[i - 1].1);
        if p[i].0 != p[i - 1].0 {
            pizza.push([mmin, mmax].to_vec());
            mmin = i64::MAX;
            mmax = 0;
            if i < n {
                ans += p[i].0 - p[i - 1].0;
            }
        }
    }
    pizza.push([b.1, b.1].to_vec());
    let m: usize = pizza.len();
    let mut f: Vec<Vec<i64>> = vec![vec![i64::MAX; 2]; m];
    f[0][0] = 0;
    f[0][1] = 0;
    for i in 1..m {
        for j in 0..2 {
            f[i][j] = min(
                f[i][j],
                min(
                    f[i - 1][j] + (pizza[i - 1][j] - pizza[i][1 - j]).abs(),
                    f[i - 1][1 - j] + (pizza[i - 1][1 - j] - pizza[i][1 - j]).abs()
                ) + (pizza[i][j] - pizza[i][1 - j]).abs()
            );
        }
    }
    ans += f[m - 1][0];
    println!("{}", ans);
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
