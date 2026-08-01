import java.rmi.Remote;
import java.rmi.RemoteException;

public interface DivideInterface extends Remote {
   public double divide(double a, double b) throws RemoteException; 
}
