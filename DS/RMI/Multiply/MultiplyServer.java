import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

public class MultiplyServer {
    public static void main(String[] args){
        try{

            //object creation
            MultiplyImpl obj=new MultiplyImpl();

            //registry attach
            Registry registry=LocateRegistry.createRegistry(1099);

            //bind object
            registry.rebind("MultiplyService",obj);

            System.out.println("Multiplication server started....");
        }catch(Exception e){
            System.err.println(e);
        }
    }
}
