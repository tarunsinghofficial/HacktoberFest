// Function to toggle temperature units (Celsius/Fahrenheit)
function toggleTemperatureUnit() {
    const temperatureElement = document.getElementById("showWeather");
    const unitToggle = document.getElementById("unitToggle");

    unitToggle.addEventListener("change", function () {
        const currentText = temperatureElement.textContent;
        const currentUnit = unitToggle.checked ? "°F" : "°C";
        const convertedText = convertTemperature(currentText, currentUnit);
        temperatureElement.textContent = convertedText;
    });
}

// Function to convert temperature units
function convertTemperature(text, currentUnit) {
    const temperature = parseInt(text);
    if (currentUnit === "°C") {
        return Math.round((temperature * 9/5) + 32) + "°F";
    } else {
        return Math.round((temperature - 32) * 5/9) + "°C";
    }
}

// Function to display weather details
function displayWeather(data) {
    const temp = Math.round(data.main.temp - 273.15);
    const humidity = data.main.humidity;
    const windSpeed = data.wind.speed;
    const weatherIcon = data.weather[0].icon;

    const weatherIconElement = document.getElementById("weather-icon");
    const showWeatherElement = document.getElementById("showWeather");

    weatherIconElement.src = `http://openweathermap.org/img/w/${weatherIcon}.png`;
    showWeatherElement.textContent = `Temperature: ${temp}°C, Humidity: ${humidity}%, Wind Speed: ${windSpeed} m/s`;
    document.getElementById("weather-details").classList.remove("hidden");
    toggleTemperatureUnit();
}

// Function to get weather data
function getWeather() {
    const city = document.getElementById("city").value;
    const apiKey = "YOUR_API_KEY"; // Replace with your actual API key

    fetch(`https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}`)
        .then(response => response.json())
        .then(data => {
            displayWeather(data);
        })
        .catch(error => {
            alert("City not found. Please try again.");
        });
}

// Function to get weather data based on geolocation
function getWeatherByLocation() {
    if (navigator.geolocation) {
        navigator.geolocation.getCurrentPosition(function (position) {
            const latitude = position.coords.latitude;
            const longitude = position.coords.longitude;
            const apiKey = "YOUR_API_KEY"; // Replace with your actual API key

            fetch(`https://api.openweathermap.org/data/2.5/weather?lat=${latitude}&lon=${longitude}&appid=${apiKey}`)
                .then(response => response.json())
                .then(data => {
                    displayWeather(data);
                })
                .catch(error => {
                    alert("Failed to fetch weather data for your location.");
                });
        });
    } else {
        alert("Geolocation is not supported by your browser.");
    }
}

document.getElementById("getWeather").addEventListener("click", getWeather);
document.getElementById("getLocation").addEventListener("click", getWeatherByLocation);

// Initial call to get weather based on geolocation
getWeatherByLocation();
