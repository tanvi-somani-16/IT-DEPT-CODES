import java.util.Scanner;
import java.util.ArrayList;

class gen<T>{
    ArrayList<T> arraylist=new ArrayList<>();
    Scanner s=new Scanner(System.in);

    public void input(){
        System.out.println("Enter length of arraylist");
        int length=s.nextInt();
        System.out.println("Enter elements of arraylist");
        for(int i=0;i<length;i++){
            arraylist.add((T)s.next());
        }
    }
    public void display(){
        System.out.println("Elements in array are ");
        for(T j:arraylist){
            System.out.println(j+" ");
        }
    }
    public void show(){
        ArrayList<Integer> even=new ArrayList<>();
        ArrayList<Integer> odd=new ArrayList<>();
        for( T j:arraylist) {
            int var = Integer.parseInt((String) j);
            if (var % 2 == 0) {
                even.add(var);
            } else {
                odd.add(var);
            }
        }
        System.out.println("Even elements");
        if(even.isEmpty()){
            System.out.println("No even elements added");
        }
        else{
            System.out.println(even);
        }
        System.out.println("Odd elements");
        if(odd.isEmpty()){
            System.out.println("No odd elements added");
        }
        else{
            System.out.println(odd);
        }
    }
    public void prime(){
        ArrayList<Integer> prime=new ArrayList<>();
        for(T i:arraylist) {
            int var = Integer.parseInt((String) i);
            boolean flag = false;

            if (var == 0) {
                flag = true;
            } else if (var == 1) {
                flag = true;
            } else {
                for (int k = 2; k < var; k++) {
                    if (var % k == 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                prime.add(var);
            }
        }
        System.out.println("Prime elements");
        if(prime.isEmpty()){
            System.out.println("No prime elements added");
        }
        else{
            System.out.println(prime);
        }
    }
    public void palindrome(){
        ArrayList<String> palindrome=new ArrayList<>();
        for(T m:arraylist){
            String s=(String) m;
            String rev="";
            for(int i=s.length()-1;i>=0;i--){
                rev=rev+s.charAt(i);
            }
            if(rev.equals(s)){
                palindrome.add(s);
            }
        }
        System.out.println("Palindrome elements");
        if(palindrome.isEmpty()){
            System.out.println("Palindrome not found");
        }
        else{
            System.out.println(palindrome);
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int flag=1;
        do{
            try{
                System.out.println("Menu:");
                System.out.println("1 for operation on integer");
                System.out.println("2 for operation on string");
                System.out.println("3 for exit");

                System.out.println("Enter choice");
                int choice=Integer.parseInt(sc.next());

                switch (choice){
                    case 1:
                        gen g=new gen();
                        g.input();
                        g.display();
                        g.show();
                        g.prime();
                        break;
                    case 2:
                        gen g1=new gen();
                        g1.input();
                        g1.display();
                        g1.palindrome();
                        break;
                    case 3:
                        System.out.println("Program Terminated");
                        flag=0;
                        break;
                    default:
                        System.out.println("Invalid choice");
                        break;
                }
            }
            catch(NumberFormatException e){
                System.out.println("Warning : Exception "+e);
            }
        }while(flag!=0);
    }
}