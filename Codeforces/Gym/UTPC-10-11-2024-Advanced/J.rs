use std::io::{self};

struct Solution {
    n: i64,
    d: i64,
    c: Vec<(i64, i64)>,
    s: Vec<i64>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer);
        let (n, d): (i64, i64) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        let mut c: Vec<(i64, i64)> = Vec::new();
        for i in 0..n as usize {
            buffer.clear();
            stdin.read_line(&mut buffer);
            let (x, y): (i64, i64) = {
                let mut iter = buffer.trim().split_whitespace();
                (
                    iter.next().unwrap().parse().unwrap(),
                    iter.next().unwrap().parse().unwrap(),
                )
            };
            c.push((x, y));
        }
        buffer.clear();
        stdin.read_line(&mut buffer);
        let s: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution { n, d, c, s }
    }

    pub fn solve(&self) {}
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
