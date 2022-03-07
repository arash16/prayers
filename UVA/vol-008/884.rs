/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 884
  Name: Factorial Factors
  Problem: https://onlinejudge.org/external/8/884.pdf
  Language: Rust

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

use std::io::BufRead;

fn divcount(n: i32, p: i32) -> i32 {
    let mut cnt = 0;
    let mut x = n;
    while x % p == 0 {
        x /= p;
        cnt += 1;
    }
    cnt
}

fn sieve(c: &mut [i32]) {
    for i in 2i32..1000001 {
        if c[i as usize]==0 {
            c[i as usize] = 1;
            let mut j = 2*i;
            while j < 1000001 {
                c[j as usize] += divcount(j, i);
                j += i;
            }
        }
    }

    for i in 1..1000001 {
        c[i] += c[i-1];
    }
}

fn main() {
    let mut c = [0i32; 1000001];
    sieve(&mut c);

    let cin = std::io::stdin();
    for line in cin.lock().lines() {
        let ind: i32 = line.unwrap().parse().unwrap();
        println!("{}", c[ind as usize]);
    }
}
