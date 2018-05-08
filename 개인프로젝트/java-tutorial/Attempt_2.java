import java.io.IOException;
import java.io.*;
import java.util.Scanner;

public class Attempt_2
{
    public static int factorial(int i)
    {
        int fac = 1;
        
        for (int j = 1; j <= i; j++)
        {
            fac *= j;
        }
        return fac;
    }

    public static void main(String[] args) throws IOException
    {
        Scanner sc = new Scanner(System.in);

        int n = 1,
            s = 0,
            fa = 1;

        System.out.printf("정수 1개를 입력해주세요.");
        n = sc.nextInt();

        for(int i = 1; i<= n; i++)
        {
            s += factorial(i);
        }
        System.out.println("\ns = "+s);
    }
}