import java.lang.String;
import java.util.Scanner;

class exception{
    public void div(){
        Scanner s=new Scanner(System.in);
        try{
            System.out.println("Enter first number:");
            String a=s.nextLine();
            int num1=Integer.parseInt(a);
            System.out.println("Enter second number");
            String b=s.nextLine();
            int num2=Integer.parseInt(b);
            int result=num1/num2;
            System.out.println("Division is "+result);
        }
        catch(ArithmeticException e) {
            System.out.println("Warning: Exception occured " + e);
            System.out.println("Enter valid divisior");
        }
        catch(NumberFormatException e){
            System.out.println("Warning: Exception occured "+e);
        }
        finally{
            System.out.println("First try catch block completed");
        }
    }

    public void array(){
        int[] a={2,68,4,36,12,45};
        Scanner c=new Scanner(System.in);
        try{
            for(int i=0;i<6;i++){
                System.out.println("Array elemnts are ");
                System.out.print(a[i]+" ");
            }
            System.out.println("Enter the index of array");
            int num=c.nextInt();
            System.out.println("Element at index "+num+" is "+a[num]);
            }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Warning: Index out of bound "+e);
        }
        finally{
            System.out.println("Second try catch block ended");
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner d=new Scanner(System.in);
        exception ed=new exception();
        int flag=1;
        do{
            System.out.println("Menu:");
            System.out.println("1 for exceptions in division");
            System.out.println("2 for array exceptions");
            System.out.println("3 for exit");

            System.out.println("Enter choice");
            int choice=d.nextInt();

            switch(choice){
                case 1:
                    ed.div();
                    System.out.println("-----------------------------------------------");
                    break;
                case 2:
                    ed.array();
                    System.out.println("-------------------------------------------------");
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


