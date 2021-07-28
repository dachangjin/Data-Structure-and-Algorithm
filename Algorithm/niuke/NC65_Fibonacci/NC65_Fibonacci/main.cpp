//
//  main.cpp
//  NC65_Fibonacci
//
//  Created by wangwei on 2021/7/27.
//

#include <iostream>

// NC65 斐波那契数列
// https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=188&&tqId=38580&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int pre = 0;
        int val = 1;
        int temp = 0;
        for (int i = 2; i <= n; i ++) {
            temp = val;
            val = pre + val;
            pre = temp;
        }
        return val;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
