use std::cmp::min;
use std::io::{self, BufRead};

#[allow(dead_code)]
struct Solution {
    n: i32,
    d: i32,
    x: i32,
    k: Vec<i32>,
    c: Vec<i32>,
}

impl Solution {
    pub fn new() -> Solution {
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        let first_line = lines.next().unwrap().unwrap();
        let mut first_line_split = first_line.trim().split_whitespace();
        let (n, d, x): (i32, i32, i32) = (
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
        );
        let k: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let c: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution { n, d, x, k, c }
    }

    pub fn solve(&self) {
        let mut candies: Vec<(i32, i32)> = Vec::with_capacity(self.n as usize);
        for i in 0..self.n as usize {
            candies.push((self.c[i], self.k[i]));
        }
        candies.sort_by(|a, b| b.0.cmp(&a.0).then_with(|| a.1.cmp(&b.1)));
        let mut ans: i64 = 0;
        let mut total: i64 = self.d as i64 * self.x as i64;
        for i in 0..self.n as usize {
            let k: i32 = min(candies[i].1, self.d);
            let required: i64 = min(k.into(), total);
            total -= required;
            ans += required as i64 * candies[i].0 as i64;
        }
        println!("{ans}")
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
