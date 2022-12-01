import java.io.IOException;

interface Number{
    double doubleValue();
}
public class Logarithm implements Number {
    private double base, argument;
    @Override
    public double doubleValue() { return Math.log(this.argument) / Math.log(this.base);}
    public Logarithm(double inputBase, double inputArgument) {
      if (inputBase < 0 || inputBase == 1){
        throw new IllegalArgumentException(
            String.format("Liczba mniejsza od 1 nie moze byc podstawa logarytmutmu")
        );
      }
      if (argument < 0){
        throw new IllegalArgumentException(
            String.format("Liczba mniejsza od o nie moze byc argumentem logarytmu")
        );
      }
      this.base = inputBase;
      this.argument = inputArgument;
    }

    public static void main(String[] args ){
        try{
            Logarithm log = new Logarithm(0, 0);    
        } catch (IllegalArgumentException ex) {
            throw new IllegalArgumentException(
                String.format("podane wartosci nie spelniaja wlasnosci logarytmu"),
                ex
            );
        }
        
    }
  }