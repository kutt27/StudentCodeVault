import java.util.StringTokenizer;  
import java.util.Scanner;  
  
public class StringTokenizer1 {  
    public static void main(String[] args) {  
        String s;  
        int sum = 0, temp = 0;  
        System.out.println("Enter line of Integer: ");  
        Scanner sc = new Scanner(System.in);  
        s = sc.nextLine();  
        StringTokenizer tokenizer = new StringTokenizer(s);  
        System.out.println("Digits in the line are: ");  
        while(tokenizer.hasMoreTokens()){  
            temp = Integer.parseInt(tokenizer.nextToken());  
            System.out.println(temp + "\t");  
            sum = sum + temp;  
        }  
        System.out.println("\rSum of digits: "+ sum);  
    }  
}
