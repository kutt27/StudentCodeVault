import java.util.Arrays;  
import java.util.Scanner;  
  
public class QuickSort1 {  
  
    public static void quickSort(String[] arr, int low, int high) {  
        if (low < high) {  
            int pi = partition(arr, low, high);  
            quickSort(arr, low, pi - 1);  
            quickSort(arr, pi + 1, high);  
        }  
    }  
  
    public static int partition(String[] arr, int low, int high) {  
        String pivot = arr[high];  
        int i = (low - 1);   
for (int j = low; j < high; j++) {  
            if (arr[j].compareTo(pivot) <= 0) {  
                i++;  
                String temp = arr[i];  
                arr[i] = arr[j];  
                arr[j] = temp;  
            }  
        }  
        String temp = arr[i + 1];  
        arr[i + 1] = arr[high];  
        arr[high] = temp;  
  
        return i + 1;  
    }  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        int size;  
        System.out.println("Enter the number of Strings you want to sort out: ");  
        size = sc.nextInt();  
        String[] arr = new String[size];  
        System.out.println("Enter the names: ");  
        arr[0] = sc.nextLine();  
        for (int i = 0; i < size; i++) {  
            arr[i] = sc.nextLine();  
        }  
        quickSort(arr, 0, size - 1);  
  
        System.out.println("Sorted array:");  
        System.out.println(Arrays.toString(arr));  
    }  
}
