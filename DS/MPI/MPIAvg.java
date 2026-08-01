import mpi.*;

public class MPIAvg {
    public static void main(String args[]){
        
        MPI.Init(args);

        int rank=MPI.COMM_WORLD.Rank();
        int size=MPI.COMM_WORLD.Size();

        int n=size*2;   //number of elements 
        int sendbuff[]=new int[n];
        int recvbuff[]=new int[n/size];

        double localAvg[]=new double[1];
        double allAvg[]=new double[size];
        
        //generating random array
        if(rank==0){
            System.out.println("Generated Array:");

            for(int i=0;i<n;i++){
                sendbuff[i] = (int)(Math.random() * 10); // random 0-9
                System.out.print(sendbuff[i]+" ");
            }

            System.out.println();
        }

        MPI.COMM_WORLD.Scatter(sendbuff,0,n/size,MPI.INT,recvbuff,0,n/size,MPI.INT,0);

        //calculate local avg of each process
        int sum=0;
        for(int i=0;i<n/size;i++){
            sum+=recvbuff[i];
        }

        localAvg[0]=(double)sum/recvbuff.length;

        System.out.println("Process "+rank+" Local Average: "+localAvg[0]);

        //gather all localavgs
        MPI.COMM_WORLD.Gather(localAvg,0,1,MPI.DOUBLE,allAvg,0,1,MPI.DOUBLE,0);

        //Root computed Final Aberage
        if(rank==0){
            double finalAvg=0;

            for(int i=0;i<size;i++){
                finalAvg+=allAvg[i];
            }

            finalAvg=finalAvg/size;

            System.out.println("Final Average: "+finalAvg);
        }

        MPI.Finalize();
    }
}
