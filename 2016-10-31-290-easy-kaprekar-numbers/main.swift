import Foundation

func isKaprekar(_ n: Int) -> Bool {
    guard !(n == 1) else { return true }
    var shift = 1, tenPow = Int(pow(10.0, Double(shift)))
    let numSq = n * n
    while tenPow < numSq {
        let first = numSq % tenPow, second = numSq / tenPow
        if first + second == n && first > 0 && second > 0 {
            return true
        }
        shift += 1
        tenPow = Int(pow(10.0, Double(shift)))
    }
    return false
}

func findKaprekar(start: Int, end: Int) {
    let _ = (start...end).filter { isKaprekar($0) }.forEach { print($0) }
}

let _ = findKaprekar(start: 1, end: 50)
let _ = findKaprekar(start: 2, end: 100)
let _ = findKaprekar(start: 101, end: 9000)
