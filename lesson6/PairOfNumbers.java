public class PairOfNumbers{
    private static int a;
    private static int b;
    
    public static int maxValue(){
        if (a > b){
            return a;
        }
        else{
            return b;
        }
    };

    public static int minValue(){
        if (a < b){
            return a;
        }
        else{
            return b;
        }
    };

    public static float average(){
        return (float)(a + b)/2 ;
    };

    public PairOfNumbers(int a, int b){
        this.a = a;
        this.b = b;

    }
    public static void main(String[] args ){
        PairOfNumbers pair = new PairOfNumbers(2,5);
        System.out.println(pair.average());
        
    }
}
