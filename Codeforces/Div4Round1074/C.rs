use std::io::{ self };
use std::cmp::{ max };

#[allow(dead_code)]
struct Solution {
    t: i32,
    ns: Vec<i32>,
    arrs: Vec<Vec<i32>>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer: String = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let t: i32 = buffer.trim().parse().unwrap();
        let mut ns: Vec<i32> = Vec::<i32>::new();
        let mut arrs: Vec<Vec<i32>> = Vec::new();
        for _ in 0..t as usize {
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            let n: i32 = buffer.trim().parse().unwrap();
            ns.push(n);
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            let arr: Vec<i32> = buffer
                .trim()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();
            arrs.push(arr);
        }
        Solution {
            t: t,
            ns: ns,
            arrs: arrs,
        }
    }

    pub fn solve(&mut self) {
        for i in 0..self.t as usize {
            self.arrs[i].sort_unstable();
            println!("{:?}", self.arrs[i]);
            self.arrs[i].dedup();
            let mut mmax: i32 = 1;
            let mut count: i32 = 1;
            for j in 1..self.arrs[i].len() as usize {
                if self.arrs[i][j] == self.arrs[i][j - 1] + 1 {
                    count += 1;
                } else {
                    count = 1;
                }
                mmax = max(mmax, count);
            }
            println!("{}", mmax);
        }
    }
}

fn main() {
    let mut solution: Solution = Solution::new();
    solution.solve();
}
