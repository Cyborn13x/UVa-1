package unclejack;

import java.io.*;
import java.util.*;
import java.math.*;

public class UncleJack {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int b;
        BigInteger a,res;
        while(true){
            a=scan.nextBigInteger();
            b=scan.nextInt();
            if(a.equals(BigInteger.valueOf(0)) && b==0) break;
            res=a.pow(b);
            System.out.println(res);
        }
    }
}
