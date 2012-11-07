package basicremains;

import java.io.*;
import java.util.*;
import java.math.*;

public class Basicremains {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int base;
        String a,b;
        while(true){
            base = scan.nextInt();
            if(base==0) break;
            a=scan.next();
            BigInteger n1=new BigInteger(a,base);
            b=scan.next();
            BigInteger n2=new BigInteger(b,base);
            System.out.println(n1.mod(n2).toString(base));
        }
    }
}
