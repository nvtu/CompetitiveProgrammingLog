#![allow(dead_code)]
use std::io::{ self };

struct Solution {
    n: i32,
    m: i32,
    h: i32,
    a: Vec<i32>,
    b: Vec<i32>,
    c: Vec<i32>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer: String = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let (n, m, h): (i32, i32, i32) = {
            let mut iter = buffer.trim().split_whitespace();
            (
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
                iter.next().unwrap().parse().unwrap(),
            )
        };
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let a: Vec<i32> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();
        let mut b: Vec<i32> = Vec::<i32>::with_capacity(m as usize);
        let mut c: Vec<i32> = Vec::<i32>::with_capacity(m as usize);
        for _ in 0..m as usize {
            buffer.clear();
            stdin.read_line(&mut buffer).unwrap();
            let (_b, _c): (i32, i32) = {
                let mut iter = buffer.trim().split_whitespace();
                (iter.next().unwrap().parse().unwrap(), iter.next().unwrap().parse().unwrap())
            };
            b.push(_b);
            c.push(_c);
        }
        Solution { n, m, h, a, b, c }
    }

    pub fn solve(self) {
        let mut mem: Vec<i32> = self.a.clone();
        let mut last_reset: Vec<i32> = vec![0; self.n as usize];
        let mut reset: i32 = 0;
        for i in 0..self.m as usize {
            let j: usize = (self.b[i] - 1) as usize;
            if last_reset[j] < reset {
                last_reset[j] = reset;
                mem[j] = self.a[j];
            }
            mem[j] += self.c[i];
            if mem[j] > self.h {
                reset += 1;
            }
        }
        for i in 0..self.n as usize {
            if last_reset[i] < reset {
                mem[i] = self.a[i];
            }
            print!("{} ", mem[i]);
        }
        print!("\n");
    }
}

fn main() {
    let mut buffer: String = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    let mut t: i32 = buffer.trim().parse().unwrap();
    buffer.clear();
    while t > 0 {
        t -= 1;
        let solution: Solution = Solution::new();
        solution.solve();
    }
}
