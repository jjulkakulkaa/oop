public class Euro implements Currency {
    private final float money;
    private final FakeCantor fc = new FakeCantor();
    @Override
    public Euro addedCurrency(float value, String currency){
        return new Euro(this.money + (value / fc.euroToRate(currency)));
    }
    @Override
    public Euro subtractedCurrency(float value, String currency){
        float subBalance = this.money - (value / fc.euroToRate(currency));
        if (subBalance >= 0){
            return new Euro(subBalance);
        }
        else {
            return new Euro(0);
        }
    }

    public String abbreviation(){
        return "EUR";
    }
    public String symbol(){
        return "EUR";
    }
    public String ballance(){
        return "your ballance is: " + money + "\n";  
    }
    public Euro(float money){
        this.money = money;
    }
    public static void main(String[] args){
        Euro euro = new Euro(420);
        System.out.println(euro.ballance());
    }
}
