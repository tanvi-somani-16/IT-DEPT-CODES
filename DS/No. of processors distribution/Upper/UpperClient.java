import U.*;
import org.omg.CORBA.*;
import org.omg.CosNaming.*;
import java.util.*;

public class UpperClient {
    public static void main (String args[]){
        try{

            ORB orb=ORB.init(args,null);

            NamingContextExt ncRef=NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));

            Upper obj=UpperHelper.narrow(ncRef.resolve_str("upper"));

            Scanner sc=new Scanner(System.in);
            System.out.println("Enter String :");
            String s=sc.nextLine();

            System.out.println("Upper Case String: "+obj.convert(s));

        }catch(Exception e){
            System.out.println("Client Error "+e);
        }
    }
}
