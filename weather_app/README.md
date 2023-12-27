# Weather App

## Overview

The Weather App is a simple iOS application built in Swift that allows users to check the current weather conditions for a given location. It provides real-time weather data, including temperature, humidity, wind speed, and more.

## Photo
<img src="https://github.com/j-balkovec/Projects/blob/main/WeatherApp/SShot.PNG" height="400" width="200">



## Features

- **Current Weather:** Get the latest information about the current weather conditions in your location.
- **Forecast:** View a 7-day weather forecast to plan your activities ahead.
- **Location-based:** The app uses the device's location services to automatically fetch weather data for the user's current location.
- **Custom Location:** Users can also search for weather information in other locations by entering the city name.

## Requirements

- iOS 17.0+
- Xcode 15.0+
- Swift 5.0+

## Installation

1. Clone the repository:
    
    ```bash
    git clone https://github.com/j-balkovec/Projects/WeatherApp.git
    ```
2. Open the project in Xcode:
    ```
    cd weather-app
    open WeatherApp.xcodeproj
    ```
## Dependencies

The Weather App relies on the following third-party libraries:

`Alamofire`: Used for making network requests.
`SwiftyJSON`: Simplifies JSON parsing.

To install these dependencies, use CocoaPods or Swift Package Manager.

## Configuration

To customize the app for your use, you may need to configure API keys for the weather data provider. Open the WeatherService.swift file and update the apiKey property with your API key.
```
static let apiKey = "YOUR_API_KEY"
```

## Contributing

If you would like to contribute to the project, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make changes and commit them.
4. Submit a pull request.

## License

This Weather App is open source and available under the [MIT License].
Feel free to use, modify, and distribute this code for your projects.


Remember to replace placeholder values such as `path/to/your/logo.png`, `path/to/screenshot1.png`, `path/to/screenshot2.png`, and `YOUR_API_KEY` with the actual paths and API key. Customize the content as needed for your specific app.
