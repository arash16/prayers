import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int cse = 1;
        while (in.hasNextInt()) {
        	int n = in.nextInt(),
        		f = in.nextInt();

        	BigInteger p = BigInteger.ZERO;
        	if (n==0 && f==0) break;
        	for (int i=0; i<n; i++)
        		p = p.add(in.nextBigInteger());

        	pw.printf("Bill #%d costs %s: each friend should pay %s\n\n", cse++, 
        			p.toString(), p.divide(BigInteger.valueOf(f)).toString());
        }
        pw.flush();
    }
}
