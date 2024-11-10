use std::cmp::{max, min};
use std::io::{self};

#[allow(dead_code)]
struct Solution {
    n: i32,
    h: Vec<i64>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let n: i32 = buffer.trim().parse().unwrap();
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let h: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution { n, h }
    }

    pub fn solve(&self) {
        let mut left_max: Vec<i64> = vec![0; self.n as usize];
        let mut right_max: Vec<i64> = vec![0; self.n as usize];
        let mut max_height: i64 = 0;
        let mut total_volumes: i64 = 0;
        left_max[0] = self.h[0];
        for i in 1..self.n as usize {
            left_max[i] = max(left_max[i - 1], self.h[i]);
        }
        right_max[self.n as usize - 1] = self.h[self.n as usize - 1];
        for i in (0..self.n - 1).rev() {
            right_max[i as usize] = max(right_max[i as usize + 1], self.h[i as usize]);
        }
        for i in 1..self.n as usize - 1 {
            let surface_height: i64 = min(left_max[i - 1], right_max[i + 1]);
            let pool_height: i64 = surface_height - self.h[i];
            if pool_height > 0 {
                if surface_height > max_height {
                    max_height = surface_height;
                    total_volumes = pool_height;
                } else if surface_height == max_height {
                    total_volumes += pool_height;
                }
            }
        }
        println!("{}", total_volumes);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
