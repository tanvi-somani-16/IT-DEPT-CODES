import java.util.Scanner;

class Car{
    String cname , color ;
    int seat, gear ;
    Car(){
        this.cname = null;
        this.color = null;
        this.seat = 0;
        this.gear = 0;
    }
    public void collection(){
        System.out.println("Parts collected");
    }
    public void assemble(){
        System.out.println("Car assembling...........");
        System.out.println("Car assembeled");
    }
}
class Hatchback extends Car{
    Scanner sc = new Scanner(System.in);
    Hatchback(){
        System.out.print("Enter company name: ");
        this.cname = sc.next();
        System.out.println("Enter color: ");
        this.color = sc.next();
        System.out.println("Enter no. of gears: ");
        this.gear = sc.nextInt();
        System.out.println("Enter no. of seats: ");
        this.seat = sc.nextInt();
    }
    @Override
    public void collection() {
        System.out.println("---------Information collected--------");
        System.out.println("company name: " + cname);
        System.out.println("color: " + color);
        System.out.println("gear: " + gear);
        System.out.println("seats: " + seat);
        System.out.println("\n");
        super.collection();
    }

    @Override
    public void assemble() {
        super.assemble();
    }
}class Sedan extends Car{
    Scanner sc = new Scanner(System.in);
    Sedan(){
        System.out.print("Enter company name: ");
        this.cname = sc.next();
        System.out.println("Enter color: ");
        this.color = sc.next();
        System.out.println("Enter no. of gears: ");
        this.gear = sc.nextInt();
        System.out.println("Enter no. of seats: ");
        this.seat = sc.nextInt();
    }
    @Override
    public void collection() {
        System.out.println("---------Information collected--------");
        System.out.println("company name: " + cname);
        System.out.println("color: " + color);
        System.out.println("gear: " + gear);
        System.out.println("seats: " + seat);
        System.out.println("\n");
        super.collection();
    }

    @Override
    public void assemble() {
        super.assemble();
    }
}class Luxury extends Car{
    Scanner sc = new Scanner(System.in);
    Luxury(){
        System.out.print("Enter company name: ");
        this.cname = sc.next();
        System.out.println("Enter color: ");
        this.color = sc.next();
        System.out.println("Enter no. of gears: ");
        this.gear = sc.nextInt();
        System.out.println("Enter no. of seats: ");
        this.seat = sc.nextInt();
    }
    @Override
    public void collection() {
        System.out.println("---------Information collected--------");
        System.out.println("company name: " + cname);
        System.out.println("color: " + color);
        System.out.println("gear: " + gear);
        System.out.println("seats: " + seat);
        System.out.println("\n");
        super.collection();
    }

    @Override
    public void assemble() {
        super.assemble();
    }
}
class carfactory{
    Scanner sc = new Scanner(System.in);
    public Car getType(){
        System.out.println("Enter vehicle type you want to order from \n [Hatchback/Sedan/Luxury] = ");
        String type = sc.next();
        switch (type.toLowerCase()){
            case "hatchback" :
                return new Hatchback();
            case "sedan" :
                return new Sedan();
            case "luxury" :
                return new Luxury();
        }
        return null;
    }
}

public class testfactory{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String choice;
        do {
            carfactory cf = new carfactory();
            Car c = cf.getType();
            c.collection();
            c.assemble();

            System.out.println("\nDo you want to continue [Y/N]");
            choice = in.next();
        }while ( choice.equalsIgnoreCase("y"));
    }
}