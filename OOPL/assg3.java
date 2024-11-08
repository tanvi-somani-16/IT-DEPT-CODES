import java.util.Scanner;

class Employee{
    String Emp_name;
    int Emp_id;
    String Address;
    String Mail_id;
    double mob_no;
    double bp,hra,da,pf,club;
    double gross,net;
   public void get_data(){
        Scanner s=new Scanner(System.in);
        System.out.println("Enter id no of employee");
        Emp_id=s.nextInt();
        System.out.println("Enter name of employee");
        Emp_name=s.next();
        System.out.println("Enter mail id of employee");
        Mail_id=s.next();
        System.out.println("Enter mobile no of employee");
        mob_no=s.nextDouble();
        System.out.println("Enter the address of employee");
        Address=s.next();
    }

    public void display(){
       System.out.println("Name :"+Emp_name);
       System.out.println("Employee id :"+Emp_id);
       System.out.println("Mail id :"+Mail_id);
       System.out.println("Mobile no :"+mob_no);
       System.out.println("Address :"+Address);
    }

    public void get_slip(){
       hra=0.10*bp;
       da=0.97*bp;
       pf=0.12*bp;
       club=0.001*bp;
       gross=hra+da+bp;
       net=gross-pf-club;
       System.out.println("Gross salary: "+gross);
       System.out.println("Net salary :"+net);
    }

}

class Programmer extends Employee{
    public void get_asst(){
        Scanner a=new Scanner(System.in);
        System.out.println("Basic pay :");
        bp=a.nextDouble();
    }
    public void calculate_asst(){
        display();
        get_slip();
    }

}

class Team_Lead extends Employee{
    public void get_asst(){
        Scanner b=new Scanner(System.in);
        System.out.println("Basic pay :");
        bp=b.nextDouble();
    }
    public void calculate_asst(){
        display();
        get_slip();
    }
}

class Assistant_PM extends Employee{
    public void get_asst(){
        Scanner c=new Scanner(System.in);
        System.out.println("Basic pay :");
        bp=c.nextDouble();
    }
    public void calculate_asst(){
        display();
        get_slip();
    }
}

class Project_Manager extends Employee{
    public void get_asst(){
        Scanner d=new Scanner(System.in);
        System.out.println("Basic pay :");
        bp=d.nextDouble();
    }
    public void calculate_asst(){
        display();
        get_slip();
    }
}

public class Main{
    public static void main(String[] args){
        do{
            System.out.println("------------------------------------------------");
            System.out.println("1 for Programmer");
            System.out.println("2 for Team Lead ");
            System.out.println("3 for Assistant Project Manager");
            System.out.println("4 for Project Manager");
            System.out.println("5 for exit");

            Scanner sc=new Scanner(System.in);
            System.out.println("Enter choice");
            int ch=sc.nextInt();

            switch(ch){
                case 1:
                    Programmer p=new Programmer();
                    p.get_data();
                    p.get_asst();
                    p.calculate_asst();
                    break;
                case 2:
                    Team_Lead t=new Team_Lead();
                    t.get_data();
                    t.get_asst();
                    t.calculate_asst();
                    break;
                case 3:
                    Assistant_PM ap=new Assistant_PM();
                    ap.get_data();
                    ap.get_asst();
                    ap.calculate_asst();
                    break;
                case 4:
                    Project_Manager pm=new Project_Manager();
                    pm.get_data();
                    pm.get_asst();
                    pm.calculate_asst();
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