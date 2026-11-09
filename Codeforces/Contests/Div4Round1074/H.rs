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

struct Solution {
    n: usize,
    k: i64,
    a: Vec<i64>,
}

impl Solution {
    fn new<R: BufRead>(sc: &mut Scanner<R>) -> Self {
        let n: usize = sc.next();
        Self {
            n: n,
            k: sc.next(),
            a: sc.next_values(n),
        }
    }

    fn range_sum_ignoring_index(&self, psum: &[i64], l: usize, r: usize, index: usize) -> i64 {
        let mut ans: i64 = 0;
        if r < l {
            return ans;
        }
        if r < index {
            ans = psum[r] - (if l == 0 { 0_i64 } else { psum[l - 1] });
            return ans;
        }
        if l > index {
            ans = psum[r + 1] - psum[l];
        } else {
            ans = psum[r + 1] - (if l == 0 { 0_i64 } else { psum[l - 1] }) - self.a[index];
        }
        ans
    }

    fn upper_bound_ignoring_index(&self, psum: &[i64], target: i64, index: usize) -> usize {
        let mut l: usize = 0;
        let mut r: usize = self.n - 1;
        while l <= r {
            let mid: usize = (l + r) >> 1;
            if mid == 0 || self.range_sum_ignoring_index(&psum, 0, mid - 1, index) < target {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        r
    }

    fn solve(&self) {
        let psum: Vec<i64> = self.a
            .iter()
            .scan(0, |s, x| {
                *s += x;
                Some(*s)
            })
            .collect();
        for i in 0..self.n {
            let mut ans: i64 = 0;
            let last_starting_pos: usize = self.upper_bound_ignoring_index(&psum, self.a[i], i);
            let mut bad_positions: Vec<usize> = Vec::new();
            let mut current_psum: i64 = 0;
            loop {
                let v: i64 = current_psum + self.a[i];
                let bad_pos: usize = self.upper_bound_ignoring_index(
                    &psum,
                    v * 2 + 1 - self.a[i],
                    i
                );
                if bad_pos >= self.n - 1 {
                    break;
                }
                let psum_before_bad_v: i64 =
                    (if bad_pos >= 1 {
                        self.range_sum_ignoring_index(&psum, 0, bad_pos - 1, i)
                    } else {
                        0_i64
                    }) + self.a[i];
                if self.range_sum_ignoring_index(&psum, bad_pos, bad_pos, i) > psum_before_bad_v {
                    bad_positions.push(bad_pos + 1);
                }
                current_psum =
                    psum_before_bad_v +
                    self.range_sum_ignoring_index(&psum, bad_pos, bad_pos, i) -
                    self.a[i];
            }
            if self.k == 0 {
                if bad_positions.len() == 0 {
                    ans += (last_starting_pos as i64) + 1;
                }
            } else if bad_positions.len() > (self.k as usize) {
                ans += (self.n - bad_positions[bad_positions.len() - (self.k as usize)]) as i64;
            } else if bad_positions.len() < (self.k as usize) {
                ans += self.n as i64;
            } else {
                let temp = min(self.n, last_starting_pos + 1 + self.n - bad_positions[0]);
                ans += temp as i64;
            }
            print!("{} ", ans);
        }
        println!("");
    }
}

fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let mut t: usize = sc.next();
    while t > 0 {
        t -= 1;
        let solver = Solution::new(&mut sc);
        solver.solve();
    }
}
