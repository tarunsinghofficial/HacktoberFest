import tkinter as tk
import requests

class WeatherApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Weather App")

        self.api_key = "YOUR_API_KEY"  # Replace with your OpenWeatherMap API key

        self.city_label = tk.Label(root, text="Enter City Name:")
        self.city_label.pack(pady=10)

        self.city_entry = tk.Entry(root)
        self.city_entry.pack(pady=10)

        self.get_weather_button = tk.Button(root, text="Get Weather", command=self.get_weather)
        self.get_weather_button.pack(pady=10)

        self.result_label = tk.Label(root, text="", wraplength=300)
        self.result_label.pack(pady=20)

    def get_weather(self):
        city = self.city_entry.get()
        if city:
            url = f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={self.api_key}&units=metric"
            response = requests.get(url)

            if response.status_code == 200:
                data = response.json()
                weather = data['weather'][0]['description']
                temperature = data['main']['temp']
                self.result_label.config(text=f"Weather: {weather}\nTemperature: {temperature}°C")
            else:
                self.result_label.config(text="City not found. Please try again.")
        else:
            self.result_label.config(text="Please enter a city name.")

if __name__ == "__main__":
    root = tk.Tk()
    weather_app = WeatherApp(root)
    root.mainloop()
