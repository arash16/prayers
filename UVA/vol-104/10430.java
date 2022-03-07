/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10430
  Name: Dear GOD
  Problem: https://onlinejudge.org/external/104/10430.pdf
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
        PrintWriter pw = new PrintWriter(System.out);

        pw.println("Dear GOD, Pardon Me");

        boolean frst = true;
        while (in.hasNextInt()) {
            if (frst) frst = false;
            else pw.println();

            int t = in.nextInt(),
                n = in.nextInt();

            if (t == 1)
                pw.printf("X = %d\nK = 1\n", n, 1);

            else {
                BigInteger bt = BigInteger.valueOf(t),
                            k = bt.pow(n),
                            x = k.subtract(BigInteger.ONE).divide(bt.subtract(BigInteger.ONE));
                pw.printf("X = %s\nK = %s\n", x.toString(), k.toString());
            }
        }
        pw.flush();
    }
}
