import java.util.*;  
  
public class DoublyLinkedList {  
    private List<Integer> list = new LinkedList<>();  

    public void insert(int data, int position) {  
        if (position < 0 || position > list.size()) {  
            System.out.println("Invalid position.");  
            return;        }  
        list.add(position, data);  
        System.out.println("Inserted " + data + " at position " + position + ".");  
    }  
   
    public void delete(int position) {  
        if (position < 0 || position >= list.size()) {  
            System.out.println("Invalid position.");  
            return;        }  
        int data = list.get(position);  
        list.remove(position);  
        System.out.println("Deleted " + data + " at position " + position + ".");  
    }  
   
    public void display() {  
        System.out.println("List: " + list);  
    }  
  
    public static void main(String[] args) {  
        Scanner scanner = new Scanner(System.in);  
        DoublyLinkedList dll = new DoublyLinkedList();  
  
        while (true) {  
            System.out.println("1. Insert\n2. Delete\n3. Display\n4. Exit");  
            System.out.print("Enter your choice: ");  
            int choice = scanner.nextInt();  
  
            switch (choice) {  
                case 1:  
                    System.out.print("Enter the value to insert: ");  
                    int value = scanner.nextInt();  
                    System.out.print("Enter the position to insert at: ");  
                    int position = scanner.nextInt();  
                    dll.insert(value, position);  
                    break;                case 2:  
                    System.out.print("Enter the position to delete from: ");  
                    position = scanner.nextInt();  
                    dll.delete(position);  
                    break;                case 3:  
                    dll.display();  
                    break;                case 4:  
                    System.out.println("Exiting the program...");  
                    scanner.close();  
                    return;                default:  
                    System.out.println("Invalid choice.");  
            }  
        }  
    }  
}
