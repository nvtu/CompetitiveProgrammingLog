use std::io::{self, BufRead};

struct SegmentTree {
    tree: Vec<Vec<i64>>,
}

impl SegmentTree {
    pub fn new(n: usize) -> SegmentTree {
        return SegmentTree {
            tree: vec![vec![0; 13]; n << 2],
        };
    }

    fn multiply(&self, a: Vec<i64>, b: Vec<i64>) -> Vec<i64> {
        const MOD: i64 = 1_000_000_007;
        let mut res: Vec<i64> = vec![0; 13];
        for i in 0..13 as usize {
            for j in 0..13 as usize {
                let k = (i * j) % 13;
                res[k] = (res[k] + (a[i] * b[j]) % MOD) % MOD;
            }
        }
        return res;
    }

    pub fn update(&mut self, start: i64, end: i64, val: i64, L: i64, R: i64, index: usize) {
        if start >= R || end <= L {
            return;
        }
        if L + 1 == R {
            let mut temp: Vec<i64> = vec![0; 13];
            temp[1] += 1;
            temp[val as usize] += 1;
            self.tree[index] = temp;
            return;
        }
        let mid = (L + R) >> 1;
        let left_node_index = index << 1;
        let right_node_index = (index << 1) + 1;
        self.update(start, end, val, L, mid, left_node_index);
        self.update(start, end, val, mid, R, right_node_index);
        self.tree[index as usize] = self.multiply(
            self.tree[left_node_index].clone(),
            self.tree[right_node_index].clone(),
        );
    }

    pub fn query(&self, start: i64, end: i64, L: i64, R: i64, index: usize) -> Vec<i64> {
        if start >= R || end <= L {
            let mut res: Vec<i64> = vec![0; 13];
            res[1] += 1;
            return res;
        }
        if start <= L && end >= R {
            return self.tree[index].clone();
        }
        let mid = (L + R) >> 1;
        let left_node_index = index << 1;
        let right_node_index = (index << 1) + 1;
        let left_query = self.query(start, end, L, mid, left_node_index);
        let right_query = self.query(start, end, mid, R, right_node_index);
        let res: Vec<i64> = self.multiply(left_query.clone(), right_query.clone());
        return res;
    }
}

#[allow(dead_code)]
struct Solution {
    n: i64,
    q: i64,
    d: Vec<i64>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, q): (i64, i64) = {
            let mut first_line_split = buffer.trim().split_whitespace();
            (
                first_line_split.next().unwrap().parse().unwrap(),
                first_line_split.next().unwrap().parse().unwrap(),
            )
        };
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let d: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        buffer.clear();
        return Solution { n, q, d };
    }

    pub fn solve(&mut self) {
        // Build Segment tree
        let mut segment_tree: SegmentTree = SegmentTree::new(self.n as usize);
        for i in 0..self.n {
            segment_tree.update(i, i + 1, self.d[i as usize] % 13, 0, self.n, 1);
        }

        // Process queries
        let stdin = io::stdin();
        let mut lines = stdin.lock().lines();
        for _i in 0..self.q as usize {
            let query_line = lines.next().unwrap().unwrap();
            let (t, u, v): (i64, i64, i64) = {
                let mut query_line_split = query_line.trim().split_whitespace();
                (
                    query_line_split.next().unwrap().parse().unwrap(),
                    query_line_split.next().unwrap().parse().unwrap(),
                    query_line_split.next().unwrap().parse().unwrap(),
                )
            };
            if t == 1 {
                self.d[(u - 1) as usize] = v;
                segment_tree.update(u - 1, u, v % 13, 0, self.n, 1);
            } else {
                let ans = segment_tree.query(u - 1, v, 0, self.n, 1)[5];
                println!("{}", ans);
            }
        }
    }
}

fn main() {
    let mut solution = Solution::new();
    solution.solve();
}
