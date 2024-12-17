use std::io::{self};

struct Solution {
    n: i32,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let n: i32 = buffer.trim().parse().unwrap();
        buffer.clear();
        Solution { n }
    }

    pub fn solve(&self) {
        if self.n % 4 > 1 {
            println!("{}", -1);
        } else {
            let white_keyboard: i32 = self.n / 4;
            if white_keyboard > 0 {
                let r = white_keyboard % 7;
                let mut black_keyboard = white_keyboard / 7 * 5;
                if self.n % 4 == 1 {
                    if r == 0 || r == 4 {
                        println!("{}", -1);
                        return;
                    }
                    if 0 < r && r < 4 {
                        black_keyboard += r;
                    } else {
                        black_keyboard += r - 1;
                    }
                } else {
                    if 0 < r && r < 5 {
                        black_keyboard += r - 1;
                    } else if r > 4 {
                        black_keyboard += r - 2;
                    }
                }
                println!("{} {}", white_keyboard, black_keyboard);
            } else {
                println!("{}", -1);
            }
        }
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
