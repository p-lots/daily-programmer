func scrabble(tiles: String, word: String) -> Bool {
    guard tiles.count >= word.count else { return false }
    var tilesCopy = tiles, wordCopy = word
    for ch in word {
        if let tilesIdx = tilesCopy.firstIndex(of: ch) {
            tilesCopy.remove(at: tilesIdx)
            let wordIdx = wordCopy.firstIndex(of: ch)!
            wordCopy.remove(at: wordIdx)
        } else {
            if let qPos = tilesCopy.firstIndex(of: "?") {
                tilesCopy.remove(at: qPos)
                let wordIdx = wordCopy.firstIndex(of: ch)!
                wordCopy.remove(at: wordIdx)
            } else {
                return false
            }
        }
    }
    return wordCopy.isEmpty
}

print(scrabble(tiles: "ladilmy", word: "daily")) // true
print(scrabble(tiles: "eerriin", word: "eerie")) // false
print(scrabble(tiles: "orrpgma", word: "program")) // true
print(scrabble(tiles: "orppgma", word: "program")) // false

print(scrabble(tiles: "pizza??", word: "pizzazz")) // true
print(scrabble(tiles: "piizza?", word: "pizzazz")) // false
print(scrabble(tiles: "a??????", word: "program")) // true
print(scrabble(tiles: "b??????", word: "program")) // false