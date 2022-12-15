public interface Forecast {
    float forecast();
    final class Fake implements Forecast{
        @Override
        public float forecast(){
            return (float)20.00;
        }
    }

}