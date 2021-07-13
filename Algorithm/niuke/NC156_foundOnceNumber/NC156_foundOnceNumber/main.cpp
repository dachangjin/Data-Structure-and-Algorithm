//
//  main.cpp
//  NC156_foundOnceNumber
//
//  Created by wangwei on 2021/7/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr intvector
     * @param k int
     * @return int
     */
    int foundOnceNumber(vector<int>& arr, int k) {
        int result = 0;
        for(int i = 0; i < 32; i ++) {
            int sum = 0;
            for (int val : arr) {
                if (val & 1 << i) {
                    sum ++;
                }
            }
            if (sum % k != 0) {
                result |= 1 << i;
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
