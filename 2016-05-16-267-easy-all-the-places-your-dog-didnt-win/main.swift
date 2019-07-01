import Foundation

func otherPlaces(forPlace place: Int) -> String {
    let suffixes: [String] = ["st", "nd", "rd"]
    let ret = (1...100).map { (i: Int) -> String in
        if i == place {
            return ""
        }
        let mod = i % 10
        var n = String(i)
        if (mod >= 1 && mod <= 3) && !(i >= 11 && i <= 13) {
            n.append(suffixes[mod - 1])
        } else {
            n.append("th")
        }
        return n
    }
    return ret.filter { !$0.isEmpty }.joined(separator: ", ")
}
