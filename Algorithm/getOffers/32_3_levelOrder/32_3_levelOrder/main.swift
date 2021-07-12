//
//  main.swift
//  32_1_levelOrder
//
//  Created by tommywwang on 2021/6/8.
//

import Foundation


public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}
 
class Solution {
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        if root == nil {
            return []
        }
        var results = [[Int]]()
        var queue = [TreeNode]()
        queue.append(root!)
        var count = 1
        var result = [Int]()
        var odd = true
        while !queue.isEmpty {
            let node = queue.removeFirst()
            count -= 1
            result.append(node.val)
            if node.left != nil {
                queue.append(node.left!)
            }
            if node.right != nil {
                queue.append(node.right!)
            }
            if count == 0 {
                count = queue.count
                if odd {
                    results.append(result)
                } else {
                    results.append(result.reversed())
                }
                odd = !odd
                result.removeAll()
            }
        }
        return results
    }
}

