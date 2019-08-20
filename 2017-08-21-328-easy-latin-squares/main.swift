import Foundation

func isLatinSquare(forLength len: Int, forSquare input: String) -> Bool {
    let inputSplit = input.components(separatedBy: " ").compactMap { Int(String($0)) }
    var iter = 0
    var grid = [[Int]]()
    for _ in 0..<len {
        var row = [Int]()
        for _ in 0..<len {
            row.append(inputSplit[iter])
            iter += 1
        }
        grid.append(row)
    }
    var hasNumArr = Array(repeating: false, count: len), hasAll = true
    for i in 0..<len {
        for j in 0..<len {
            let numAt = grid[i][j]
            hasNumArr[numAt - 1] = true
        }
        for j in 0..<len {
            hasAll = hasNumArr[j]
            if !hasAll { break }
        }
        if !hasAll { break }
    }
    if !hasAll { return hasAll }
    hasNumArr = Array(repeating: false, count: len)
    for i in 0..<len {
        for j in 0..<len {
            let numAt = grid[j][i]
            hasNumArr[numAt - 1] = true
        }
        for j in 0..<len {
            hasAll = hasNumArr[j]
            if !hasAll { break }
        }
        if !hasAll { break }
    }
    return hasAll
}
