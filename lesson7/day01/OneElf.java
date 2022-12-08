package lesson7.day01;
interface Elf{
    int updatedCalories(int added_calories);
    int atributes();
}
public class OneElf implements Elf{
    private int foodCalories;
    @Override
    public int updatedCalories(int added_calories){
        return this.foodCalories + added_calories;
    }
    @Override
    public int atributes(){
        return foodCalories;
    }
    public OneElf(int foodCalories){
        this.foodCalories = foodCalories;
    }

}