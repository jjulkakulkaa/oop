public class App {
    public static void main(String[] args){
        Forecast forecast = new Forecast.Fake();
        Weather weather = new Weather(forecast, 30);
        Weather forecastedWeather = weather.forecastedWeather();
        assert "20.00".equals(forecastedWeather.toString());
    }
}
