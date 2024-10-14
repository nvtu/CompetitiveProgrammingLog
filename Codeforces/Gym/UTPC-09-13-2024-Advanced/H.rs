use std::cmp::max;
use std::io::{self, BufRead};

#[allow(dead_code)]
struct Solution {
    n: i32,
    q: i32,
    a: Vec<i32>,
}

impl Solution {
    pub fn new() -> Solution {
        let stdin = io::stdin();
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let mut first_line_split = buffer.trim().split_whitespace();
        let (n, q): (i32, i32) = (
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
        );
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let a: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        buffer.clear();
        return Solution { n, q, a };
    }

    pub fn solve(&self) {
        let mut prefix: Vec<i32> = vec![0; (self.n + 1) as usize];
        let mut suffix: Vec<i32> = vec![0; (self.n + 1) as usize];
        // let mut always_exit: Vec<i32> = vec![0; (self.n + 1) as usize];
        let mut mmin_exit: Vec<i32> = vec![i32::MAX; (self.n + 1) as usize];
        for &v in self.a.iter() {
            prefix[v as usize] += 1;
            suffix[(self.n - v) as usize] += 1;
            mmin_exit[v as usize] = max(v, self.n - v);
            // always_exit[mmin_exit[v as usize] as usize] += 1;
        }
        for i in 1..self.n as usize {
            prefix[i] += prefix[i - 1];
            suffix[i] += suffix[i - 1];
            // always_exit[i] += always_exit[i - 1];
        }
        let mmin: i32 = *mmin_exit.iter().min().unwrap();
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        for _i in 0..self.q {
            let next_query: i32 = lines.next().unwrap().unwrap().parse().unwrap();
            if next_query >= mmin {
                println!("{}", -1);
            } else {
                let m = prefix[next_query as usize] + suffix[next_query as usize];
                println!("{}", m);
            }
        }
    }
}

fn main() {
    let solution: Solution = Solution::new();
    solution.solve();
}
