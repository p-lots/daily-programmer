import Foundation

func degreesToRadians(_ input: Double) -> Double {
    return input * (Double.pi / 180.0)
}

func radiansToDegrees(_ input: Double) -> Double {
    return input * (180.0 / Double.pi)
}

func celsiusToFahrenheit(_ input: Double) -> Double {
    return input * (9.0 / 5.0) + 32.0
}

func fahrenheitToCelsius(_ input: Double) -> Double {
    return (input - 32.0) * 5.0 / 9.0
}

func celsiusToKelvin(_ input: Double) -> Double {
    return input + 273.15
}

func fahrenheitToKelvin(_ input: Double) -> Double {
    return (input + 459.67) * 5.0 / 9.0
}

func kelvinToCelsius(_ input: Double) -> Double {
    return input - 273.15
}

func kelvinToFahreheit(_ input: Double) -> Double {
    return input * (9.0 / 5.0) - 459.67
}

func convert(_ input: String) -> Double {
    let conversionLookupTable: [String: (Double) -> Double] = [
        "dr": degreesToRadians, "rd": radiansToDegrees, "cf": celsiusToFahrenheit,
        "fc": fahrenheitToCelsius, "ck": celsiusToKelvin, "fk": fahrenheitToKelvin,
        "kc": kelvinToCelsius, "kf": kelvinToFahreheit
    ]
    let convStrIndex = input.firstIndex(where: { CharacterSet.lowercaseLetters.contains($0.unicodeScalars.first!) })!
    let convStr = String(input[convStrIndex...])
    let units = Double(String(input[..<convStrIndex]))!
    var ret = 0.0
    if let convFunc = conversionLookupTable[convStr] {
        ret = convFunc(units)
    }
    return ret
}
