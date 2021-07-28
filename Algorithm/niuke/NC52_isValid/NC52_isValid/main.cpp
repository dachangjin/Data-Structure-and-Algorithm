//
//  main.cpp
//  NC52_isValid
//
//  Created by wangwei on 2021/7/27.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// NC52 括号序列
// https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2?tpId=188&&tqId=38573&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 使用栈
class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i ++) {
            char chr = s[i];
            if (chr == '{' || chr == '[' || chr == '(') {
                stk.push(chr);
            } else if (chr == '}') {
                if (stk.empty() || stk.top() != '{')  return false;
                stk.pop();
            } else if (chr == ']') {
                if (stk.empty() || stk.top() != '[')  return false;
                stk.pop();
            } else if (chr == ')') {
                if (stk.empty() || stk.top() != '(')  return false;
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
        // write code here
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
