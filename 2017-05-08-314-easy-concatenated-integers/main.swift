// based on the algorithm described in this post: https://possiblywrong.wordpress.com/2017/05/16/a-number-concatenation-problem/

import Foundation

func cmp(_ lhs: String, rhs: String) -> Bool {
    let lhsConcat = lhs + rhs, rhsConcat = rhs + lhs
    return Int(lhsConcat)! < Int(rhsConcat)!
}

func smallest(_ input: [String]) -> Int {
    let inputSorted = input.sorted(by: cmp)
    return Int(inputSorted.joined())!
}

func largest(_ input: [String]) -> Int {
    let inputSortedRev = input.sorted(by: cmp).reversed()
    return Int(inputSortedRev.joined())!
}

var input = ["5", "56", "50"]
print("Smallest: \(smallest(input)) Largest: \(largest(input))")

input = ["79", "82", "34", "83", "69"]
print("Smallest: \(smallest(input)) Largest: \(largest(input))")

input = ["420", "34", "19", "71", "341"]
print("Smallest: \(smallest(input)) Largest: \(largest(input))")

input = ["17", "32", "91", "7", "46"]
print("Smallest: \(smallest(input)) Largest: \(largest(input))")
