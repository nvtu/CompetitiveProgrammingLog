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

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let mut a: Vec<usize> = sc.next_values(n);
    let mut mark: Vec<bool> = vec![false; n + 1];
    for i in 1..(n / 2 + 1) {
        if mark[i] {
            continue;
        }
        let mut j: usize = i;
        let mut temp: Vec<usize> = Vec::new();
        while j < n + 1 {
            if !mark[j] {
                mark[j] = true;
                temp.push(a[j - 1]);
            }
            j <<= 1;
        }
        temp.sort();
        j = i;
        for &v in &temp {
            a[j - 1] = v;
            j <<= 1;
        }
    }
    for i in 1..n {
        if a[i] < a[i - 1] {
            println!("NO");
            return;
        }
    }
    println!("YES");
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
