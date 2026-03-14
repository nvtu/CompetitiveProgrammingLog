use std::collections::{BinaryHeap, VecDeque};
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
    let k: usize = sc.next();
    let p: usize = sc.next();
    let mut m: i32 = sc.next();
    let mut q: VecDeque<(usize, i32)> = VecDeque::new();
    let mut h: BinaryHeap<(usize, i32)> = BinaryHeap::new();
    let a: Vec<i32> = sc.next_values(n);
    for i in 0..n {
        let is_win_pos: usize = if i + 1 == p { 1 } else { 0 };
        if i < k {
            h.push((is_win_pos, -a[i]));
        } else {
            q.push_back((is_win_pos, -a[i]));
        }
    }
    let mut ans: usize = 0;
    while m > 0 {
        let (is_win_pos, energy) = h.pop().unwrap();
        m += energy;
        if m >= 0 {
            ans += is_win_pos;
        }
        q.push_back((is_win_pos, energy));
        h.push(q.pop_front().unwrap());
    }
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
