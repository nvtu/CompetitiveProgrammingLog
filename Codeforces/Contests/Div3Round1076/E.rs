use std::io::{ self, BufRead };
use std::str::FromStr;
use std::cmp::min;
use std::collections::BTreeMap;

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
    let a: Vec<i32> = sc.next_values(n);
    let mut count: BTreeMap<i32, i32> = BTreeMap::new();
    for i in 0..n {
        *count.entry(a[i]).or_insert(0) += 1;
    }
    let mut ans: Vec<i32> = vec![i32::MAX; n+1];
    for i in 1..n + 1 {
        if *count.get(&(i as i32)).unwrap_or(&0) > 0 {
            ans[i] = 1;
        } else {
            let sqrt: usize = ((i as f32).sqrt() as usize) + 1;
            for j in 2..sqrt {
                if i % j == 0 && ans[j] != -1 && ans[i / j] != -1 {
                    ans[i] = min(ans[i], ans[j] + ans[i / j]);
                }
            }
        }
        if ans[i] == i32::MAX {
            ans[i] = -1;
        }
        print!("{} ", ans[i]);
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
