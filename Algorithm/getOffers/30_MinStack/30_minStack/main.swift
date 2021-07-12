//
//  main.swift
//  30_minStack
//
//  Created by tommywwang on 2021/6/8.
//

import Foundation

class MinStack {

    var data = [Int]()
    var minData = [Int]()
    
    init() {

    }
    
    func push(_ x: Int) {
        data.append(x)
        if minData.isEmpty {
            minData.append(x)
        } else {
            if x > minData.last! {
                minData.append(minData.last!)
            } else {
                minData.append(x)
            }
        }
    }
    
    func pop() {
        data.removeLast()
        minData.removeLast()
    }
    
    func top() -> Int {
        return data.last!
    }
    
    func min() -> Int {
        return minData.last!
    }
}

