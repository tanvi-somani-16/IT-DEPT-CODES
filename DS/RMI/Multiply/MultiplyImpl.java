import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class MultiplyImpl extends UnicastRemoteObject implements MultiplyInterface{
    
    protected MultiplyImpl() throws RemoteException{
        super();
    }

    public int multiply(int a, int b) throws RemoteException{
        System.out.println("Client Request Handled by"+ Thread.currentThread().getName());
        return a*b;
    }
}