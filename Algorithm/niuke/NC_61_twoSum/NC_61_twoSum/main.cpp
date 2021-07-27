//
//  main.cpp
//  NC_61_twoSum
//
//  Created by tommywwang on 2021/7/22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// NC61 两数之和
// https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=188&&tqId=38589&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking
// 使用map已val为key，下标为value储存
class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        map<int, int> store;
        for (int i = 0; i < numbers.size(); i ++) {
            int val = numbers[i];
            int offset = target - val;
            map<int,int>::iterator iter = store.find(offset);
            if (iter != store.end()) {
                result.push_back(iter->second + 1);
                result.push_back(i + 1);
                return result;
            } else {
                store[val] = i;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
