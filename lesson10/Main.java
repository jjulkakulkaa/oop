public class Main {
    public static void main(String[] args) {
        Shiritori shiritori = new Shiritori();
        shiritori.play("blanket");
        shiritori.play("taurus");
        shiritori.play("siren");
        shiritori.printWords();
        shiritori.restart();

        shiritori.play("apple");
        shiritori.play("banana");
        shiritori.restart();

        shiritori.play("cat");
        shiritori.play("talk");
        shiritori.play("talk");
        shiritori.play("talk");
        shiritori.play("talk");

    }
}
