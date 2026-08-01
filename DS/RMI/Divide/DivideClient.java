import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class DivideClient {
    public static void main(String[] args) {
        try {
            // Replace with server IP address
            String host = "localhost";

            Registry registry = LocateRegistry.getRegistry(host, 1099);

            DivideInterface stub = (DivideInterface) registry.lookup("DivideService");

            double result = stub.divide(20, 0);

            System.out.println("Division Result: " + result);

        } catch (ArithmeticException ae) {
            System.out.println("Math Error: " + ae.getMessage());
        } catch (Exception e) {
            System.out.println("Client Error: " + e);
        }
    }
}
