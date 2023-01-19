public class Characters implements Sequence {
    private final String str;

    public Characters(String str) {
        this.str=str;
    }

    @Override
    public String printedSeq() {
        return this.str;
    }
}
