/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10497
  Name: Sweet Child Makes Trouble
  Problem: https://onlinejudge.org/external/104/10497.pdf
  Language: Java

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        BigInteger DP[] = new BigInteger[801];
        DP[0] = DP[1] = BigInteger.ZERO;
        DP[2] = BigInteger.ONE;
        for (int i=3; i<801; i++)
            DP[i] = DP[i-1].add(DP[i-2]).multiply(BigInteger.valueOf(i-1));

        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            if (n == -1) break;
            System.out.println(DP[n]);
        }
    }
}
