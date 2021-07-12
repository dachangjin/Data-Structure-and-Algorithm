//
//  main.swift
//  26_isSubStructure
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
    var has = false
    func isSubStructure(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        if B == nil {
            return false
        }
        dfs(A) { (a: TreeNode?,stop: inout Bool) in
            if (a!.val == B!.val) {
                if compare(a, B) {
                    has = true
                    stop = true
                }
            }
        }
        return has
    }
    
    func compare(_ A: TreeNode?, _ B: TreeNode?) -> Bool {
        if A == nil && B != nil {
            return false
        }
        if A == nil && B == nil {
            return true
        }
        if B == nil && A != nil {
            return true
        }
        if A!.val == B!.val {
            return compare(A!.left, B!.left) && compare(A!.right, B!.right)
        } else {
            return false
        }
    }
    
    func dfs(_ A: TreeNode?, callback: (_ a: TreeNode,_ stop: inout Bool) -> Void) {
        if A == nil || has {
            return
        }
        var stop = false
        callback(A!, &stop)
        if stop {
            return
        }
        if A!.left != nil {
            dfs(A!.left, callback: callback)
        }
        if A!.right != nil {
            dfs(A!.right, callback: callback)
        }
    }
}

