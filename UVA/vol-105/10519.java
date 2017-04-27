import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger two = BigInteger.valueOf(2);
        while (in.hasNext()) {
        	BigInteger n = in.nextBigInteger();
        	
        	if (n.signum()==0)
        		System.out.println(1);
        	else
        		System.out.println(n.multiply(n.subtract(BigInteger.ONE)).add(two));
        }
    }
}
