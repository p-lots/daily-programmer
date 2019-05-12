import Foundation

func makeDictionaryFromPhrase(phrase text: String) -> [Character: Int] {
    var ret: [Character: Int] = [:]
    let _ = text.lowercased().forEach { (ch: Character) in 
        switch ch {
        case "a"..."z":
            if let currCount = ret[ch] {
                ret[ch] = currCount + 1
            } else {
                ret.updateValue(1, forKey: ch)
            }
        default:
            return
        }
    }
    return ret
}

func isAnagram(phrase text: String) -> String {
    let phrases = text.components(separatedBy: " ? ")
    let first = makeDictionaryFromPhrase(phrase: phrases[0]), second = makeDictionaryFromPhrase(phrase: phrases[1])
    return "\(phrases[0]) is \(first == second ? "" : "NOT ")an anagram of \(phrases[1])"
}

let testPhrases = ["\"wisdom\" ? \"mid sow\"",
    "\"Seth Rogan\" ? \"Gathers No\"",
    "\"Reddit\" ? \"Eat Dirt\"",
    "\"Schoolmaster\" ? \"The classroom\"",
    "\"Astronomers\" ? \"Moon starer\"",
    "\"Vacation Times\" ? \"I'm Not as Active\"",
    "\"Dormitory\" ? \"Dirty Rooms\""]
for phrase in testPhrases {
    print(isAnagram(phrase: phrase))
}