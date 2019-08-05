import Foundation

func main(_ input: String) -> String {
    let inputSplit = input.components(separatedBy: "\n").map { $0.components(separatedBy: " ") }
    let goldiWeight = Int(inputSplit[0][0])!, maxTolerableTemp = Int(inputSplit[0][1])!
    var ret = [Int]()
    for i in 1..<inputSplit.count {
        let currWeight = Int(inputSplit[i][0])!, currTemp = Int(inputSplit[i][1])!
        if currWeight >= goldiWeight && currTemp <= maxTolerableTemp {
            ret.append(i)
        }
    }
    return ret.map { String($0) }.joined(separator: " ")
}

print(main("100 80\n30 50\n130 75\n90 60\n150 85\n120 70\n200 200\n110 100"))
