import java.rmi.registry.*;

public class MultiplyClient {
    public static void main(String[] args){
        try{
            //host
            String host="localhost";

            //getregistry
            Registry registry=LocateRegistry.getRegistry(host,1099);

            //lookup service
            MultiplyInterface stub=(MultiplyInterface) registry.lookup("MultiplyService");

            int result=stub.multiply(5,5);

            System.out.println("Multiplication: "+result);
        }catch(Exception e){
            System.err.println(e);
        }
    }
}
