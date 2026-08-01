import mpi.*;
import java.util.*;

public class MPIArray {
    public static void main(String args[]) throws Exception{

        MPI.Init(args); //initialize MPI

        int rank=MPI.COMM_WORLD.Rank(); //process id
        int size=MPI.COMM_WORLD.Size();  //number of processes

        int sendbuff[]=new int[size];   //root array
        int recvbuff[]=new int[1];  //each process gets 1 element

        //Root Process Input
        // if(rank==0){
        //     Scanner sc=new Scanner(System.in);
        //     System.out.println("Enter "+size+" elements :");
        //     for(int i=0;i<size;i++){
        //         sendbuff[i]=sc.nextInt();
        //     }
        // }
        if(rank==0){
            int temp[] = {10, 20, 30, 40};   // fixed input
            for(int i=0;i<size;i++){
                sendbuff[i]=temp[i];
            }
        }

        //Scatter the elements in processes
        //The last parameter in Scatter denotes the root process, which distributes data to all other processes.
        // Scatter(sendbuf, send_offset, send_count, datatype,recvbuf, recv_offset, recv_count, datatype,root)
        MPI.COMM_WORLD.Scatter(sendbuff,0,1,MPI.INT,recvbuff,0,1,MPI.INT,0); 

        int data=recvbuff[0];
        int sum=data;

        //Intermeditate sum calculation

        //Recieve Condition
        if(rank!=0){
            int temp[]=new int[1];
            MPI.COMM_WORLD.Recv(temp,0,1,MPI.INT,rank-1,0);     //Recv(buffer, offset, count, datatype, source, tag)
            sum=temp[0]+data;
        }

        //Send Condition
        if(rank!=size-1){
            int temp[]=new int[1];
            temp[0]=sum;
            MPI.COMM_WORLD.Send(temp,0,1,MPI.INT,rank+1,0);         //Send(buffer, offset, count, datatype, destination, tag)
        }

        //Output
        System.out.println("Process "+rank+" Intermediate Sum : "+sum);

        MPI.Finalize();


    }
}

//MPI runs the same code on multiple processes simultaneously
//MPI uses SPMD (Single Program Multiple Data)
