#![allow(dead_code)]
use std::io::{ self };
use std::cmp::max;

fn read_buffer() -> String {
    let mut buffer: String = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    return buffer;
}

fn argsort<T: Ord + Copy>(arr: &[T]) -> Vec<usize> {
    let mut idx: Vec<usize> = (0..arr.len()).collect();
    idx.sort_by_key(|&i| arr[i]);
    return idx;
}

fn upper_bound<T: Ord>(arr: &[T], val: T, l: usize, r: usize) -> usize {
    let sub = &arr[l..r];
    let off = sub.partition_point(|x| *x <= val);
    l + off
}

fn lower_bound<T: Ord>(arr: &[T], val: T, l: usize, r: usize) -> usize {
    let sub = &arr[l..r];
    let off = sub.partition_point(|x| *x < val);
    l + off
}

struct Solution {
    n: i32,
    m: i32,
    k: i32,
    a: Vec<i32>,
    b: Vec<i32>,
    ins: String,
}

impl Solution {
    pub fn new() -> Solution {
        let (n, m, k): (i32, i32, i32) = {
            let buffer = read_buffer();
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        let mut a: Vec<i32> = read_buffer()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let mut b: Vec<i32> = read_buffer()
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        a.sort();
        b.sort();
        let ins: String = read_buffer().trim().to_string();
        Solution { n, m, k, a, b, ins }
    }

    pub fn solve(self) {
        let mut left: Vec<i32> = vec![0; self.n as usize];
        let mut right: Vec<i32> = left.clone();
        for i in 0..self.n as usize {
            left[i] = lower_bound(&self.b, self.a[i], 0, self.m as usize) as i32;
            right[i] = upper_bound(&self.b, self.a[i], 0, self.m as usize) as i32;
            left[i] = match left[i] {
                0 => (1e9 as i32) + 7,
                _ => self.a[i] - self.b[(left[i] - 1) as usize],
            };
            right[i] = match right[i] {
                val if val == self.m => (1e9 as i32) + 7,
                _ => self.b[right[i] as usize] - self.a[i],
            };
        }
        let left_index: Vec<usize> = argsort(&left);
        let right_index: Vec<usize> = argsort(&right);
        left = left_index
            .iter()
            .map(|&i| left[i])
            .collect();
        right = right_index
            .iter()
            .map(|&i| right[i])
            .collect();

        let mut dead_count: i32 = 0;
        let mut flag: Vec<bool> = vec![false; self.n as usize];
        let mut left_counter: i32 = 0;
        let mut right_counter: i32 = 0;
        let mut l: usize = 0;
        let mut r: usize = 0;
        for c in self.ins.chars() {
            if c == 'L' {
                left_counter += 1;
                right_counter -= 1;
                let old_l: usize = l;
                l = upper_bound(&left, max(0, left_counter), l, self.n as usize);
                for i in old_l..l {
                    let j: usize = left_index[i];
                    if flag[j] == false {
                        flag[j] = true;
                        dead_count += 1;
                    }
                }
            } else {
                left_counter -= 1;
                right_counter += 1;
                let old_r: usize = r;
                r = upper_bound(&right, max(0, right_counter), r, self.n as usize);
                for i in old_r..r {
                    let j: usize = right_index[i];
                    if flag[j] == false {
                        flag[j] = true;
                        dead_count += 1;
                    }
                }
            }
            print!("{} ", max(0, self.n - dead_count));
        }
        print!("\n");
    }
}

fn main() {
    let mut t: i32 = read_buffer().trim().parse().unwrap();
    while t > 0 {
        t -= 1;
        let sol: Solution = Solution::new();
        sol.solve();
    }
}
