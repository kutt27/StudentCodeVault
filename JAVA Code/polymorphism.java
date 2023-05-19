abstract class Shape {  
    public abstract void numberOfSides();  
}  
  
class Rectangle extends Shape {  
    public void numberOfSides() {  
        System.out.println("Rectangle has 4 sides.");  
    }  
}  
  
class Triangle extends Shape {  
    public void numberOfSides() {  
        System.out.println("Triangle has 3 sides.");  
    }  
}  
  
class Hexagon extends Shape {  
    public void numberOfSides() {  
        System.out.println("Hexagon has 6 sides.");  
    }  
}  
  
public class Sides {  
    public static void main(String[] args) {  
        Shape shape1 = new Rectangle();  
        shape1.numberOfSides();  
  
        Shape shape2 = new Triangle();  
        shape2.numberOfSides();  
  
        Shape shape3 = new Hexagon();  
        shape3.numberOfSides();  
    }  
}
