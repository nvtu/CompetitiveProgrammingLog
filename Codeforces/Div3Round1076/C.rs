use std::io::{ self, BufRead };
use std::str::FromStr;
use std::cmp::max;

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
    let q: usize = sc.next();
    let a: Vec<i32> = sc.next_values(n);
    let b: Vec<i32> = sc.next_values(n);
    let mut c: Vec<i32> = a.clone();
    for i in (0..n).rev() {
        c[i] = max(a[i], b[i]);
        if i < n - 1 {
            c[i] = max(c[i], c[i + 1]);
        }
    }
    let psum: Vec<i32> = std::iter
        ::once(0)
        .chain(
            c.iter().scan(0, |s, x| {
                *s += x;
                Some(*s)
            })
        )
        .collect();
    for _ in 0..q {
        let l: usize = sc.next();
        let r: usize = sc.next();
        print!("{} ", psum[r] - psum[l - 1]);
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
