import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class AddClient {
    public static void main(String[] args){
        try{
            //Replace server with IP Address
            String host="localhost";

            //get registry
            Registry registry=LocateRegistry.getRegistry(host,1099);

            //Lookup service
            AddInterface stub=(AddInterface) registry.lookup("AddService");

            //Call Remote method
            int result=stub.add(10,15);

            System.out.println("Addition Result:"+result);
        }catch(Exception e){
            System.err.println(e);
        }
    }
}
