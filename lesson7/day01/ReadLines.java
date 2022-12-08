package lesson7.day01;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class ReadLines {
    
    public static void main(String args[]){
    try{
        FileInputStream file=new FileInputStream("Day01.txt");
        Scanner scanner=new Scanner(file);
        ArrayList<Elf> elves = new ArrayList<>();
        while(scanner.hasNextLine())
        {
            elves.add(new OneElf(0));
            while(scanner.nextLine()!= "\n"){
                int calories_to_add = Integer.valueOf(scanner.nextLine());
                
            }
        }
        scanner.close();
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
    }
}
