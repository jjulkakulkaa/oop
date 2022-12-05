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
            String.format("The base of a log function cannot be equal to 1 or less than 0")
        );
      }
      if (argument < 0){
        throw new IllegalArgumentException(
            String.format("The argument of a log function cannot be smaller than 0")
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
                String.format("Logarithm cannot be computed from given values"),
                ex
            );
        }
        
    }
  }
