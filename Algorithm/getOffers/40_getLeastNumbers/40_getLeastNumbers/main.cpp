//
//  main.cpp
//  40_getLeastNumbers
//
//  Created by wangwei on 2021/6/10.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
 最小的k个数
 */
class Solution {
public:
    // 利用快排partition思想
    int partition(vector<int> &arr, int start, int end) {
        if (start >= end) {
            return end;
        }
        // 随机挑选一个数值，并且放到数组最后一个位置
        int randomIndex =  start + rand()%(end-start+1);
        swap(arr[randomIndex], arr[end]);
        int val = arr[end];
        // index指向当前需要被替换的下表
        int index = start;
        int i = start;
        //从start开始一直遍历到倒数第一个就行了。
        while (i < end) {
            if (arr[i] < val) {
                // 当找到小于的值时候，替换index和找到的那个值。index向前进一位。
                swap(arr[index], arr[i]);
                index ++;
            }
            i ++;
        }
        // 最后将分和值放分割处
        swap(arr[index], arr[end]);
        return index;
    }
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k > arr.size()) {
            return vector<int>();
        } else if (k == arr.size()){
            return arr;
        }
        vector<int> results;
        int start = 0;
        int end = (int)arr.size() - 1;
        int index = partition(arr, start, end);
        // 逐渐减小范围
        while (index != k) {
            if (index < k) {
                start = index + 1;
                index = partition(arr, start, end);
            } else if (index > k) {
                end = index -1;
                index = partition(arr, 0, end);
            }
        }
        vector<int>::iterator i = arr.begin();
        index = 0;
        while (index < k) {
            results.push_back(*i);
            index ++;
            i ++;
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> array;
    array.push_back(4);
    array.push_back(2);
    array.push_back(1);
    array.push_back(5);
    array.push_back(0);
    
    Solution sol;
    vector<int> result = sol.getLeastNumbers(array, 3);
    
    
    return 0;
}
