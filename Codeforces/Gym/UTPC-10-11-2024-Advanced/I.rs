use std::io::{self};

const MOD: i64 = 998244353;

struct Solution {
    p: i64,
}

impl Solution {
    pub fn new() -> Solution {
        let mut buffer = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut buffer).unwrap();
        let p: i64 = buffer.trim().parse().unwrap();
        buffer.clear();
        Solution { p }
    }

    fn compute_pow(&self, mut a: i64, mut n: i64) -> i64 {
        let mut res: i64 = 1;
        while n > 0 {
            if (n & 1) > 0 {
                res = (res * a) % MOD;
            }
            a = (a * a) % MOD;
            n >>= 1;
        }
        res
    }

    pub fn solve(&self) {
        let mut prob: i64 = 1;
        let mut ans: i64 = 0;
        for i in 1..=self.p as usize {
            let prob_go_back: i64 = (i as i64 * self.compute_pow(self.p, MOD - 2)) % MOD;
            let prob_continue: i64 = (1 - prob_go_back + MOD) % MOD;
            let exp_turn_back: i64 = ((i as i64 + 1) * self.compute_pow(2, MOD - 2)) % MOD;
            ans = (ans + ((exp_turn_back * prob) % MOD) * prob_go_back) % MOD;
            prob = (prob * prob_continue) % MOD;
        }
        println!("{}", ans);
    }
}

fn main() {
    let solution = Solution::new();
    solution.solve();
}
