use std::io::{ self, BufRead };
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

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let p: Vec<i32> = sc.next_values(n);
    let mut mmax: Vec<(i32, usize)> = vec![(0, 0); n];
    mmax[n - 1] = (p[n - 1], n - 1);
    for i in (0..n - 1).rev() {
        mmax[i] = if p[i] > mmax[i + 1].0 { (p[i], i) } else { mmax[i + 1] };
    }
    let mut i: usize = 0;
    let mut rev: bool = false;
    while i < n {
        if p[i] != mmax[i].0 && !rev {
            for j in (i..mmax[i].1 + 1).rev() {
                print!("{} ", p[j]);
            }
            i = mmax[i].1 + 1;
            rev = true;
            continue;
        }
        print!("{} ", p[i]);
        i += 1;
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
