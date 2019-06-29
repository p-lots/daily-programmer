import Foundation

func decimalToFactorial(fromDecimal dec: Int) -> String {
    var n = dec, divisor = 1, rem = 0
    var retArr = [String]()
    while n > 0 {
        rem = n % divisor
        retArr.append(String(rem))
        n /= divisor
        divisor += 1
    }
    return Array(retArr.reversed()).joined()
}

func makePermutation(fromNumbers numbers: [Int], fromFac fac: String) -> [Int] {
    var ret = [Int]()
    var mutInput = numbers
    for ch in fac {
        let n = Int(String(ch))!
        ret.append(mutInput[n])
        mutInput.remove(at: n)
    }
    return ret
}

let test1 = Array((0..<6))
let result1 = makePermutation(fromNumbers: test1, fromFac: decimalToFactorial(fromDecimal: 239))
print(result1)
let test2 = Array((0..<7))
let result2 = makePermutation(fromNumbers: test2, fromFac: decimalToFactorial(fromDecimal: 3239))
print(result2)
