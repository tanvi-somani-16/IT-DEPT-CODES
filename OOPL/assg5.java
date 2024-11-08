import java.util.Scanner;

interface Vehicle{
     void speed_up();
     void change_gear();
     void brakes();
}

class Bicycle implements Vehicle{
    int speed;
    int gear;
    int speedu;
    int speedd;
    @Override
    public void speed_up(){
        Scanner s=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=s.nextInt();
        System.out.println("Increase the speed");
        speedu=s.nextInt();
        speed+=speedu;
        System.out.println("Speed:"+speed);
    }
    @Override
    public void change_gear(){
        Scanner b=new Scanner(System.in);
        System.out.println("Enter the gear to be changed");
        gear=b.nextInt();
        System.out.println("Gear changed to "+gear);
    }
    @Override
    public void brakes(){
        Scanner a=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=a.nextInt();
        if(speed>30){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 5");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>25||speed<30){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 4");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>20||speed<25){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 3");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>15||speed<20){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 2");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>10||speed<15){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 1");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else{
            System.out.println("No need to apply brakes");
        }
    }
}
class Bike implements Vehicle{
    int speed;
    int gear;
    int speedu;
    int speedd;
    @Override
    public void speed_up(){
        Scanner s=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=s.nextInt();
        System.out.println("Increase the speed");
        speedu=s.nextInt();
        speed+=speedu;
        System.out.println("Speed:"+speed);
    }
    @Override
    public void change_gear(){
        Scanner b=new Scanner(System.in);
        System.out.println("Enter the gear to be changed");
        gear=b.nextInt();
        System.out.println("Gear changed to "+gear);
    }
    @Override
    public void brakes(){
        Scanner a=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=a.nextInt();
        if(speed>80){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 5");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>60||speed<80){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 4");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>40||speed<60){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 3");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>20||speed<40){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 2");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>10||speed<20){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 1");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else{
            System.out.println("No need to apply brakes");
        }
    }
}
class Car implements Vehicle{
    int speed;
    int gear;
    int speedu;
    int speedd;
    @Override
    public void speed_up(){
        Scanner s=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=s.nextInt();
        System.out.println("Increase the speed");
        speedu=s.nextInt();
        speed+=speedu;
        System.out.println("Speed:"+speed);
    }
    @Override
    public void change_gear(){
        Scanner b=new Scanner(System.in);
        System.out.println("Enter the gear to be changed");
        gear=b.nextInt();
        System.out.println("Gear changed to "+gear);
    }
    @Override
    public void brakes(){
        Scanner a=new Scanner(System.in);
        System.out.println("Current speed:");
        speed=a.nextInt();
        if(speed>100){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 5");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>80||speed<100){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 4");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>60||speed<80){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 3");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>40||speed<60){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 2");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else if(speed>20||speed<40){
            System.out.println("Reduce the speed");
            System.out.println("Change the gear to 1");
            System.out.println("Speed to reduce");
            speedd=a.nextInt();
            speed-=speedd;
            System.out.println("Speed reduced to "+speed);
        }
        else{
            System.out.println("No need to apply brakes");
        }
    }
}

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int flag=1;
        do {
            System.out.println("Menu:");
            System.out.println("1 for Bicycle");
            System.out.println("2 for Bike");
            System.out.println("3 for Car");
            System.out.println("4 for exit");

            System.out.println("Enter choice:");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    Bicycle b = new Bicycle();
                    int choice1;
                    do {
                        System.out.println("1 for increase speed");
                        System.out.println("2 for change gear");
                        System.out.println("3 for decrease speed");
                        System.out.println("4 for exit");
                        System.out.println("Enter choice:");

                        choice1 = sc.nextInt();
                        switch (choice1) {
                            case 1:
                                b.speed_up();
                                break;
                            case 2:
                                b.change_gear();
                                break;
                            case 3:
                                b.brakes();
                                break;
                            case 4:
                                System.out.println("Exit");
                                break;
                            default:
                                System.out.println("Invalid choice");
                                break;
                        }
                    }while(choice1!=4);
                    break;
                case 2:
                    Bike bk = new Bike();
                    int choice2;
                    do {
                        System.out.println("1 for increase speed");
                        System.out.println("2 for change gear");
                        System.out.println("3 for decrease speed");
                        System.out.println("4 for exit");
                        System.out.println("Enter choice:");

                        choice2 = sc.nextInt();
                        switch (choice2) {
                            case 1:
                                bk.speed_up();
                                break;
                            case 2:
                                bk.change_gear();
                                break;
                            case 3:
                                bk.brakes();
                                break;
                            case 4:
                                System.out.println("Exit");
                                break;
                            default:
                                System.out.println("Invalid choice");
                                break;
                        }
                    }while(choice2!=4);
                    break;
                case 3:
                    Car c = new Car();
                    int choice3;
                    do {
                        System.out.println("1 for increase speed");
                        System.out.println("2 for change gear");
                        System.out.println("3 for decrease speed");
                        System.out.println("4 for exit");
                        System.out.println("Enter choice:");

                        choice3 = sc.nextInt();
                        switch (choice3) {
                            case 1:
                                c.speed_up();
                                break;
                            case 2:
                                c.change_gear();
                                break;
                            case 3:
                                c.brakes();
                                break;
                            case 4:
                                System.out.println("Exit");
                                break;
                            default:
                                System.out.println("Invalid choice");
                                break;
                        }
                    }while(choice3!=4);
                    break;
                case 4:
                    System.out.println("Program Terminated");
                    flag=0;
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
               }
        }while(flag!=0);
    }
}
