import java.util.Scanner;  
  
public class MatrixMultiplication {  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
  
        System.out.print("Enter the number of rows of first matrix: ");  
        int rows1 = sc.nextInt();  
        System.out.print("Enter the number of columns of first matrix: ");  
        int columns1 = sc.nextInt();  
  
        int[][] matrix1 = new int[rows1][columns1];  
        System.out.println("Enter the elements of first matrix:");  
        for (int i = 0; i < rows1; i++) {  
            for (int j = 0; j < columns1; j++) {  
                matrix1[i][j] = sc.nextInt();  
            }  
        }  
  
        System.out.print("Enter the number of rows of second matrix: ");  
        int rows2 = sc.nextInt();  
        System.out.print("Enter the number of columns of second matrix: ");  
        int columns2 = sc.nextInt();  
  
        int[][] matrix2 = new int[rows2][columns2];  
        System.out.println("Enter the elements of second matrix:");  
        for (int i = 0; i < rows2; i++) {  
            for (int j = 0; j < columns2; j++) {  
                matrix2[i][j] = sc.nextInt();  
            }  
        }  
          
        if (columns1 != rows2) {  
            System.out.println("Matrix multiplication not possible");  
            return;        }  
  
        int[][] result = new int[rows1][columns2];  
        for (int i = 0; i < rows1; i++) {  
            for (int j = 0; j < columns2; j++) {  
                for (int k = 0; k < columns1; k++) {  
                    result[i][j] += matrix1[i][k] * matrix2[k][j];  
                }  
            }  
        }  
  
        System.out.println("Product of the matrices:");  
        for (int i = 0; i < rows1; i++) {  
            for (int j = 0; j < columns2; j++) {  
                System.out.print(result[i][j] + " ");  
            }  
            System.out.println();  
        }  
    }  
}
