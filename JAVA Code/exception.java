import java.util.Scanner;  
  
public class ExceptionHandling {  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        try {  
            int a, b;  
            System.out.println("Enter the value of A: ");  
            a = sc.nextInt();  
            System.out.println("Enter the value of B: ");  
            b = sc.nextInt();  
            int result = divide(a, b);  
            System.out.println("Result: " + result);  
        } catch (ArithmeticException e) {  
            System.out.println("Cannot divide by zero: " + e.getMessage());  
        } finally {  
            System.out.println("This block will always be executed");  
        }  
    }  
  
    public static int divide(int a, int b) throws ArithmeticException {  
        if (b == 0) {  
            throw new ArithmeticException("Cannot divide by zero");  
        }  
        return a / b;  
    }  
}
