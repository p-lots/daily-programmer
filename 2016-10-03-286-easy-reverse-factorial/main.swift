import Foundation

/**
 reverseFactorial: finds the factorial base of a number.
 For example, reverseFactorial(120) = 5
 Returns 0 if no base is found.
 */

func reverseFactorial(_ n: Int) -> Int {
    var incr = 2, modBool = true, nVar = n
    while nVar > 0 {
        modBool = nVar % incr == 0
        nVar /= incr
        if nVar == 1 && modBool {
            return incr
        }
        incr += 1
    }
    return nVar
}
