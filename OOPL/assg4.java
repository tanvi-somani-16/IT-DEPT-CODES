import java.util.Scanner;

abstract class shape{
    double dim1;
    double dim2;
    shape(){
        dim1=0;
        dim2=0;
    }
    public void input(){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter dimension 1");
        dim1=s.nextDouble();
        System.out.println("Enter dimension 2");
        dim2=s.nextDouble();
    }
    abstract public void compute_area();
}

class Rectangle extends shape{
    double area;
    Rectangle(){
        area=0;
    }
    public void compute_area(){
        System.out.println("Enter length and breadth :");
        input();
        area=dim1*dim2;
        System.out.println("Area of rectangle :"+area);
    }
}

class Triangle extends shape{
    double area;
    Triangle(){
        area=0;
    }
    public void compute_area(){
        System.out.println("Enter base and height :");
        input();
        area=0.5*dim1*dim2;
        System.out.println("Area of triangle :"+area);
    }
}

public class Main{
    public static void main(String[] args){
        Rectangle r=new Rectangle();
        Triangle t=new Triangle();
        int flag=1;
        do{
            Scanner s=new Scanner(System.in);
            System.out.println("Menu:");
            System.out.println("Enter 1 for Rectangle");
            System.out.println("Enter 2 for Triangle ");
            System.out.println("Enter 3 for exit ");

            System.out.println("Enter your choice");
            int ch=s.nextInt();

            switch(ch){
                case 1:
                    r.compute_area();
                    System.out.println("---------------------------------------------");
                    break;
                case 2:
                    t.compute_area();
                    System.out.println("----------------------------------------------");
                    break;
                case 3:
                    System.out.println("Program Terminated");
                    flag=0;
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }while(flag!=0);
    }
}

