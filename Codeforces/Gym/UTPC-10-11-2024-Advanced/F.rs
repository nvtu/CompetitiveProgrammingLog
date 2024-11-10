use std::io::{self};

#[allow(dead_code)]
struct Solution {
    n: i32,
    k: i32,
    a: Vec<i32>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, k): (i32, i32) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let a: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution { n, k, a }
    }

    fn check(&self, dist: i32) -> bool {
        let mut cnt: i32 = 0;
        let mut i: usize = 0;
        while i < self.n as usize {
            cnt += 1;
            let lamp_pos: i32 = self.a[i] + dist;
            let mut j = i;
            while j < self.n as usize && (self.a[j] - lamp_pos).abs() <= dist {
                j += 1;
            }
            if i != j {
                i = j - 1;
            }
            i += 1;
        }
        cnt <= self.k
    }

    pub fn solve(&self) {
        let max_dist: i32 = self.a.iter().max().unwrap() - self.a.iter().min().unwrap();
        let mut l: i32 = 0;
        let mut r: i32 = max_dist;
        let mut ans: i32 = max_dist;
        while l <= r {
            let mid: i32 = (l + r) >> 1;
            if self.check(mid) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
