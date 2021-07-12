//
//  main.swift
//  31_validateStackSequences
//
//  Created by tommywwang on 2021/6/8.
//

import Foundation

class Solution {
    // 按出栈
    func validateStackSequences(_ pushed: [Int], _ popped: [Int]) -> Bool {
        var stack = [Int]()
        var pop = popped
        var push = pushed
        while !pop.isEmpty {
            let val = pop.removeFirst()
            let stackVal = stack.last
            if stackVal != nil && stackVal == val {
                stack.removeLast()
                continue
            }
            while !push.isEmpty {
                let num = push.removeFirst()
                if val != num {
                    stack.append(num)
                } else {
                    break
                }
            }
        }
        return pop.isEmpty && stack.isEmpty
    }
    
    func validateStackSequences1(_ pushed: [Int], _ popped: [Int]) -> Bool {
        var stack = [Int]()
        var i = 0
        for num in pushed {
            // 先入栈
            stack.append(num)
            // 符合出栈数组则出栈，否则一直入栈
            while !stack.isEmpty && stack.last! == popped[i] {
                _ = stack.popLast()
                i += 1
            }
        }
        return stack.isEmpty
    }
}

