use std::cmp::min;
use std::collections::VecDeque;
use std::io::{self, BufRead};

#[allow(dead_code)]
struct Solution {
    n: i32,
    m: i32,
    s: i32,
    k: i32,
    g: i32,
    e: Vec<i32>,
    r: Vec<i32>,
    edges: Vec<Vec<i32>>,
}

impl Solution {
    pub fn new() -> Solution {
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        let first_line = lines.next().unwrap().unwrap();
        let mut first_line_split = first_line.trim().split_whitespace();
        let (n, m, s, k, g): (i32, i32, i32, i32, i32) = (
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
            first_line_split.next().unwrap().parse().unwrap(),
        );
        let mut edges: Vec<Vec<i32>> = Vec::with_capacity((n + 1) as usize);
        edges.resize((n + 1) as usize, vec![]);
        for _i in 0..m {
            let next_line = lines.next().unwrap().unwrap();
            let mut next_line_split = next_line.trim().split_whitespace();
            let (a, b): (i32, i32) = (
                next_line_split.next().unwrap().parse().unwrap(),
                next_line_split.next().unwrap().parse().unwrap(),
            );
            edges[a as usize].push(b);
            edges[b as usize].push(a);
        }
        let e: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let r: Vec<i32> = lines
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        Solution {
            n,
            m,
            s,
            k,
            g,
            e,
            r,
            edges,
        }
    }

    fn bfs(&self, queue: &mut VecDeque<i32>, visited: &mut Vec<bool>, dist: &mut Vec<i32>) {
        while !queue.is_empty() {
            let u = queue.pop_front().unwrap();
            for &v in self.edges[u as usize].iter() {
                if !visited[v as usize] {
                    visited[v as usize] = true;
                    dist[v as usize] = dist[u as usize] + 1;
                    queue.push_back(v);
                } else {
                    dist[v as usize] = min(dist[v as usize], dist[u as usize] + 1);
                }
            }
        }
    }

    pub fn solve(&self) {
        let mut dist_harry: Vec<i32> = vec![i32::MAX; (self.n + 1) as usize];
        let mut dist_ghost: Vec<i32> = vec![i32::MAX; (self.n + 1) as usize];
        let mut hq: VecDeque<i32> = VecDeque::new();
        let mut visited: Vec<bool> = vec![false; (self.n + 1) as usize];
        hq.push_back(self.s);
        visited[self.s as usize] = true;
        dist_harry[self.s as usize] = 0;
        self.bfs(&mut hq, &mut visited, &mut dist_harry);
        let mut gq: VecDeque<i32> = VecDeque::new();
        visited = vec![false; (self.n + 1) as usize];
        for i in 0..self.g {
            dist_ghost[self.r[i as usize] as usize] = 0;
            visited[self.r[i as usize] as usize] = true;
            gq.push_back(self.r[i as usize]);
        }
        self.bfs(&mut gq, &mut visited, &mut dist_ghost);
        let mut ans: i32 = 0;
        for i in 0..self.k {
            if dist_harry[self.e[i as usize] as usize] < dist_ghost[self.e[i as usize] as usize] {
                ans += 1;
            }
        }
        // println!("{:?}", dist_harry);
        // println!("{:?}", dist_ghost);
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
