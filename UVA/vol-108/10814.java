/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10814
  Name: Simplifying Fractions
  Problem: https://onlinejudge.org/external/108/10814.pdf
  Language: Java

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- != 0) {
            BigInteger a = in.nextBigInteger();
            in.next();
            BigInteger b = in.nextBigInteger();

            BigInteger g = a.gcd(b);
            System.out.printf("%s / %s\n", a.divide(g).toString(), b.divide(g).toString());
        }
    }
}
