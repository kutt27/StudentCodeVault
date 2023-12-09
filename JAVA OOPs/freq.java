import java.util.Scanner;  
  
public class Freq {  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        System.out.print("Enter a string: ");  
        java.lang.String str = sc.nextLine();  
        System.out.print("Enter the character to find frequency: ");  
        char c = sc.next().charAt(0);  
        int count = 0;  
        for (int i = 0; i < str.length(); i++) {  
            if (str.charAt(i) == c) {  
                count++;  
            }  
        }  
  
        System.out.println("Frequency of '" + c + "' in the string: " + count);  
    }  
}
