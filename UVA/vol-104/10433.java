/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10433
  Name: Automorphic Numbers
  Problem: https://onlinejudge.org/external/104/10433.pdf
  Language: Java

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        while (in.hasNextLine()) {
            String ln = in.nextLine(); ln = ln.trim();
            if (ln.length() == 0) continue;

            BigInteger num = new BigInteger(ln);
            String sq = num.pow(2).toString();

            if (sq.length()>=ln.length() && sq.substring(sq.length()-ln.length()).compareTo(ln)==0)
                pw.printf("Automorphic number of %d-digit.\n", ln.length());
            else
                pw.println("Not an Automorphic number.");
        }
        pw.flush();
    }
}
