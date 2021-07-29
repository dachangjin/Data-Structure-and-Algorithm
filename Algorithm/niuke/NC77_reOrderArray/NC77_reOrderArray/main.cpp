//
//  main.cpp
//  NC77_reOrderArray
//
//  Created by tommywwang on 2021/7/29.
//

#include <iostream>
#include <vector>

using namespace std;

// NC77 调整数组顺序使奇数位于偶数之前，并保持相对位置不变
// https://www.nowcoder.com/practice/ef1f53ef31ca408cada5093c8780f44b?tpId=188&&tqId=38597&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 需要保持相对位置不变则不能使用双指针，使用新数组存奇数和偶数值，在合并数组即可
// 或者使用冒泡排序思想两次for循环遍历
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        vector<int> result;
        vector<int> events;
        for (int val: array) {
            if (val % 2 == 1) {
                result.push_back(val);
            } else {
                events.push_back(val);
            }
        }
        for (int val : events) {
            result.push_back(val);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
