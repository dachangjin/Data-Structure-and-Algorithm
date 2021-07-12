//
//  main.cpp
//  NC17_getLongestPalindrome
//
//  Created by wangwei on 2021/7/13.
//

#include <iostream>

using namespace std;
// NC17 最长回文子串
// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=188&&tqId=38608&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 遍历每个字符，以此字符为回文串中心，计算最大长度。中心分为奇数中心(aba)和偶数中心(abba)
class Solution {
public:
    int getLongestPalindrome(string A, int n) {
        if (n <= 1) {
            return n;
        }
        int start = 0;
        int end = n - 1;
        int maxCount = 0;
        for (int i = 0; i < n - 1; i ++) {
            int count = max(getLength(A, start, end, i, i), getLength(A, start, end, i, i + 1));
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
    
    int getLength(string &str, int start, int end, int left, int right) {
        int count = right - left + 1;
        while(left >= start && right <= end) {
            if (str[left] == str[right]) {
                count = right - left + 1;
                left--;
                right++;
            } else {
                break;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string str = "abc1234321ab";
    sol.getLongestPalindrome(str, 12);
    return 0;
}
