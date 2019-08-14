import Foundation

func fib(_ n: Int) -> Int {
    if n == 0 {
        return 0
    } else if n == 1 {
        return 1
    } else if n == 2 {
        return 1
    }
    var a = 1, b = 1, c = a + b
    var i = 2
    while i < n {
        c = a + b
        a = b
        b = c
        i += 1
    }
    return c
}

func fibToDec(_ fibo: String) -> Int {
    var ret = 0, place = fibo.count, fibOfPlace = fib(place), p: Int
    for ch in fibo {
        fibOfPlace = fib(place)
        place -= 1
        p = (ch == "0" ? 0 : 1)
        ret += p * fibOfPlace
    }
    return ret
}

func decToFib(_ n: Int) -> String {
    var fibIncr = 1, placeValue = fib(fibIncr)
    var places = [Int]()
    var ret: String = ""
    while placeValue < n {
        places.insert(placeValue, at: 0)
        fibIncr += 1
        placeValue = fib(fibIncr)
    }
    var nVar = n
    for place in places {
        if nVar >= place {
            ret.append("1")
            nVar -= place
        } else {
            ret.append("0")
        }
    }
    return ret
}
