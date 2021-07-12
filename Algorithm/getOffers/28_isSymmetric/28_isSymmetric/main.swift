//
//  main.swift
//  28_isSymmetric
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
    func isSymmetric(_ root: TreeNode?) -> Bool {
        if root == nil {
            return true
        }
        return same(n1: root!.left, n2: root!.right)
    }
    
    func same(n1: TreeNode?, n2: TreeNode?) -> Bool {
        if n1 == nil && n2 == nil {
            return true
        }
        if n1 == nil || n2 == nil || n1!.val != n2!.val {
            return false
        }
        return same(n1: n1!.left, n2: n2!.right) && same(n1: n1!.right, n2: n2!.left)
    }
}

