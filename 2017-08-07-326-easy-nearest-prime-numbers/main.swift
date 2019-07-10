import Foundation

func isPrime(_ n: Int) -> Bool {
    guard n % 2 == 1 else { return false }
    guard n % 3 != 0 else { return false }
    let squareRoot = Int(sqrt(Double(n)))
    for i in 5...squareRoot {
        if n % i == 0 { return false }
    }
    return true
}

func findNearestPrime(for n: Int) -> String {
    guard !isPrime(n) else { return "\(n) is prime." }
    var down = n, up = n
    while !isPrime(down) { down -= 1 }
    while !isPrime(up) { up += 1 }
    return "\(down) < \(n) < \(up)"
}
