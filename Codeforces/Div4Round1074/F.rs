#![allow(dead_code)]
use std::io::{ self, BufRead };
use std::str::FromStr;
use std::cmp::min;

struct Scanner<R> {
    reader: R,
    buffer: Vec<u8>,
    pos: usize,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
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

struct Solution {
    n: usize,
    q: usize,
    a: Vec<i32>,
    b: Vec<usize>,
    c: Vec<i32>,
}

impl Solution {
    fn new<R: BufRead>(sc: &mut Scanner<R>) -> Self {
        let n: usize = sc.next();
        let q: usize = sc.next();
        let a: Vec<i32> = sc.next_values(1 << n);
        let (b, c): (Vec<usize>, Vec<i32>) = (0..q)
            .map(|_| (sc.next::<usize>(), sc.next::<i32>()))
            .unzip();
        Self { n, q, a, b, c }
    }

    fn solve(self) {
        let prexor: Vec<i32> = std::iter
            ::once(0)
            .chain(
                self.a.iter().scan(0, |s, x| {
                    *s ^= x;
                    Some(*s)
                })
            )
            .collect();
        for i in 0..self.q {
            let mut ans: i32 = 0;
            let mut pos: usize = self.b[i] - 1;
            let mut current_index: usize = self.b[i];
            for j in 0..self.n {
                let round_size: usize = 1 << j;
                current_index = if round_size > 1 {
                    (current_index + 1) / 2
                } else {
                    current_index
                };
                let mut current_xor: i32 = prexor[min(pos + round_size, 1 << self.n)] ^ prexor[pos];
                current_xor ^= self.a[self.b[i] - 1] ^ self.c[i];
                if current_index % 2 == 0 {
                    // If the current index is even after round j,
                    // then consider fighting with the LHS
                    let mut neighbor_xor: i32 = prexor[pos];
                    pos = if pos >= round_size { pos - round_size } else { 0 };
                    neighbor_xor ^= prexor[pos];
                    if neighbor_xor >= current_xor {
                        ans += round_size as i32;
                    }
                } else {
                    // If the current index is odd after round j,
                    // then consider fighting with the RHS
                    let neighbor_xor: i32 =
                        prexor[pos + round_size] ^ prexor[min(pos + 2 * round_size, 1 << self.n)];
                    if neighbor_xor > current_xor {
                        ans += round_size as i32;
                    }
                }
            }
            println!("{}", ans);
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let mut t: usize = sc.next();
    while t > 0 {
        t -= 1;
        let solver: Solution = Solution::new(&mut sc);
        solver.solve();
    }
}
