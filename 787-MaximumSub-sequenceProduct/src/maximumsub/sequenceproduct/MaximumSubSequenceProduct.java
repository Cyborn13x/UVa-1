/*
 * Author - Shakil Ahmed
 * Catagory - MaxSum
 */
package maximumsub.sequenceproduct;

/*problem id-787
 *
 *language-JAVA
 *
 */
import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class MaximumSubSequenceProduct {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x;
        while(sc.hasNext()){
            ArrayList<Integer> list = new ArrayList<Integer>();
            while(sc.hasNext() && (x=sc.nextInt())!=-999999) list.add(x);
            BigInteger res = BigInteger.valueOf(list.get(0));
            for(int i=0, l=list.size();i<l;i++){
                BigInteger X = BigInteger.valueOf(list.get(i));
                res = X.max(res);
                for(int j=i+1;j<l;j++){
                    X=X.multiply(BigInteger.valueOf(list.get(j)));
                    res=X.max(res);
                }
            }
            System.out.println(res);
        }
    }
}
