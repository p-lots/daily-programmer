import Foundation

func willExplode(prevColor: String, currColor: String) -> Bool {
    switch (prevColor) {
    case "white":
        return currColor == "white" || currColor == "black"
    case "red":
        return currColor != "green"
    case "black":
        return currColor == "white" || currColor == "orange" || currColor == "green"
    case "orange":
        return currColor != "red" && currColor != "black"
    case "green":
        return currColor != "white" && currColor != "orange"
    case "purple":
        return currColor == "white" || currColor == "orange" || currColor == "green" || currColor == "purple"
    default:
        return false
    }
}

func main(_ input: String) -> String {
    let inputSplit = input.components(separatedBy: "\n")
    let inputZip = zip(inputSplit, inputSplit[1...])
    for (prev, curr) in inputZip {
        if willExplode(prevColor: prev, currColor: curr) {
            return "Boom"
        }
    }
    return "Bomb defused"
}

print(main("white\nred\ngreen\nwhite")) // Bomb defused
print(main("white\norange\ngreen\nwhite")) // Boom