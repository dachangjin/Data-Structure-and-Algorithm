//
//  main.cpp
//  NC14_Print
//
//  Created by tommywwang on 2021/7/29.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// NC14 按之字形顺序打印二叉树
// https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=188&&tqId=38563&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking
// 简单，没什么好说的
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> results;
        vector<int> result;
        queue<TreeNode *> nodes;
        if (pRoot) {
            nodes.push(pRoot);
        }
        int count = (int)nodes.size();
        bool shouldReverse = false;
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            result.push_back(node->val);
            nodes.pop();
            if (node->left) {
                nodes.push(node->left);
            }
            if (node->right) {
                nodes.push(node->right);
            }
            count --;
            if (count == 0) {
                if (shouldReverse) {
                    reverse(result.begin(), result.end());
                    results.push_back(result);
                } else {
                    results.push_back(result);
                }
                shouldReverse = !shouldReverse;
                result.clear();
                count = (int)nodes.size();
            }
        }
        return results;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
