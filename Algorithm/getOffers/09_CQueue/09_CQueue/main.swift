//
//  main.swift
//  09_CQueue
//
//  Created by tommywwang on 2021/5/20.
//

import Foundation
// 用两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
class CQueue {
    
    var pushStack = [Int]()
    var popStack = [Int]()
    
    init() {

    }
    
    func appendTail(_ value: Int) {
        pushStack.append(value)
    }
    
    func deleteHead() -> Int {
        if popStack.isEmpty {
            while !pushStack.isEmpty {
                popStack.append(pushStack.removeLast())
            }
        }
        if popStack.isEmpty {
            return -1
        }
        return popStack.removeLast()
    }
}


