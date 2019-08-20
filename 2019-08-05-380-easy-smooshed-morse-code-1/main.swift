import Foundation

func smorse(phrase input: String) -> String {
    let lookupDict: [Character: String] = [ "a": ".-", "b": "-...", "c": "-.-.",
                                            "d": "-..", "e": ".", "f": "..-.",
                                            "g": "--.", "h": "....", "i": "..",
                                            "j": ".---", "k": "-.-", "l": ".-..",
                                            "m": "--", "n": "-.", "o": "---",
                                            "p": ".--.", "q": "--.-", "r": ".-.",
                                            "s": "...", "t": "-", "u": "..-",
                                            "v": "...-", "w": ".--", "x": "-..-",
                                            "y": "-.--", "z": "--.."]
    return input.lowercased().map { lookupDict[$0] ?? "" }.joined()
}

print(smorse(phrase: "sos"))
print(smorse(phrase: "daily"))
print(smorse(phrase: "programmer"))
print(smorse(phrase: "bits"))
print(smorse(phrase: "three"))
