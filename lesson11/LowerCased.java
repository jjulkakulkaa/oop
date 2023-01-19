public class LowerCased implements Sequence {
    private final Sequence seq;

    @Override
    public String printedSeq(){
        return this.seq.printedSeq().toLowerCase();
    }

    public LowerCased(Sequence seq) {
        this.seq = seq;
    }

}
