import java.util.*;

public class TokenRing {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter number of nodes :");
        int n=sc.nextInt();

        System.out.println("Ring");
        for(int i=0;i<n;i++){
            System.out.print(i+"->");
        }
        System.out.println("0");

        int choice;
        int token=0;        //token starts at 0

        do{
            System.out.println("Current token at process "+token);

            System.out.println("Enter sender : ");
            int sender=sc.nextInt();
            System.out.println("Enter Reciver : ");
            int reciver=sc.nextInt();

            sc.nextLine();

            System.out.println("Enter Data : ");
            String data=sc.nextLine();

            //move token until it reaches sender
            while(token!=sender){
                System.out.println(token+"->");
                token=(token+1)%n;
            }
            System.out.println("Sender : "+token);

            //critical section
            System.out.println("Process "+sender+" enter CRITICAL SECTION");
            System.out.println("Sending Data : "+data);

            //data forwarding
            int i=sender;
            while(i!=reciver){
                System.out.println("Data Forwarded from "+i+" to "+(i+1)%n);
                i=(i+1)%n;
            }

            System.out.println("Data "+data+" Received by Process : "+reciver);
            System.out.println("Process "+sender+" exits CRITICAL SECTION");

            //pass token to next process
            token=(token+1)%n;

            System.out.println("\nEnter 1 to continue ,Enter 0 to exit");
            choice=sc.nextInt();
        }while(choice==1);


    }
}
