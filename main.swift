//
//  main.swift
//  bsq
//
//  Created by Demirhan Mehmet Atabey on 1.08.2023.
//

import Foundation

struct Point {
  let x: Int
  let y: Int
}

struct Square {
  let topLeft: Point
  let size: Int
}

class BSQ {
  var map: [[Character]] = []
  var width: Int = 0
  var height: Int = 0
  
  @discardableResult func readMapFromFile(_ filePath: String) -> Bool {
    let contents = """
..o.....
........
........
oo...o..
..o.....
........
.o......
.o......
"""
    let lines = contents.components(separatedBy: .newlines)
    if lines.count < 2 {
      print("Map error")
      return false
    }
    
    width = lines[1].count
    height = lines.count - 1
    
    map = Array(repeating: Array(repeating: Character(" "), count: width), count: height)
    
    for i in 0..<height {
      let line = Array(lines[i])
      if line.count != width {
        print("Map error")
        return false
      }
      map[i] = line
    }
    
//    print(map)
    return true
  }
  
  func findLargestSquare() -> Square? {
    var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: width), count: height)
    
    var maxSize = 0
    var maxPoint = Point(x: 0, y: 0)
    
    for i in 0..<height {
      for j in 0..<width {

        if map[i][j] == "o" {
          dp[i][j] = 0
        } else {
          let left = j > 0 ? dp[i][j - 1] : 0
          let top = i > 0 ? dp[i - 1][j] : 0
          let topLeft = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0
          
          dp[i][j] = min(left, top, topLeft) + 1
          
          if dp[i][j] > maxSize {
            maxSize = dp[i][j]
            maxPoint = Point(x: j - maxSize + 1, y: i - maxSize + 1)
          }
        }
      }
    }

    
    if maxSize > 0 {
      return Square(topLeft: maxPoint, size: maxSize)
    }
    
    return nil
  }
  
  func printMapWithSquare(_ square: Square?) {
    for i in 0..<height {
      for j in 0..<width {
        if let square = square {
          if i >= square.topLeft.y && i < square.topLeft.y + square.size && j >= square.topLeft.x && j < square.topLeft.x + square.size {
            print("x", terminator: "")
          } else {
            print("\(map[i][j])", terminator: "")
          }
        } else {
          print("\(map[i][j])", terminator: "")
        }
      }
      print()
    }
  }
  
  func run() {
    let _ = readMapFromFile("")
    let square = findLargestSquare()
    printMapWithSquare(square)
    print()
  }
}

let bsq = BSQ()
bsq.run()
