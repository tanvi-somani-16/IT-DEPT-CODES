import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

public class DivideImpl extends UnicastRemoteObject implements DivideInterface {
    
    protected DivideImpl() throws RemoteException{
        super();
    }


    public double divide(double a, double b) throws RemoteException{
        System.out.println("Client Request Handled by : "+ Thread.currentThread().getName());

        if(b==0){
            throw new ArithmeticException("Cannot divide by Zero");
        }

        return a/b;

    }
} 
