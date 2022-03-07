/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11821
  Name: High-Precision Number
  Problem: https://onlinejudge.org/external/118/11821.pdf
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
        PrintWriter pw = new PrintWriter(System.out);
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        in.nextLine();
        while (T-- != 0) {
            BigDecimal sum = new BigDecimal(0);
            while (true) {
                String s = in.nextLine();
                if (s.equals("0")) break;
                sum = sum.add(new BigDecimal(s));
            }

            String r = sum.toString();
            int l = r.length();
            while (l>0 && r.charAt(l-1)=='0') --l;
            if (l>0 && r.charAt(l-1)=='.') --l;
            pw.println(r.substring(0, l));
        }

        pw.close();
    }
}
