package reallystrange;

import java.util.Scanner;
import java.math.BigInteger;

public class REALLYSTRANGE {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger n,ans;
        while(scan.hasNext()){
            n=scan.nextBigInteger();
            if(n.equals(BigInteger.valueOf(0))) ans=BigInteger.valueOf(1);
            else ans=n.multiply(n).add(n.negate()).add(BigInteger.valueOf(2));
            System.out.println(ans);
        }
    }
}
