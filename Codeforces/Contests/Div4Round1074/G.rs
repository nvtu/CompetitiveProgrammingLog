#![allow(dead_code)]
use std::io::{ self, BufRead };
use std::str::FromStr;
use std::collections::BTreeMap;

struct Scanner<R> {
    reader: R,
    buffer: Vec<u8>,
    pos: usize,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self { reader, buffer: Vec::<u8>::new(), pos: 0 }
    }

    fn next<T: FromStr>(&mut self) -> T {
        loop {
            if self.pos >= self.buffer.len() {
                self.buffer.clear();
                self.reader.read_until(b'\n', &mut self.buffer).unwrap();
                self.pos = 0;
            }
            while self.pos < self.buffer.len() && self.buffer[self.pos].is_ascii_whitespace() {
                self.pos += 1;
            }
            if self.pos < self.buffer.len() {
                let start: usize = self.pos;
                while self.pos < self.buffer.len() && !self.buffer[self.pos].is_ascii_whitespace() {
                    self.pos += 1;
                }
                return std::str
                    ::from_utf8(&self.buffer[start..self.pos])
                    .unwrap()
                    .parse::<T>()
                    .ok()
                    .unwrap();
            }
        }
    }

    fn next_values<T: FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}

struct Solution {
    n: usize,
    l: Vec<usize>,
    a: Vec<Vec<i64>>,
}

impl Solution {
    fn new<R: BufRead>(sc: &mut Scanner<R>) -> Self {
        let n: usize = sc.next();
        let mut l: Vec<usize> = Vec::<usize>::with_capacity(n);
        let mut a: Vec<Vec<i64>> = Vec::with_capacity(n);
        for i in 0..n {
            l.push(sc.next());
            a.push(sc.next_values(l[i]));
            a[i].sort();
        }
        Self { n, l, a }
    }

    fn find_mex(&self, arr: &[i64], skip_mex: i64) -> i64 {
        let n: usize = arr.len();
        let mut i: usize = 0;
        let mut j: usize = 0;
        while i < n {
            if (j as i64) != arr[i] {
                if (j as i64) != skip_mex {
                    return j as i64;
                } else {
                    j += 1;
                    continue;
                }
            }
            i += 1;
            j += 1;
        }
        if (j as i64) == skip_mex {
            j += 1;
        }
        return j as i64;
    }

    fn solve(&self) {
        let mut counts: Vec<BTreeMap<i64, i64>> = Vec::new();
        for i in 0..self.n {
            counts.push(
                self.a[i]
                    .iter()
                    .copied()
                    .fold(BTreeMap::new(), |mut acc, x| {
                        *acc.entry(x).or_insert(0) += 1;
                        acc
                    })
            );
        }
        let mex_arr: Vec<i64> = (0..self.n)
            .map(|i| self.find_mex(&counts[i].keys().copied().collect::<Vec<_>>(), -1))
            .collect();
        let next_mex_arr: Vec<i64> = (0..self.n)
            .map(|i| self.find_mex(&counts[i].keys().copied().collect::<Vec<_>>(), mex_arr[i]))
            .collect();
        let mex_sum: i64 = mex_arr.iter().sum();
        // For a mex, what is the sum of the next_mex_arr and how many mex_arr that has mex value?
        let next_mex_sum: BTreeMap<i64, (i64, i64)> = (0..self.n).fold(
            BTreeMap::new(),
            |mut acc, i| {
                let key: i64 = mex_arr[i];
                let entry: &mut (i64, i64) = acc.entry(key).or_insert((0, 0));
                entry.0 += next_mex_arr[i];
                entry.1 += 1;
                acc
            }
        );
        // println!("{}", mex_sum);
        // println!("{:?}", next_mex_sum);
        let mut ans = 0;
        for i in 0..self.n {
            for (val, count) in &counts[i] {
                let entry: (i64, i64) = *next_mex_sum.get(val).unwrap_or(&(0, 0));
                let mut temp_sum = mex_sum;
                if *val < mex_arr[i] && *count == 1 {
                    temp_sum = temp_sum + *val - mex_arr[i];
                }
                temp_sum *= (self.n - 1) as i64;
                temp_sum = temp_sum + entry.0 - *val * entry.1;
                // println!("{} {}", *val, temp_sum);
                ans += temp_sum * count;
            }
        }
        println!("{}", ans);
    }
}

fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let mut t: usize = sc.next();
    while t > 0 {
        t -= 1;
        let solver = Solution::new(&mut sc);
        solver.solve();
    }
}
