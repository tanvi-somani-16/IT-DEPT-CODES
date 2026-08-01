import R.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.CosNaming.*;

public class ReverseServer {
    public static void main(String args[]){
        try{
            //initiate ORB
            ORB orb=ORB.init(args,null);

            //Get Root POA(Portable Object Adapter)
            POA rootpoa=POAHelper.narrow(orb.resolve_initial_references("RootPOA"));

            //Activate POA
            rootpoa.the_POAManager().activate();

            //Create Implementation object
            ReverseImpl obj=new ReverseImpl();

            //Convert Object to CORBA Reference
            org.omg.CORBA.Object ref=rootpoa.servant_to_reference(obj);

            //Narrowing to correct type
            Reverse href=ReverseHelper.narrow(ref);

            //Access Naming Service
            NamingContextExt ncRef=NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));

            //Bind Object to Name
            ncRef.rebind(ncRef.to_name("rev"),href);

            System.out.println("Server Ready....");

            //Start Server Loop
            orb.run();
        }catch(Exception e){
            System.out.println("Server Error : "+e);
        }
    }
}
