let input = [187621, 237860461, 2187521, 18752]

func printBase62(_ n: Int) {
    let digits = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    var n_mut: Int = n
    var result = String()
    while (n_mut > 0) {
        let offset = n_mut % 62
        let index = digits.index(digits.startIndex, offsetBy: offset)
        result = String(digits[index]) + result
        n_mut /= 62
    }
    print(result)
}

input.forEach {
    printBase62($0)
}
