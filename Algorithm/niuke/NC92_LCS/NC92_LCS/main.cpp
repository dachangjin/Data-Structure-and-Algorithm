//
//  main.cpp
//  NC92_LCS
//
//  Created by tommywwang on 2021/7/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        int s1Length = (int)s1.length();
        int s2Length = (int)s2.length();
        string dp[s1.length() + 1][s1.length() + 1];
        dp[0][0] = "";
        dp[0][1] = "";
        dp[1][0] = "";
        for (int i = 1; i <= s1Length; i ++) {
            for (int j = 1; j <= s2Length; j ++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + (s1[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }
        return dp[s1Length][s2Length] == "" ? "-1" : dp[s1Length][s2Length];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
