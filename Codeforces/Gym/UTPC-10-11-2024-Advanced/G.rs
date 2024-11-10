use std::cmp::Reverse;
use std::collections::BinaryHeap;
use std::io::{self};

#[allow(dead_code)]
struct Solution {
    n: i64,
    m: i64,
    a: i64,
    b: i64,
    edges: Vec<Vec<(i64, i64, i64)>>,
    start: Vec<i64>,
    end: Vec<i64>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, m, a, b): (i64, i64, i64, i64) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        let mut edges = vec![vec![]; (n + 1) as usize];
        for _ in 0..m {
            let (u, v, c, e): (i64, i64, i64, i64) = {
                buffer.clear();
                stdin.read_line(&mut buffer).unwrap();
                let mut iter = buffer.trim().split_whitespace();
                (
                    iter.next().unwrap().parse().unwrap(),
                    iter.next().unwrap().parse().unwrap(),
                    iter.next().unwrap().parse().unwrap(),
                    iter.next().unwrap().parse().unwrap(),
                )
            };
            edges[v as usize].push((u, c, e));
        }
        let start: Vec<i64> = {
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            buffer
                .trim()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect()
        };
        let end: Vec<i64> = {
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            buffer
                .trim()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect()
        };
        Solution {
            n,
            m,
            a,
            b,
            edges,
            start,
            end,
        }
    }

    fn find_min_dist_to_entrances(&self, is_chicken: bool) -> Vec<i64> {
        let mut visited: Vec<bool> = vec![false; (self.n + 1) as usize];
        let mut pq: BinaryHeap<Reverse<(i64, i64)>> = BinaryHeap::new();
        let mut dist: Vec<i64> = vec![i64::MAX; (self.n + 1) as usize];
        for i in 0..self.b as usize {
            let source: usize = self.end[i] as usize;
            dist[source] = 0;
            pq.push(Reverse((dist[source], self.end[i])));
        }
        while pq.len() > 0 {
            let Reverse((d, node)) = pq.pop().unwrap();
            if visited[node as usize] {
                continue;
            }
            visited[node as usize] = true;
            for (next, ccost, ecost) in self.edges[node as usize].iter() {
                if !visited[*next as usize] {
                    let cost: i64 = if is_chicken { *ccost } else { *ecost };
                    if d + cost < dist[*next as usize] {
                        dist[*next as usize] = d + cost;
                        pq.push(Reverse((dist[*next as usize], *next)));
                    }
                }
            }
        }
        let mut min_dist_to_entrance: Vec<i64> = Vec::new();
        for i in 0..self.a as usize {
            let node: usize = self.start[i] as usize;
            min_dist_to_entrance.push(dist[node]);
        }
        min_dist_to_entrance.sort();
        return min_dist_to_entrance;
    }

    fn count_wins(&self, target_dist: Vec<i64>, source_dist: Vec<i64>) -> i64 {
        let mut wins: i64 = 0;
        let mut r = self.a - 1;
        let mut l = self.a - 1;
        while l >= 0 {
            while r >= 0 && target_dist[l as usize] < source_dist[r as usize] {
                r -= 1;
            }
            if r + 1 < self.a && target_dist[l as usize] < source_dist[(r + 1) as usize] {
                wins += self.a - r - 1;
            }
            l -= 1;
        }
        return wins;
    }

    pub fn solve(&self) {
        let cdist: Vec<i64> = self.find_min_dist_to_entrances(true);
        let edist: Vec<i64> = self.find_min_dist_to_entrances(false);
        let chicken_wins: i64 = self.count_wins(cdist.clone(), edist.clone());
        let egg_wins: i64 = self.count_wins(edist.clone(), cdist.clone());
        if chicken_wins > egg_wins {
            println!("chicken");
        } else if chicken_wins < egg_wins {
            println!("egg");
        } else {
            println!("tie");
        }
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
