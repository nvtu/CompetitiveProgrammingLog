use std::io::{self, BufRead};

#[allow(dead_code)]
struct Solution {
    n: i32,
    m: i32,
    a: Vec<i32>,
    q: Vec<i32>,
}

impl Solution {
    pub fn new() -> Solution {
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        let first_line = lines.next().unwrap().unwrap();
        let mut first_line_split = first_line.trim().split_whitespace();
        let n: i32 = first_line_split.next().unwrap().parse().unwrap();
        let m: i32 = first_line_split.next().unwrap().parse().unwrap();
        let a: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let q: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        Solution { n, m, a, q }
    }

    pub fn solve(&self) {
        // Compute prefix sum
        let mut presum: Vec<i64> = vec![0; self.n as usize];
        presum[0] = self.a[0].into();
        for i in 1..self.n as usize {
            presum[i] = presum[i - 1] + self.a[i] as i64;
        }

        for i in 0..self.m as usize {
            if self.q[i] == 0 {
                println!("0");
                continue;
            }
            let mut ans = -1;
            let mut l = 0;
            let mut r = self.n - 1;
            while l <= r {
                let mid = (l + r) >> 1;
                if presum[mid as usize] >= self.q[i].into() {
                    ans = mid + 1;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            println!("{}", ans);
        }
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
