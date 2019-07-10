import Foundation

let weekdays = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]

func calculateDay(forYear year: Int, forMonth month: Int, forDay day: Int) -> String {
    var m = month, y = year
    if m < 3 {
        m += 12
        y -= 1
    }
    let k = y % 100, j = y / 100
    let index = (day + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) + (5 * j)) % 7
    return weekdays[index]
}