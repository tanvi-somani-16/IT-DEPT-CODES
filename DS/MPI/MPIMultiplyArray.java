import mpi.*;

public class MPIMultiplyArray {
    public static void main(String args[]){

        MPI.Init(args);

        int rank=MPI.COMM_WORLD.Rank();
        int size=MPI.COMM_WORLD.Size();

        int sendbuff[]=new int[size];
        int recvbuff[]=new int[1];

        if(rank==0){
            int temp[] = {2,4,6,8};   // fixed input
            for(int i=0;i<size;i++){
                sendbuff[i]=temp[i];
            }
        }

        MPI.COMM_WORLD.Scatter(sendbuff, 0, 1, MPI.INT,recvbuff, 0, 1, MPI.INT, 0);

        int data=recvbuff[0];
        int product=data;

        if(rank!=0){
            int temp[]=new int[1];
            MPI.COMM_WORLD.Recv(temp,0,1,MPI.INT,rank-1,0);
            product=temp[0]*data;
        }

        if(rank!=size-1){
            int temp[]=new int[1];
            temp[0]=product;
            MPI.COMM_WORLD.Send(temp,0,1,MPI.INT,rank+1,0);
        }

        System.out.println("Process " + rank + " Intermediate Product = " + product);

        MPI.Finalize();
    }
}
