package whosaidcrisis;

import java.io.*;
import java.util.*;
import java.math.*;

public class WhoSaidCrisis {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int cases = scan.nextInt();
        int i;
        for(i=0;i<cases;i++){
            BigInteger first = scan.nextBigInteger();
            BigInteger second = scan.nextBigInteger();
            System.out.println(first.subtract(second));
        }
    }
}
