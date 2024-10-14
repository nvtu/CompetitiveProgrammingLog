use std::cmp::Reverse;
use std::collections::BinaryHeap;
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
        let mut first_line_split = buffer.trim().split_whitespace();
        let (n, k): (i32, i32) = (
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
        return Solution { n, k, a };
    }

    pub fn solve(&self) {
        let mut ans: i32 = -1;
        let mut pq: BinaryHeap<Reverse<(i32, usize, usize, i32)>> = BinaryHeap::new();
        let mut d: Vec<Vec<i32>> = vec![vec![i32::MAX; self.n as usize]; self.n as usize];
        d[(self.k - 1) as usize][(self.k - 1) as usize] = 0;
        pq.push(Reverse((
            0,
            (self.k - 1) as usize,
            (self.k - 1) as usize,
            1,
        )));
        while pq.len() > 0 {
            let Reverse((dist, i, j, dir)) = pq.pop().unwrap();
            // Current direction is turning left
            if dir < 0 {
                // If continue turning left
                if i > 0 && d[i - 1][j] > dist + 1 && self.a[i - 1] > dist + 1 {
                    d[i - 1][j] = dist + 1;
                    pq.push(Reverse((dist + 1, i - 1, j, dir)));
                }
                // If turning right
                if j + 1 < self.n as usize
                    && d[i][j + 1] > dist + (j + 1 - i) as i32
                    && self.a[j + 1] > dist + (j + 1 - i) as i32
                {
                    d[i][j + 1] = dist + (j + 1 - i) as i32;
                    pq.push(Reverse((dist + (j + 1 - i) as i32, i, j + 1, -dir)));
                }
            } else {
                // If continue turning right
                if j + 1 < self.n as usize && d[i][j + 1] > dist + 1 && self.a[j + 1] > dist + 1 {
                    d[i][j + 1] = dist + 1;
                    pq.push(Reverse((dist + 1, i, j + 1, dir)));
                }
                // If turning left
                if i > 0
                    && d[i - 1][j] > dist + (j - i + 1) as i32
                    && self.a[i - 1] > dist + (j - i + 1) as i32
                {
                    d[i - 1][j] = dist + (j - i + 1) as i32;
                    pq.push(Reverse((dist + (j - i + 1) as i32, i - 1, j, -dir)));
                }
            }
        }
        if d[0][(self.n - 1) as usize] != i32::MAX {
            ans = d[0][(self.n - 1) as usize];
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution: Solution = Solution::new();
    solution.solve();
}
