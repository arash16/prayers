import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        while (in.hasNextInt()) {
            int t = in.nextInt(),
                a = in.nextInt(),
                b = in.nextInt();

            pw.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);

            boolean bad = t<=1 || b<1 || a%b!=0 || (a-b)*Math.log10(t)>103;
            if (!bad) {
                if (a == 0) pw.println(0);
                else if (a < b) bad = true;
                else if (a == b) pw.println(1);
                else {
                    BigInteger num = BigInteger.valueOf(t).pow(a).subtract(BigInteger.ONE),
                                den = BigInteger.valueOf(t).pow(b).subtract(BigInteger.ONE);

                    BigInteger[] res = num.divideAndRemainder(den);
                    if (res[1].compareTo(BigInteger.ZERO) == 0) {
                        String s = res[0].toString();
                        if (s.length() <= 100)
                             pw.println(s);
                        else bad = true;
                    }
                    else bad = true;
                }
            }

            if (bad) pw.println("is not an integer with less than 100 digits.");
        }
        pw.flush();
    }
}
