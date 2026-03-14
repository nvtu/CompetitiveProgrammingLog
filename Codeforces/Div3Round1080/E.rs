use std::io::{self, BufRead};
use std::str::FromStr;

struct Scanner<R> {
    reader: R,
    buffer: Vec<u8>,
    pos: usize,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader: reader,
            buffer: Vec::new(),
            pos: 0,
        }
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
                return std::str::from_utf8(&self.buffer[start..self.pos])
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

fn dfs(u: usize, l: &[usize], r: &[usize], f: &mut [i64]) {
    let MOD: i64 = 1000000007;
    if l[u] > 0 {
        dfs(l[u], l, r, f);
        f[u] = (f[l[u]] + f[u] + 2) % MOD;
    }
    if r[u] > 0 {
        dfs(r[u], l, r, f);
        f[u] = (f[r[u]] + f[u] + 2) % MOD;
    }
}

fn dfs2(u: usize, l: &[usize], r: &[usize], f: &[i64], ans: &mut [i64]) {
    let MOD: i64 = 1000000007;
    ans[u] = (ans[u] + f[u] + 1) % MOD;
    if l[u] > 0 {
        ans[l[u]] = (ans[l[u]] + ans[u]) % MOD;
        dfs2(l[u], l, r, f, ans);
    }
    if r[u] > 0 {
        ans[r[u]] = (ans[r[u]] + ans[u]) % MOD;
        dfs2(r[u], l, r, f, ans);
    }
}

fn solve<R: BufRead>(sc: &mut Scanner<R>) {
    let n: usize = sc.next();
    let mut l: Vec<usize> = vec![0; n + 1];
    let mut r: Vec<usize> = vec![0; n + 1];
    let mut f: Vec<i64> = vec![0; n + 1];
    let mut ans: Vec<i64> = vec![0; n + 1];
    for i in 1..n + 1 {
        l[i] = sc.next();
        r[i] = sc.next();
    }
    l[0] = 1;
    dfs(0, &l, &r, &mut f);
    dfs2(1, &l, &r, &f, &mut ans);
    for i in 1..n + 1 {
        print!("{} ", ans[i]);
    }
    println!("");
}

fn main() {
    let stdin = io::stdin();
    let mut sc = Scanner::new(stdin.lock());
    let mut t: usize = sc.next();
    while t > 0 {
        t -= 1;
        solve(&mut sc);
    }
}
