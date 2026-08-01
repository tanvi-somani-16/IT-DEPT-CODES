import U.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.CosNaming.*;

public class UpperServer {
    public static void main(String args[]){

        try{
            ORB orb=ORB.init(args,null);

            POA rootpoa=POAHelper.narrow(orb.resolve_initial_references("RootPOA"));

            rootpoa.the_POAManager().activate();

            UpperImpl obj=new UpperImpl();

            org.omg.CORBA.Object ref=rootpoa.servant_to_reference(obj);

            Upper href=UpperHelper.narrow(ref);

            NamingContextExt ncRef=NamingContextExtHelper.narrow(orb.resolve_initial_references("NameService"));

            ncRef.rebind(ncRef.to_name("upper"),href);

            System.out.println("Server Ready ...");

            orb.run();
        }catch(Exception e){
            System.out.println("Server Error : "+e);
        }

    }
}
