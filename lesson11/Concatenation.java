public class Concatenation implements Sequence {
    private final Sequence sequence1;
    private final Sequence sequence2;

    @Override
    public String printedSeq(){
        return this.sequence1.printedSeq() + this.sequence2.printedSeq();
    }

    public Concatenation(Sequence firstSequence, Sequence secondSequence) {
        this.sequence1= firstSequence;
        this.sequence2 = secondSequence;
    }
}
