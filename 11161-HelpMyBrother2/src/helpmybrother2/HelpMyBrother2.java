/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package helpmybrother2;

/**
 *
 * @author User
 */

import java.io.*;
import java.util.*;
import java.math.*;

public class HelpMyBrother2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i,n,test=0;
        BigInteger data[][] = new BigInteger[1505][2];
        BigInteger fib[] = new BigInteger[1505],b;
        fib[1]=fib[2]=BigInteger.valueOf(1);
        for(i=3;i<1505;i++){
            fib[i]=fib[i-2].add(fib[i-1]);
        }
        data[1][1]=BigInteger.valueOf(0);
        data[2][1]=BigInteger.valueOf(1);
        data[3][0]=BigInteger.valueOf(2);
        data[3][1]=BigInteger.valueOf(2);
        for(i=4;i<=1501;i++){
            data[i][0]=data[i-1][0].add(fib[i-1]);
            b=fib[i].subtract(BigInteger.valueOf(1));
            b=b.divide(BigInteger.valueOf(2));
            data[i][1]=data[i][0].add(b);
        }
        while(true){
            n=scan.nextInt();
            if(n==0) break;
            System.out.printf("Set %d:\n",++test);
            System.out.println(data[n][1]);
        }
    }
}
