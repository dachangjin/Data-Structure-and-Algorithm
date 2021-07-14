//
//  main.cpp
//  NC92_LCS
//
//  Created by tommywwang on 2021/7/14.
//

#include <iostream>
#include <vector>

using namespace std;
// NC92 最长公共子序列-II
// https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11?tpId=188&&tqId=38551&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 动态规划
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    // dp[i][j] 为以s1[i] s2[j]结尾的最长公共子串。由于dp中存放的是字符串，空间有点爆表了
    string LCS1(string s1, string s2) {
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
    
    // dp[i][j] 为以s1[i] s2[j]结尾的最长公共子串的长度。然后再反过来推出最长的字符串
    string LCS(string s1, string s2) {
        int s1Length = (int)s1.length();
        int s2Length = (int)s2.length();
        int dp[s1.length() + 1][s1.length() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        
        for (int i = 1; i <= s1Length; i ++) {
            for (int j = 1; j <= s2Length; j ++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        if (dp[s1Length][s2Length] == 0) {
            return "-1";
        }
        string result;
        int i = s1Length;
        int j = s2Length;
        while (i > 0 && j > 0) {
            // 相同就加入result中
            if (s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                i--;
                j--;
            } else {
                // 相反递推
                if (dp[i - 1][j] > dp[i][j-1]) {
                    i --;
                } else {
                    j --;
                }
            }
        }
        reverse(result.begin(), result.end());
        return result.length() ? result : "-1";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    string length = sol.LCS("JGIHa76X06Mx330MtfiNafgpQfj0sJVop2nrMb7Gx2i3RIA72UIIXWA2NoPjRN1jwMNVawJrsn3obxhKDINaHLMJT4JnxHo43xf7CUjh77Pae1UUi3GIiH4ponfV6HRzbk1pp7ehACa2ephI6kVb46FR0irx4tVmDjpks0VRonMe3keeVJ83Z8N2eUJoIN4WGd0GQWDn1jnM4MsojgFIbXs7Nu3jnFHrWi3fbNiWRIfxUzr23yb4NGrj1XhkJMbj42DXeUAeifpMNHFx6AGu962ATDV3kkJfAjeJj4Xs0oxq4pGxm2xrrZf4MGJfin4boMzhNFrYGf3sRpafUXIOUAkfU7bas2pHkViihorlhwd7njxefBMpnCWR4rqX76GrW27R1HIna09Dhkfirtpn1F6A2Gr4rbc3MFrtzVrfCxntVh3nHra0I4xNaWi7bVphjoIiGWhIzoiAfkMMdzyVfQoHAw4Gr4M6CC4TGar118GhJS6GfR6HIopGDpzxmkS11nC4sXxoeaA77bAzWsJJ9W10Xnae4Vk2zIHUxUVJiGr62J1B45NhHp41A726WqJNaI7UbjRr1GkX0jChibFW6Chn1i3boIBpfVAf4Wa37sX4J9CjWrhG174rXixexFs9JAn3NVWGnWokWnCs1jfRI36xiIWfCXUj7bsbKeJtpxri2AzsskRJhUVzaNNA2iHR6iGHI0er34n6axnbrWis6o4H70VipGy7CH5fTqJakNI3MnuRvqbskBX8kXHpAbVNHN07ooGnrPrUCItRoRH1bco4VUVXrxHIoqM6ahzjGFh1h37ibpoXhX00b3iGaxG6XfVVeAVJoKfFVieI6zWrairpCRNRniVr0HWGKNWFRxTxRRGN1xBNXgrreeaNFWpz7637joijexGRAspXnRnQoU6bab4R7afC3C1k3NxiRX72kjARUGeMRMaR6k0wNxHj2kzHWH0XjtkrxJM0IhU4eaohWF8UCpCGjhXeAUse1piLGFl7x2J3VkVVnMr6UhR9nzUF473TNFXip35j3sR4nNws4hzU7p6IWWIR4Nf2Q3yFRf1RUz2sRhJG1aSxaffQAz7apoxIXJaX0nXa6Ffj3IkV0zxjUTVdkGUx", "K8dqDTE5Z5lgtvv9m9Qg8ugmYu9qDwaDgtKl5vylPLyLPLwlKETQ8v5YvTMwBKQKyT3Pl8tuKvmqgwEOQlx5vZLKgT5ABdw7yqPdZPmcuugDqOZwtNYgLcwBgTrEqlhKummLgmZDcHwcmm5LvmTvDLxlQyttK7DPgTucUq5DdlmKiSE8mBt93tOgTQKTGhCPBDudBLmgPtLvYTuydmcqD5EtEQZmwmmBLc5SEd89TyOlDYdwol8lDZl8cucOB9ggldm5QZPuPl58qttLQDP1TELyMtgggdutTuy9wZL8YwZqvw8EtgqqYK5LvK4yYwjBXSODNcDQHmEE8uvdZP9lQutwPcYyvQSwTLD8PcdgKE5DE89ZqdPBycc5wmQgLZT2B8ZE9wBzE58P9EOqYLTw5OUrSlTQPOqOTqtZBvwOv5yDwSddQY9BTqT8DY59BYQy9gPEl9gLZtEdvLuLByOB9S79DgrBtvZQqmyBr98y9tqc5cTcvP3mt9VE5mtEZuBaivBywYSO59YZEBgyISBYqBl8TZd8vSOETQZy8Qwl8g9BTvKBvS8LQSvYLqD9ZmYgTSQOdStmlqtTROYuOQDPuEuuS8gm5BlmPuEcZSydCc9tggu8cQmmXOxSTEvmBDKtd59LbqLlTPd9EcSKEwVIy58wgBDlwlQxTBTc5KmB8uZSqdjBLBYtmqlmGQKigTcdOmZKgOB9quvgcOWqBwuZmtw5KPZE9LlvtdluoS1SBRZuKQKlmtlsKgw85KuuOBqdKmYcgD8cQPtZLBvtugY5TrEqkvBTllqy5tEiuTZPvTPw7855L9diqEDyygCtmZ5BODKY8OuZSLEuwETZuLQqvTqODuKSy8qDvuRwqS8v");
    cout << length;
    return 0;
}
