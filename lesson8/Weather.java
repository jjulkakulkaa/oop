public class Weather{
    private final Forecast forecast;
    private final float temperature;
    public Weather(Forecast f, float t) {
        this.forecast = f;
        this.temperature = t;
    }
    
    public Weather forecastedWeather(){
        return new Weather(forecast, forecast.forecast());
    }
    @Override

    public String toString(){
        return String.valueOf(temperature);
    }
}
