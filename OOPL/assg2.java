import java.util.Scanner;

class Publications{
    String Title;
    int Price;
    int Copies;
    public void get_data(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter title :");
        Title=sc.nextLine();
        System.out.println("Enter price :");
        Price=sc.nextInt();
        System.out.println("Enter copies available :");
        Copies=sc.nextInt();
    }
    public void sale_copy(int p,int q){
        int total_sale=p+q;
        System.out.println("Total sale:"+total_sale);
    }

}

class Books extends Publications{
    String author;
    int order;
    int calculate;
    Books(){
        calculate=0;
        order=0;
    }
    public void order_copies(){
        get_data();
        Scanner s=new Scanner(System.in);
        System.out.println("Enter author name :");
        author=s.nextLine();
    }

    public void sale_copy(){
        Scanner st=new Scanner(System.in);
        System.out.println("Enter quantity :");
        order=st.nextInt();
        if(order<Copies){
            calculate=order*Price;
            System.out.println("Ordered Price:"+calculate);
        }
        else if(order==0){
            System.out.println("No orders for this copy");
        }
        else{
            System.out.println("Orders are more than available copies");
        }
    }
}

class Magazine extends Publications{
    int Qty;
    String current_issue;
    int calculate;
    Magazine(){
        calculate=0;
        Qty=0;
    }

    public void recive_issue(){
        get_data();
        Scanner ac=new Scanner(System.in);
        System.out.println("Enter current issue");
        current_issue=ac.next();
    }

    public void sale_copy(){
        Scanner a=new Scanner(System.in);
        System.out.println("Enter quantity: ");
        Qty=a.nextInt();
        if(Qty<Copies){
            calculate=Qty*Price;
            System.out.println("Orderd Price :"+calculate);
        }
        else if(Qty==0){
            System.out.println("No copies orderd");
        }
        else{
            System.out.println("Qty exceeds copies");
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner b=new Scanner(System.in);
        int flag=1;
        Publications pbc=new Publications();
        Books abc=new Books();
        Magazine mn=new Magazine();

        do{
            System.out.println("Menu:");
            System.out.println("1 for book order copies and sale copies");
            System.out.println("2 for magazine ordercopies and sale copies");
            System.out.println("3 for total sale");
            System.out.println("4 for exit");

            System.out.println("Enter choice:");
            int choice=b.nextInt();

            switch(choice){
                case 1:
                    abc.order_copies();
                    abc.sale_copy();
                    System.out.println("Ordered succesffully");
                    System.out.println("-------------------------------------------------");
                    break;
                case 2:
                    mn.recive_issue();
                    mn.sale_copy();
                    System.out.println("Ordered succesffully");
                    System.out.println("-------------------------------------------------");
                    break;
                case 3:
                    pbc.sale_copy(abc.calculate,mn.calculate);
                    System.out.println("-------------------------------------------------");
                    break;
                case 4:
                    System.out.println("Program terminated");
                    flag=0;
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        }while(flag!=0);
    }
}