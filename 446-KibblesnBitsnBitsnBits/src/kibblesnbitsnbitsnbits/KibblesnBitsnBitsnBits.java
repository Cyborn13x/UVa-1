package kibblesnbitsnbitsnbits;

import java.io.*;
import java.util.*;
import java.math.*;

public class KibblesnBitsnBitsnBits {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String a,b,c,tmp1,tmp2;
        BigInteger n1,n2,ans;
        int t;
        t=scan.nextInt();
        while(t>0){
            a=scan.next();
            c=scan.next();
            b=scan.next();
            n1 = new BigInteger(a,16);
            n2 = new BigInteger(b,16);
            if(c.compareTo("+")==0){
                ans=n1.add(n2);
            }
            else{
                ans=n1.subtract(n2);
            }
            a=n1.toString(2);
            b=n2.toString(2);
            a=String.format("%13s",a);
            b=String.format("%13s",b);
            a=a.replace(' ','0');
            b=b.replace(' ','0');
            System.out.printf("%s %s %s = %s%n",a,c,b,ans.toString(10));
            t=t-1;
        }
    }
}
