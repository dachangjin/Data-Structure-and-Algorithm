//
//  main.cpp
//  NC103_solve
//
//  Created by wangwei on 2021/7/12.
//

#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        int start = 0;
        int end = (int)str.length() - 1;
        while (end > start) {
            swap(str[start++], str[end--]);
        }
        return str;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
