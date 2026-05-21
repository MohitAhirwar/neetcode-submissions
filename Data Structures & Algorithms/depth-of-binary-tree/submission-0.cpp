/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxD = 0;

    void dfs(TreeNode* root, int d){
        if(!root) return;

        maxD = max(maxD,d);
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }


    int maxDepth(TreeNode* root) {
        dfs(root,1);
        return maxD;
    }
};
