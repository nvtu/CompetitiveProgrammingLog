use std::io;

fn solve(n: i32, s: &str) {
    // Your code here
    let chars: Vec<char> = s.chars().collect();
    let mut count: Vec<i32> = vec![0; 2];
    if chars[0] == '0' {
        count[0] += 1;
    } else {
        count[1] += 1;
    }
    for i in 1..n as usize {
        if chars[i] != chars[i - 1] && chars[i] == '0' {
            count[0] += 1;
        }
        if chars[i] != chars[i - 1] && chars[i] == '1' {
            count[1] += 1;
        }
    }
    println!("{}", count.iter().min().unwrap());
}

fn main() {
    let mut buffer = String::new();
    let stdin = io::stdin();
    stdin.read_line(&mut buffer).unwrap();
    let n: i32 = buffer.trim().parse().unwrap();
    buffer.clear();
    stdin.read_line(&mut buffer).unwrap();
    let s: &str = buffer.trim();
    solve(n, s);
}
