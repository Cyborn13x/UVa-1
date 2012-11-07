package simplifyingfractions;

import java.io.*;
import java.util.*;
import java.math.*;

public class SimplifyingFractions {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BigInteger a,b,gcd;
        String tmp;
        int n;
        n = scan.nextInt();
        for(int i=0;i<n;i++){
            a = scan.nextBigInteger();
            tmp = scan.next();
            b = scan.nextBigInteger();
            gcd = a.gcd(b);
            System.out.println(a.divide(gcd)+" / "+b.divide(gcd));
        }
        
    }
}
