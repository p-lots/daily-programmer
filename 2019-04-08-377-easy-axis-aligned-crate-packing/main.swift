import Cocoa
import XCTest

func fit1(_ totalLength: Int, _ totalHeight: Int, _ eachBoxLength: Int, _ eachBoxHeight: Int) -> Int {
    return (totalLength / eachBoxLength) * (totalHeight / eachBoxHeight)
}

func fit2(_ totalLength: Int, _ totalHeight: Int, _ eachBoxLength: Int, _ eachBoxHeight: Int) -> Int {
    return max(fit1(totalLength, totalHeight, eachBoxLength, eachBoxHeight), fit1(totalLength, totalHeight, eachBoxHeight, eachBoxLength))
}

class fit1Tests: XCTestCase {
    func testing(_ totalLen: Int, _ totalHeight: Int, _ boxLength: Int, _ boxHeight: Int, _ expected: Int) {
        XCTAssertTrue(fit1(totalLen, totalHeight, boxLength, boxHeight) == expected, """
            Given args \(totalLen), \(totalHeight), \(boxLength), and \(boxHeight),
            should return \(expected), instead returned \(fit1(totalLen, totalHeight, boxLength, boxHeight))
            """)
    }
    func testAverageCase() {
        let crateX = 25
        let crateY = 18
        let boxX = 6
        let boxY = 5
        let expected = 12
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testPerfectFit() {
        let crateX = 10
        let crateY = 10
        let boxX = 1
        let boxY = 1
        let expected = 100
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testAnotherAverageCase() {
        let crateX = 12
        let crateY = 34
        let boxX = 5
        let boxY = 6
        let expected = 10
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testLargeNumbers() {
        let crateX = 12345
        let crateY = 678910
        let boxX = 1112
        let boxY = 1314
        let expected = 5676
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testZeroCase() {
        let crateX = 5
        let crateY = 100
        let boxX = 6
        let boxY = 1
        let expected = 0
        testing(crateX, crateY, boxX, boxY, expected)
    }
}

class fit2Tests: XCTestCase {
    func testing(_ totalLen: Int, _ totalHeight: Int, _ boxLength: Int, _ boxHeight: Int, _ expected: Int) {
        XCTAssertTrue(fit2(totalLen, totalHeight, boxLength, boxHeight) == expected, """
            Given args \(totalLen), \(totalHeight), \(boxLength), and \(boxHeight),
            should return \(expected), instead returned \(fit2(totalLen, totalHeight, boxLength, boxHeight))
            """)
    }
    func testAverageCase() {
        let crateX = 25
        let crateY = 18
        let boxX = 6
        let boxY = 5
        let expected = 15
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testAnotherAverageCase() {
        let crateX = 12
        let crateY = 34
        let boxX = 5
        let boxY = 6
        let expected = 12
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testLargeNumbers() {
        let crateX = 12345
        let crateY = 678910
        let boxX = 1112
        let boxY = 1314
        let expected = 5676
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testOnlyFitsRotated() {
        let crateX = 5
        let crateY = 5
        let boxX = 3
        let boxY = 2
        let expected = 2
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testAnotherFitsRotated() {
        let crateX = 5
        let crateY = 100
        let boxX = 6
        let boxY = 1
        let expected = 80
        testing(crateX, crateY, boxX, boxY, expected)
    }
    func testZeroCase() {
        let crateX = 5
        let crateY = 5
        let boxX = 6
        let boxY = 1
        let expected = 0
        testing(crateX, crateY, boxX, boxY, expected)
    }
}

fit1Tests.defaultTestSuite.run()
fit2Tests.defaultTestSuite.run()
