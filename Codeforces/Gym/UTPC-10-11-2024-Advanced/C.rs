use std::io::{self};

#[allow(dead_code)]
struct Solution {
    k: i32,
    n: i32,
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
        Solution { n, k }
    }

    pub fn solve(&self) {
        let mut ans: Vec<i32> = Vec::with_capacity(self.n as usize);
        for i in (self.k + 1..=self.n).rev() {
            ans.push(i);
        }
        for i in 1..=self.k {
            ans.push(i);
        }
        for i in 0..self.n {
            print!("{} ", ans[i as usize]);
        }
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
