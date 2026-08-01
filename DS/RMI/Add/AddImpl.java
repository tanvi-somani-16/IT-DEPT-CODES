import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class AddImpl extends UnicastRemoteObject implements AddInterface {
    
    protected AddImpl() throws RemoteException{
        super();
    }

    public int add(int a, int b) throws RemoteException{
        System.out.println("Client Request Handled By"+Thread.currentThread().getName());
        return a+b;
    }
}
