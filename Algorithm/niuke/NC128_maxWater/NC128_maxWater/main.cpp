//
//  main.cpp
//  NC128_maxWater
//
//  Created by tommywwang on 2021/7/14.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        long long maxResult = 0;
        
        vector<int> fromStart;
        vector<int> fromEnd;
        
        int current = 0;
        for (int i = 0; i < arr.size(); i ++) {
            current = max(current, arr[i]);
            fromStart.push_back(current);
        }
        current = 0;
        for (int i = (int)arr.size() - 1; i >= 0; i --) {
            current = max(current, arr[i]);
            fromEnd.insert(fromEnd.begin(), current);
        }
        for (int i = 0; i < arr.size(); i ++) {
            maxResult += min(fromStart[i], fromEnd[i]) - arr[i];
        }
        return maxResult;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(4);
    long long result = sol.maxWater(arr);
    
    return 0;
}
