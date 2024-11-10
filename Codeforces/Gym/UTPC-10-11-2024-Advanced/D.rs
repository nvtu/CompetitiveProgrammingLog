use std::io::{self};

#[allow(dead_code)]
struct Solution {
    s: Vec<char>,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let s: Vec<char> = buffer.trim().chars().collect();
        Solution { s }
    }

    pub fn solve(&self) {
        let mut count: Vec<i32> = vec![0; 26];
        for c in &self.s {
            let index: usize = (*c as u8 - b'a') as usize;
            count[index] += 1;
        }
        let mut ans: String = String::new();
        let mut odd: i32 = -1;
        for i in 0..26 {
            for _ in 0..count[i] / 2 {
                let c: char = (b'a' + i as u8) as char;
                ans.push(c);
            }
            if (count[i] & 1) > 0 {
                odd = i as i32;
            }
        }
        if odd != -1 {
            let c: char = (b'a' + odd as u8) as char;
            ans.push(c);
        }
        for i in 0..26 {
            for _ in 0..count[25 - i] / 2 {
                let c: char = (b'a' + (25 - i) as u8) as char;
                ans.push(c);
            }
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
