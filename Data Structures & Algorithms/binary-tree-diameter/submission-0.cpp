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
    int dfs(TreeNode* x){
        if(!x) return 0;

        int ld = dfs(x->left);
        int rd = dfs(x->right);
        maxD = max(maxD, ld + rd);
        return 1 + max(ld,rd);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxD;
    }
};
