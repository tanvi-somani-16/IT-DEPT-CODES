import mpi.*;

public class MPIReciprocal {
    public static void main(String args[]){

        MPI.Init(args);

        int rank=MPI.COMM_WORLD.Rank();
        int size=MPI.COMM_WORLD.Size();

        int sendbuff[]=new int[size];
        int recvbuff[]=new int[1];

        double result[]=new double[1];
        double finalResult[]=new double[size];

        if(rank==0){
            int temp[]={2,9,8,3,4};
            for(int i=0;i<size;i++){
                sendbuff[i]=temp[i];
            }
        }

        MPI.COMM_WORLD.Scatter(sendbuff, 0, 1, MPI.INT,recvbuff, 0, 1, MPI.INT, 0);

        int data=recvbuff[0];
        //compute reciprocal
        if(data!=0){
            result[0]=1.0/data;
        }
        else{
            result[0]=0;
        }

        System.out.println("Process " + rank + " Reciprocal = " + result[0]);

        // Gather results at root
        MPI.COMM_WORLD.Gather(result, 0, 1, MPI.DOUBLE,
                              finalResult, 0, 1, MPI.DOUBLE, 0);

        // Root prints final array
        if (rank == 0) {
            System.out.println("Final Resultant Array (Reciprocals):");
            for (int i = 0; i < size; i++) {
                System.out.print(finalResult[i] + " ");
            }
            System.out.println();
        }

        MPI.Finalize();
    }
}
