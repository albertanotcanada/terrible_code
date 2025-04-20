
#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

int main() {
    std::string apiKey = "your_api_key"; // Replace with your actual API key
    std::vector<std::string> cities = {
        "Albany", "Atlanta", "Austin", "Baltimore", "Boston", "Chicago", "Cleveland", "Dallas", "Denver", "Detroit",
        "Houston", "Indianapolis", "Jacksonville", "Las Vegas", "Los Angeles", "Miami", "Minneapolis", "Nashville",
        "New Orleans", "New York", "Orlando", "Philadelphia", "Phoenix", "Pittsburgh", "Portland", "San Antonio",
        "San Diego", "San Francisco", "Seattle", "Washington"
    };

    for (const auto& city : cities) {
        // Make an HTTP GET request to the OpenWeatherMap API
        std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;
        cpr::Response response = cpr::Get(cpr::Url{url});

        if (response.status_code == 200) {
            // Parse the JSON response
            auto jsonResponse = nlohmann::json::parse(response.text);
            std::string weatherDescription = jsonResponse["weather"][0]["description"];
            double temperature = jsonResponse["main"]["temp"] - 273.15; // Convert from Kelvin to Celsius

            // Output the weather information
            std::cout << "Weather in " << city << ": " << weatherDescription << std::endl;
            std::cout << "Temperature: " << temperature << "°C" << std::endl;
        } else {
            std::cerr << "Failed to fetch weather data for " << city << ". HTTP Status Code: " << response.status_code << std::endl;
        }
    }

    return 0;
}

