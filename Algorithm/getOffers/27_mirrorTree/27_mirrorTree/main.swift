//
//  main.swift
//  27_mirrorTree
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
    func mirrorTree(_ root: TreeNode?) -> TreeNode? {
        if root == nil {
            return root
        }
        revertTree(root)
        return root
    }
    func revertTree(_ node: TreeNode?) {
        let left = node!.left
        node!.left = node!.right
        node!.right = left
        if node!.left != nil {
            revertTree(node!.left)
        }
        if node!.right != nil {
            revertTree(node!.right)
        }
    }
}

