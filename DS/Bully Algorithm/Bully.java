import java.util.*;

public class Bully{
    
    static boolean[] alive;
    static int n;

    //Bully Algorithm
    static void election(int p){
        System.out.println("Start Election from "+p+" ");

        for(int i=p+1;i<n;i++){
            if(alive[i]){
                System.out.println("(" + p + " -> " + i + ")");
                election(i);
                return;
            }
        }

        System.out.println("\n Coordinator (Bully Leader) :"+p);

        for(int i=0;i<n;i++){
            if(i!=p && alive[i]){
                System.out.println(p+" -> "+i);
            }
        }
    }

    static void showStatus() {
        System.out.print("Status: ");
        for (int i = 0; i < n; i++) {
            System.out.print(i + (alive[i] ? "(UP) " : "(DOWN) "));
        }
        System.out.println();
    }

    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter number of processes :");
        n=sc.nextInt();

        alive=new boolean[n];
        Arrays.fill(alive,true);

        int choice;

        System.out.println("\n========= MENU =========");
        System.out.println("1. UP a process: activate a deactivated Process");
        System.out.println("2. DOWN a process: Simulate failure (of a Process");
        System.out.println("3. ELECT leader: Starts Bully election from a process");
        System.out.println("4. SHOW STATUS: Displays which processes are UP/DOWN");
        System.out.println("5. EXIT");

        do{

            System.out.println("Enter your choice :");
            choice=sc.nextInt();

            switch(choice){
                case 1:
                    System.out.println("Process to UP (0-"+(n-1)+":");
                    alive[sc.nextInt()]=true;
                    break;
                case 2:
                    System.out.println("Process to DOWN (0-"+(n-1)+":");
                    alive[sc.nextInt()]=false;
                    break;
                case 3:
                    System.out.println("Start election process from (0-" + (n - 1) + "):" );
                    int p=sc.nextInt();
                    if(!alive[p]){
                        System.out.println("Process is Down");
                    }else{
                        election(p);
                    }
                    break;
                case 4:
                    showStatus();
                    break;
                case 5:
                    System.out.println("Exit");
                    break;
                default:
                    System.out.println("Invalid Choice");
            }
        }while(choice!=5);
    }

}
