import R.*;
import org.omg.CORBA.*;
import org.omg.CosNaming.*;
import java.util.*;

public class ReverseClient {
    public static void main(String args[]){

        try{
            //initiate ORB
            ORB orb=ORB.init(args,null);

            //Access Naming Service
            NamingContextExt ncRef=NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));

            //Lookup Remote Object
            Reverse obj=ReverseHelper.narrow(ncRef.resolve_str("rev"));

            Scanner sc=new Scanner(System.in);
            System.out.println("Enter String :");
            String s=sc.nextLine();

            System.out.println("Result : "+obj.rev(s));

        }catch(Exception e){
            System.out.println("Client Error :"+e);
        }
    }
}
