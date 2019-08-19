import Foundation

func makeTimeWords(forTime time: Int, isHours: Bool) -> String {
    let ones = ["oh", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine"]
    let tweensTeens = ["ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    let tens = ["twenty", "thirty", "forty", "fifty"]
    if time == 0 { return isHours ? "twelve" : "" }
    else if time < 10 { return "\(isHours ? "" : "oh ")\(ones[time])" }
    else if time < 20 { return tweensTeens[time % 10] }
    else { return tens[time / 10 - 2] + (time % 10 == 0 ? "" : " \(ones[time % 10])") }
}

func speakTime(forTime input: String) -> String {
    let colonIdx = input.firstIndex(of: ":") ?? input.endIndex
    var hours = Int(String(input[input.startIndex..<colonIdx])) ?? 0
    let afterColonIdx = input.index(after: colonIdx)
    let minutes = Int(String(input[afterColonIdx...])) ?? 0
    let pastNoon = hours >= 12
    hours = (hours >= 12 ? hours == 12 ? 12 : hours % 12 : hours)
    let hoursStr = makeTimeWords(forTime: hours, isHours: true)
    let minsStr = makeTimeWords(forTime: minutes, isHours: false)
    return "It's \(hoursStr) \(minsStr)\(!minsStr.isEmpty ? " " : "")\(pastNoon ? "pm" : "am")"
}
