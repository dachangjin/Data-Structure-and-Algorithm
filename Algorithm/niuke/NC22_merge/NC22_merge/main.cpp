//
//  main.cpp
//  NC22_merge
//
//  Created by wangwei on 2021/7/12.
//

#include <iostream>
// NC22 合并两个有序的数组
// https://www.nowcoder.com/practice/89865d4375634fc484f3a24b7fe65665?tpId=188&&tqId=38585&rp=1&ru=/ta/job-code-high-week&qru=/ta/job-code-high-week/question-ranking

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while (n > 0 && m > 0) {
            int valA = A[m - 1];
            int valB = B[n - 1];
            if (valB > valA) {
                A[m + n - 1] = valB;
                n--;
            } else {
                A[m + n - 1] = valA;
                m--;
            }
        }
        // B数组有可能还没有被拍到a中
        if (n > 0) {
            for (int i = 0; i < n; i ++) {
                A[i] = B[i];
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    int array1[6] = {4, 5, 6, 0, 0, 0};
    int array2[3] = {1, 2, 3};
    Solution sol;
    sol.merge(array1, 4, array2, 4);
    return 0;
}
