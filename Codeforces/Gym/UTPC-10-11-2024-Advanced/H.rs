use std::cmp::max;
use std::io::{self};

#[allow(dead_code)]
struct Solution {
    n: i32,
    m: i32,
    c: Vec<i64>,
    r: Vec<i64>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, m): (i32, i32) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let c: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let r: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution { n, m, c, r }
    }

    pub fn sum(&self, gain: &mut Vec<i64>, l: usize, r: usize) -> i64 {
        let mut total: i64 = 0;
        for i in l..=r {
            total += gain[i];
        }
        return total;
    }

    pub fn solve(&self) {
        let total_cost: i64 = self.c.iter().sum();
        let mut gain: Vec<i64> = vec![1; (self.n + 1) as usize];
        let mut ans: i64 = self.n as i64;
        let mut j: usize = 0;
        let mut eggs: i64 = 0;
        for d in 1..(self.n + 1) as usize {
            eggs += gain[d];
            let mut k: usize = 0;
            while k < self.m as usize {
                let index: usize = (j + k) % self.m as usize;
                if eggs >= self.c[index] {
                    eggs -= self.c[index];
                    for t in ((d + self.r[index] as usize)..=self.n as usize)
                        .step_by(self.r[index] as usize)
                    {
                        gain[t] += 1;
                    }
                    ans = max(ans, eggs + self.sum(&mut gain, d + 1, self.n as usize));
                    k += 1;
                } else {
                    break;
                }
            }
            j += k;
            let num_chickens: i64 = eggs / total_cost;
            for index in 0..self.m as usize {
                for t in
                    ((d + self.r[index] as usize)..=self.n as usize).step_by(self.r[index] as usize)
                {
                    gain[t] += num_chickens;
                }
            }
            eggs %= total_cost;
            ans = max(ans, eggs + self.sum(&mut gain, d + 1, self.n as usize));
            k = 0;
            while k < self.m as usize {
                let index: usize = (j + k) % self.m as usize;
                if eggs >= self.c[index] {
                    eggs -= self.c[index];
                    for t in ((d + self.r[index] as usize)..=self.n as usize)
                        .step_by(self.r[index] as usize)
                    {
                        gain[t] += 1;
                    }
                    ans = max(ans, eggs + self.sum(&mut gain, d + 1, self.n as usize));
                    k += 1;
                } else {
                    break;
                }
            }
            j += k;
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
