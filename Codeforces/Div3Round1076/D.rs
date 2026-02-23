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
    let mut a: Vec<i64> = sc.next_values(n);
    let b: Vec<i64> = sc.next_values(n);
    a.sort();
    a.push(0);
    let mut cnt: i64 = 1;
    let mut a_with_cnt: Vec<(i64, i64)> = Vec::new();
    for i in 1..n + 1 {
        if a[i] == a[i - 1] {
            cnt += 1;
        } else {
            a_with_cnt.push((a[i - 1], cnt));
            cnt = 1;
        }
    }
    let b_pcount: Vec<i64> = b
        .iter()
        .scan(0, |s, x| {
            *s += x;
            Some(*s)
        })
        .collect();
    let mut agg_count: Vec<i64> = vec![0; a_with_cnt.len() + 1];
    for i in (0..a_with_cnt.len()).rev() {
        agg_count[i] = agg_count[i + 1] + a_with_cnt[i].1;
    }
    let mut ans: i64 = 0;
    for i in 0..a_with_cnt.len() {
        let count: i64 = agg_count[i];
        let j: usize = b_pcount.partition_point(|x| *x <= count);
        let score: i64 = a_with_cnt[i].0 * (j as i64);
        ans = max(ans, score);
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
