//
//  main.swift
//  29_spiralOrder
//
//  Created by tommywwang on 2021/6/8.
//

import Foundation

class Solution {
    var result = [Int]()
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        let row = matrix.count
        if row == 0 {
            return []
        }
        let column = matrix[0].count
        if column == 0 {
            return []
        }
        var start = 0
        while row > start * 2 && column > start * 2 {
            // 遍历最外圈
            printMatrixInCircle(matix: matrix,row: row,column: column,start: start)
            start += 1
        }
        return result
    }
    
    func printMatrixInCircle(matix: [[Int]],row: Int,column: Int,start: Int) {
        let endX = column - 1 - start
        let endY = row - 1 - start
        // 向右
        for index in start...endX {
            result.append(matix[start][index])
        }
        // 向下
        if start < endY {
            for index in start + 1...endY {
                result.append(matix[index][endX])
            }
        }
        // 向左
        if start < endX && start < endY {
            for index in (start...endX - 1).reversed() {
                result.append(matix[endY][index])
            }
        }
        // 向上
        if start < endY - 1 && start < endX {
            for index in (start + 1...endY - 1).reversed() {
                result.append(matix[index][start])
            }
        }
    }
}


let matrix = [[1, 2, 3, 4],
              [5, 6, 7, 8],
              [9, 10, 11, 12],
              [13, 14, 15, 16]
]

let sol = Solution()
print(sol.spiralOrder(matrix))
