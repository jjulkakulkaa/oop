interface Vehicle {
    Vehicle upgradedEngine(float max_speed, float horsepower);
    Vehicle changedColor(String colour);
    String atributes();
}
public class Car implements Vehicle {
    private final float max_speed;
    private final float horsepower;
    private final String color;
    private final String transmission;
    @Override
    public Car upgradedEngine(float added_speed, float added_horsepower){
        return new Car(this.max_speed + added_speed,this.horsepower + added_horsepower, this.color, this.transmission);
    }
    @Override
    public Car changedColor(String color){
        return new Car(this.max_speed, this.horsepower, color, this.transmission);
    }
    @Override
    public String atributes(){
        return "maximum speed: " + max_speed + "km/h\n" + "horsepower: " + horsepower + "\ncolor: "+ color +"\n"+transmission+ " transmission" ;
    }
    public Car(float max_speed, float horsepower, String color, String transmission){
        this.max_speed = max_speed;
        this.horsepower = horsepower;
        this.color = color;
        this.transmission = transmission;
    }
    public static void main(String[] args){
        Car car = new Car(100,200,"black","manual");
        Car car2 = car.upgradedEngine(120,69);
        Car car3 = car.changedColor("white");
        System.out.println(car2.atributes());
    }
}
