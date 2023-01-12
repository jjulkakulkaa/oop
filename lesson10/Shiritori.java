import java.util.Vector;

public class Shiritori {
    private Vector<String> words = new Vector<String>();
    private boolean game_over;
    Shiritori(){ 
    }

    public void restart(){
        words.clear();
        game_over = false;
        System.out.println("Game restarted");
    }

    public boolean valid(String word){
        if(words.contains(word)){
            System.out.println("Word " + word + " was already used ");
            game_over = true;
            return false;
        }
        else if (words.size() > 0) {
            String lastWord = words.get(words.size()-1);
            if(lastWord.charAt(lastWord.length()-1) != word.charAt(0)){
                System.out.println(word + " doesn't start with '"+ lastWord.charAt(lastWord.length()-1) +"'" );
                game_over = true;
                return false;
            }
        }
        this.game_over = false;
        return true;
        
    }

    public void play(String word){
        if(game_over != true){
            if(valid(word)) {
                words.add(word);
            }
        }
        else{
            System.out.println("Game over!\nYou can restart game to play again");
        }
    }

    public void printWords(){
        System.out.println(words);
    }

}
