use std::cmp::{max, min};
use std::io::{self};

struct Solution {
    n: i64,
    w: i64,
    b: i64,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, w, b): (i64, i64, i64) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        buffer.clear();
        Solution { n, w, b }
    }

    fn gcd(&self, a: i64, b: i64) -> i64 {
        if b == 0 {
            return a;
        }
        self.gcd(b, a % b)
    }

    fn extended_euclid(&self, a: i64, b: i64) -> (i64, i64) {
        if b == 0 {
            return (1, 0);
        }
        let (x, y): (i64, i64) = self.extended_euclid(b, a % b);
        (y, x - (a / b) * y)
    }

    fn ceil(&self, nomi: i64, deno: i64) -> i64 {
        if nomi < 0 {
            return nomi / deno;
        }
        (nomi + deno - 1) / deno
    }

    fn floor(&self, nomi: i64, deno: i64) -> i64 {
        if nomi < 0 {
            return (nomi - deno + 1) / deno;
        }
        nomi / deno
    }

    pub fn solve(&self) {
        let mut ans: i64 = 0;
        let gcd: i64 = self.gcd(self.w, self.b);
        if self.b == 0 && self.w == 0 {
            if self.n == 0 {
                ans = 1;
            }
        } else if self.b > 0 && self.w > 0 {
            if self.n % gcd == 0 {
                let (mut cntw, mut cntb): (i64, i64) = self.extended_euclid(self.w, self.b);
                cntw *= self.n / gcd;
                cntb *= self.n / gcd;
                let lower_bound = max(
                    self.ceil(-cntw, self.b / gcd),
                    self.ceil(cntb * self.b - self.n, self.w / gcd * self.b),
                );
                let upper_bound = min(
                    self.floor(self.n - cntw * self.w, self.b / gcd * self.w),
                    self.floor(cntb, self.w / gcd),
                );
                ans = upper_bound - lower_bound + 1;
            }
        } else if self.b > 0 {
            ans = if self.n % self.b == 0 { 1 } else { 0 };
        } else if self.w > 0 {
            ans = if self.n % self.w == 0 { 1 } else { 0 };
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
