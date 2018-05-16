import java.util.*;
import java.math.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner s=new Scanner(new BufferedInputStream(System.in));
        int t;
        t=s.nextInt();
        for(int i=0;i<t;i++)
        {
            if(i!=0)System.out.println("");
            BigInteger a=new BigInteger("0"),b;
            while(true)
            {
                b=s.nextBigInteger();
                if(b.equals(new BigInteger("0")))
                {
                    System.out.println(a);
                    break;
                }
                a=a.add(b);
            }
        }
    }
}