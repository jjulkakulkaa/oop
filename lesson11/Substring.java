public class Substring implements Sequence{
    private final Sequence seq;
    private final int start;
    private final int end;

    @Override
    public String printedSeq() {
        return this.seq.printedSeq().substring(start, end);
    }

    public Substring(Sequence seq, int start, int end) {
        this.seq = seq;
        this.start = start;
        this.end = end;
    }
}
