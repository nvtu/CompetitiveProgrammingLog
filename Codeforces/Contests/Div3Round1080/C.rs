use std::cmp::min;
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

fn is_adjacent_pairs(a: usize, b: usize) -> bool {
    if a > b {
        return is_adjacent_pairs(b, a);
    }
    let adj_pairs: Vec<(usize, usize)> = vec![
        (1, 2),
        (1, 3),
        (1, 4),
        (1, 5),
        (2, 3),
        (2, 4),
        (2, 6),
        (3, 5),
        (3, 6),
        (4, 5),
        (4, 6),
        (5, 6),
    ];
    for &p in &adj_pairs {
        if a == p.0 && b == p.1 {
            return true;
        }
    }
    return false;
}

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let a: Vec<usize> = sc.next_values(n);
    let mut f: Vec<i32> = vec![0; n + 1];
    for i in 1..n {
        if !is_adjacent_pairs(a[i], a[i - 1]) {
            f[i] = f[i - 1] + 1;
            if i >= 2_usize {
                f[i] = min(f[i], f[i - 2] + 1);
            }
        } else {
            f[i] = f[i - 1];
        }
    }
    println!("{}", f[n - 1]);
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
