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
 /*
 https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 剑指 Offer 32 - II. 从上到下打印二叉树 II
 层序遍历，当一层遍历完后重置数组和count
 */
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
                results.append(result)
                result.removeAll()
            }
        }
        return results
    }
}

