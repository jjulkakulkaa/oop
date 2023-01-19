public class Main {
    public static void main(String[] args) {
        String string1 = "HELLo WORLd";
        String string2 = "CAT caT cat CAT CAT";

        System.out.println(
                new Concatenation(
                        new Characters(string1),
                        new Substring(
                                new LowerCased(new Characters(string2))
                                , 6, 17)
                                ).printedSeq());
    }
}
