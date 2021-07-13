//
//  main.cpp
//  NC1_solve
//
//  Created by wangwei on 2021/7/14.
//

#include <iostream>

using namespace std;

// NC1 大数加法
// https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=188&&tqId=38569&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 找出较长的字符串，将较短的char加到较长的里面，注意进位和char的加法和转换

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        int sLength = (int)s.length();
        int tLength = (int)t.length();
        string longString = s;
        string shortString = t;
        int longLength = sLength;
        int shortLength = tLength;
        if (tLength > sLength) {
            longString = t;
            shortString = s;
            longLength = tLength;
            shortLength = sLength;
        }
        bool more = false;
        while (longLength > 0) {
            char shortChar = '0';
            if (shortLength > 0) {
                shortChar = shortString[shortLength - 1];
            }
            int offset = (longString[longLength - 1] - '0') + (shortChar - '0') + more;
            longString[longLength - 1] = '0' + offset % 10;
            more = offset >= 10;
            shortLength--;
            longLength--;
        }
        if (more) {
            longString.insert(longString.begin(), '1');
        }
        return longString;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    sol.solve("11", "111");
    return 0;
}
