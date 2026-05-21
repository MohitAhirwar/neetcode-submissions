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
    bool ok;
    int maxD = 0;
    int dfs(TreeNode* x){
        if(!x) return 0;

        int ld = dfs(x->left);
        int rd = dfs(x->right);

        if(abs(ld - rd) > 1) ok = false;

        maxD = max(maxD, ld + rd);
        return 1 + max(ld,rd);
    }

    bool isBalanced(TreeNode* root) {
        ok = true;
        dfs(root);
        return ok;
    }
};
