import Foundation

func yahtzeeUpper(_ dicerolls: [Int]) -> Int {
    var ret = 0
    for n in 1...6 {
        let score = dicerolls.filter { $0 == n }.count * n
        ret = max(ret, score)
    }
    return ret
}

print(yahtzeeUpper([2, 3, 5, 5, 6])) // => 10
print(yahtzeeUpper([1, 1, 1, 1, 3])) // => 4
print(yahtzeeUpper([1, 1, 1, 3, 3])) // => 6
print(yahtzeeUpper([1, 2, 3, 4, 5])) // => 5
print(yahtzeeUpper([6, 6, 6, 6, 6])) // => 30