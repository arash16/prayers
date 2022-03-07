/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11448
  Name: Who said crisis?
  Problem: https://onlinejudge.org/external/114/11448.pdf
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
        int T = in.nextInt();
        while (T-- != 0)
            pw.println(in.nextBigInteger().subtract(in.nextBigInteger()));
        pw.flush();
    }
}
