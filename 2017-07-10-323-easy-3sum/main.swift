import Foundation

func threeSum(_ input: String) -> [[Int]] {
    let inputSplit = input.components(separatedBy: CharacterSet.whitespaces).compactMap { Int(String($0)) }.sorted()
    var results = Set<Array<Int>>()
    var ret = [[Int]]()
    for i in 0..<(inputSplit.count - 3) {
        let a = inputSplit[i]
        var start = i + 1, end = inputSplit.count - 1
        while start < end {
            let b = inputSplit[start], c = inputSplit[end]
            if a + b + c == 0 {
                let tempArr = [a, b, c]
                if !results.contains(tempArr) {
                    ret.append(tempArr)
                    results.insert(tempArr)
                }
                end -= 1
            } else if a + b + c > 0 {
                end -= 1
            } else {
                start += 1
            }
        }
    }
    return ret
}
