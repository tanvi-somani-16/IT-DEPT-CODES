import java.util.Scanner;

class Complex{
    double real;
    double img;
    Complex(){
        real=0;
        img=0;
    }
    Complex(double r, double i) {
        real = r;
        img = i;
    }

    public Complex Addition(Complex a, Complex b){
        Complex c3=new Complex();
        c3.real=a.real+b.real;
        c3.img=a.img+b.img;
        return c3;
    }

    public Complex Subtraction(Complex c,Complex d){
        Complex c4=new Complex();
        c4.real=c.real-d.real;
        c4.img=c.img-d.img;
        return c4;
    }

    public Complex Multiplication(Complex p,Complex q){
        Complex c5=new Complex();
        c5.real=(p.real*q.real)-(p.img*q.img);
        c5.img=(p.real*q.img)+(p.img*q.real);
        return c5;
    }

    public Complex Division(Complex m, Complex n){
        Complex c6=new Complex();
        c6.real=(m.real*n.img + m.img* n.real)/(n.real* n.real + n.img* n.img);
        c6.img=(m.real*n.real - m.img*n.img)/(n.real* n.real + n.img* n.img);
        return c6;
    }

    public void display(){
        if(real==0){
            System.out.println("i"+img);
        }
        else if(img==0){
            System.out.println(real);
        }
        else if(img<0){
            System.out.println(real+ " "+img+"i ");
        }
        else{
            System.out.println(real+"+"+"i"+img);
        }
    }
}

public class Main{
    public static void main(String[] args){
        double real,img;

        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the real part of complex 1");
        real=sc.nextDouble();
        System.out.println("Enter the imaginary part of complex 1");
        img=sc.nextDouble();
        Complex c1=new Complex(real,img);

        Scanner sc2=new Scanner(System.in);
        System.out.println("Enter the real part of complex 2");
        real=sc2.nextDouble();
        System.out.println("Enter the imaginary part of complex 2");
        img=sc2.nextDouble();
        Complex c2=new Complex(real,img);

        System.out.println("-----------------------------------------");
        System.out.println("First complex is "+c1.real+"+" +"i "+c1.img);
        System.out.println("Second complex is "+c2.real+"+"+" i "+c2.img);

        do{
            System.out.println("Menu:");
            System.out.println("1 for Addition");
            System.out.println("2 for Subtraction");
            System.out.println("3 for Multiplication");
            System.out.println("4 for Division");
            System.out.println("5 for exit");

            Scanner s=new Scanner(System.in);
            System.out.println("Enter choice");
            int choice=s.nextInt();

            switch(choice){
                case 1:
                    Complex temp1=new Complex();
                    temp1=temp1.Addition(c1,c2);
                    temp1.display();
                    break;
                case 2:
                    Complex temp2=new Complex();
                    temp2=temp2.Subtraction(c1,c2);
                    temp2.display();
                    break;
                case 3:
                    Complex temp3=new Complex();
                    temp3=temp3.Multiplication(c1,c2);
                    temp3.display();
                    break;
                case 4:
                    Complex temp4=new Complex();
                    temp4=temp4.Division(c1,c2);
                    temp4.display();
                    break;
                case 5:
                    System.out.println("Program Terminated");
                    return;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }while(true);
    }
}

