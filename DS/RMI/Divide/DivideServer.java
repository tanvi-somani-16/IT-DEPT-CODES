import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class DivideServer {
    public static void main(String[] args) {
        try {
            DivideImpl obj = new DivideImpl();

            // Start RMI registry
            Registry registry = LocateRegistry.createRegistry(1099);

            // Bind service
            registry.rebind("DivideService", obj);

            System.out.println("Division Server Started...");
        } catch (Exception e) {
            System.out.println("Server Error: " + e);
        }
    }
}