import Foundation

func largestDigit(_ n: Int) -> Int {
    let nArr = String(n).compactMap { Int(String($0)) }
    if let ret = nArr.max() {
        return ret
    }
    return -1
}

func descendingDigits(_ n: Int) -> Int {
    var nArr = String(n).compactMap { Int(String($0)) }
    while nArr.count < 4 {
        nArr.insert(0, at: 0)
    }
    return nArr.sorted(by: >).reduce(0) { acc, n in acc * 10 + n }
}

func kaprekar(_ n: Int) -> Int {
    var ret = 0
    if !kaprekarCheck(n) {
        return ret
    }
    var nVar = n
    while nVar != 6174 {
        let fwd = descendingDigits(nVar)
        let rev = String(nVar).compactMap { Int(String($0)) }.sorted(by: <).reduce(0) { acc, n in acc * 10 + n }
        nVar = fwd - rev
        ret += 1
    }
    return ret
}

func kaprekarCheck(_ n: Int) -> Bool {
    if n == 6174 {
        return false
    }
    let nArr = String(n).compactMap { Int(String($0)) }
    let first = nArr[0]
    var uniqueCount = 1
    for i in 1..<nArr.count {
        let second = nArr[i]
        if first != second {
            uniqueCount += 1
        }
    }
    return uniqueCount > 1
}
