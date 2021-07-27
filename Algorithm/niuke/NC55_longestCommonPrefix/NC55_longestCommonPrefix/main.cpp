//
//  main.cpp
//  NC55_longestCommonPrefix
//
//  Created by tommywwang on 2021/7/22.
//

#include <iostream>
#include <string>
#include <vector>
// NC55 最长公共前缀
// https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=188&&tqId=38627&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking

using namespace std;

class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string result;
        int index = 0;
        string first = strs[0];
        if (first.size() == 0) return "";
        while (true) {
            bool same = true;
            if (index > first.size() - 1) {
                break;
            }
            auto ch = first[index];
            for (int i = 1; i < strs.size(); i ++) {
                string val = strs[i];
                if (index > val.size() - 1) {
                    same = false;
                    break;
                }
                if (ch != val[index]) {
                    same = false;
                }
            }
            if (same) {
                result.push_back(ch);
            } else {
                break;
            }
            index ++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
