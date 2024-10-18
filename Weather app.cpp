#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

std::string getWeather(const std::string& city, const std::string& apiKey) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    std::string url = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

int main() {
    std::string apiKey = "YOUR_API_KEY"; // Replace with your OpenWeatherMap API key
    std::string city;

    std::cout << "Enter city name: ";
    std::getline(std::cin, city);

    std::string response = getWeather(city, apiKey);

    if (!response.empty()) {
        std::cout << "Weather data for " << city << ": " << std::endl;
        std::cout << response << std::endl; // Print the raw JSON response
    } else {
        std::cout << "Failed to fetch weather data." << std::endl;
    }

    return 0;
}
