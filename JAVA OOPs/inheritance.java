import java.util.Scanner;  
  
class Employee {  
    String name;  
    int age;  
    String phoneNumber;  
    String address;  
    int salary;  
  
    public void printSalary() {  
        System.out.println("Salary: " + salary);  
    }  
}  
  
class Manager extends Employee {  
    String department;  
    Scanner sc1 = new Scanner(System.in);  
    public void method1(){  
        System.out.println("Department: ");  
        department = sc1.nextLine();  
    }  
}  
  
class Officer extends Employee {  
    String specialization;  
    Scanner sc2 = new Scanner(System.in);  
    public void method2(){  
        System.out.println("Specialization: ");  
        specialization = sc2.nextLine();  
    }  
}  
  
public class Main {  
    public static void EmployeeData(){  
        Scanner sc = new Scanner(System.in);  
        Employee employee = new Employee();  
        System.out.println("What is the Name of the Employee: ");  
        employee.name = sc.nextLine();  
        System.out.println("Age: ");  
        employee.age = Integer.parseInt(sc.nextLine());  
        System.out.println("Phone number: ");  
        employee.phoneNumber = sc.nextLine();  
        System.out.println("Address: ");  
        employee.address = sc.nextLine();  
        System.out.println("Salary: ");  
        employee.salary = sc.nextInt();  
        System.out.println(" ");  
        System.out.println(" ");  
        System.out.println("\nManager Name: " + employee.name);  
        System.out.println("Manager Age: " + employee.age);  
        System.out.println("Manager Phone Number: " + employee.phoneNumber);  
        System.out.println("Manager Address: " + employee.address);  
        employee.printSalary();  
    }  
    public static void ManagerData(){  
        Scanner sc = new Scanner(System.in);  
        Manager manager = new Manager();  
        System.out.println("What is the Name of the Manager: ");  
        manager.name = sc.nextLine();  
        System.out.println("Age: ");  
        manager.age = Integer.parseInt(sc.nextLine());  
        System.out.println("Phone number: ");  
        manager.phoneNumber = sc.nextLine();  
        System.out.println("Address: ");  
        manager.address = sc.nextLine();  
        System.out.println("Salary: ");  
        manager.salary = sc.nextInt();  
        manager.method1();  
        System.out.println(" ");  
        System.out.println(" ");  
        System.out.println("\nManager Name: " + manager.name);  
        System.out.println("Manager Age: " + manager.age);  
        System.out.println("Manager Phone Number: " + manager.phoneNumber);  
        System.out.println("Manager Address: " + manager.address);  
        manager.printSalary();  
        System.out.println("Manager Department: " + manager.department);  
    }  
    public static void OfficerData(){  
        Scanner sc = new Scanner(System.in);  
        Officer officer = new Officer();  
        System.out.println("What is the Name of the Officer: ");  
        officer.name = sc.nextLine();  
        System.out.println("Age: ");  
        officer.age = Integer.parseInt(sc.nextLine());  
        System.out.println("Phone number: ");  
        officer.phoneNumber = sc.nextLine();  
        System.out.println("Address: ");  
        officer.address = sc.nextLine();  
        System.out.println("Salary: ");  
        officer.salary = sc.nextInt();  
        officer.method2();  
        System.out.println(" ");  
        System.out.println(" ");  
        System.out.println("\nOfficer Name: " + officer.name);  
        System.out.println("Officer Age: " + officer.age);  
        System.out.println("Officer Phone Number: " + officer.phoneNumber);  
        System.out.println("Officer Address: " + officer.address);  
        officer.printSalary();  
        System.out.println("Officer Specialization: " + officer.specialization);  
    }  
    public static void main(String[] args) {  
        EmployeeData();  
        System.out.println(" ");  
        ManagerData();  
        System.out.println(" ");  
        OfficerData();  
        System.out.println(" ");   
    }  
}
