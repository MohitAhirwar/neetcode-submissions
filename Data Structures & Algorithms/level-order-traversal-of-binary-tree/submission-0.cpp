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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,vector<TreeNode*>> res;

        queue<pair<int,TreeNode*>> Q;

        Q.push({0,root});   


        while(Q.size()){
            auto cur = Q.front(); Q.pop();
            TreeNode* curn = cur.second;
            int depth = cur.first;
            res[depth].push_back(curn);

            if(curn->left){
                Q.push({depth+1,curn->left});
            }

            if(curn->right){
                Q.push({depth+1,curn->right});
            }
        }



        for(auto &ele : res){
            vector<int> cur;
            for(auto &k : ele.second){
                cur.push_back(k->val);
            }
            ans.push_back(cur);
        }

        return ans;
    }
};
