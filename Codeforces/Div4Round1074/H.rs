#![allow(dead_code)]
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
            a: std::iter::once(0).chain(sc.next_values(n)).collect(),
        }
    }

    fn find_bad_position_bound(
        &self,
        psum: &[i64],
        skip_index: usize,
        l: usize,
        r: usize
    ) -> usize {
        let val: i64 = self.a[skip_index];
        let mut l: usize = l;
        let mut r: usize = r;
        let mut ans: usize = r + 1;
        while l <= r {
            let mid: usize = (l + r) >> 1;
            let is_bad: bool = if mid > skip_index {
                psum[mid] < val * 2
            } else {
                if mid - 1 == 0 { false } else { psum[mid - 1] < val }
            };
            if is_bad {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    fn find_cheating_limit_bound(
        &self,
        bad_positions: &[i64],
        add: i64,
        l: usize,
        r: usize
    ) -> usize {
        let mut l: usize = l;
        let mut r: usize = r;
        let mut ans = r + 1;
        while l <= r {
            let mid: usize = (l + r) >> 1;
            if bad_positions[mid] + add > self.k {
                l = mid + 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }

    fn solve(&self) {
        let psum: Vec<i64> = self.a
            .iter()
            .scan(0, |s, x| {
                *s += x;
                Some(*s)
            })
            .collect();
        let mut count_bad_positions: Vec<i64> = vec![0; self.n + 1];
        for i in (1..self.n + 1).rev() {
            if i > 1 && self.a[i] > psum[i - 1] {
                count_bad_positions[i] += 1;
            }
            if i + 1 <= self.n {
                count_bad_positions[i] += count_bad_positions[i + 1];
            }
        }
        println!("{:?}", psum);
        println!("{:?}", count_bad_positions);

        for i in 1..self.n + 1 {
            let mut ans: i64 = 0;
            let rhs_bad_ub: usize = self.find_bad_position_bound(&psum, i, i + 1, self.n);
            let rhs_bad_lb: usize = self.find_cheating_limit_bound(
                &count_bad_positions,
                0,
                i + 1,
                self.n
            );
            let lhs_bad_ub: usize = self.find_bad_position_bound(&psum, i, 1, i - 1);
            let add: i64 = if i > 1 && self.a[i] > psum[i - 1] { -1_i64 } else { 0_i64 };
            let lhs_bad_lb: usize = self.find_cheating_limit_bound(
                &count_bad_positions,
                add,
                1,
                i - 1
            );
            if rhs_bad_ub <= self.n && rhs_bad_lb <= rhs_bad_ub {
                ans += (rhs_bad_ub - rhs_bad_lb + 1) as i64;
            }
            if lhs_bad_ub <= i - 1 && lhs_bad_lb <= lhs_bad_ub {
                ans += (lhs_bad_ub - lhs_bad_lb + 1) as i64;
            }
            if
                (self.a[i] > psum[i - 1] && count_bad_positions[i] <= self.k) ||
                (self.a[i] <= psum[i - 1] && count_bad_positions[i] < self.k)
            {
                ans += 1;
            }
            println!("{} {} {} {} {}", rhs_bad_lb, rhs_bad_ub, lhs_bad_lb, lhs_bad_ub, add);
            println!("{} ", ans);
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
