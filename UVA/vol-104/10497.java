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
