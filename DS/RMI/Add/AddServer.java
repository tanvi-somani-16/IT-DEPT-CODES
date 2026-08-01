import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class AddServer {
    public static void main(String[] args){
        try{
            //Create Object
            AddImpl obj=new AddImpl();

            //Start RMI Registry at port 1099
            Registry registry=LocateRegistry.createRegistry(1099);

            //Bind Object
            registry.rebind("AddService",obj);

            System.out.println("Addition Server started...");
        }catch(Exception e){
            System.err.println(e);
        }
    }
}
