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
    void pleaseWork(int h, map<int, vector<int>>& mpp, TreeNode* node){
        if(!node) return;

        mpp[h].push_back(node->val);

        pleaseWork(h+1, mpp, node->left);
        pleaseWork(h+1, mpp, node->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int, vector<int>> mpp;

        pleaseWork(0, mpp, root);

        vector<vector<int>> ans;
        
        for(auto eh: mpp){
            ans.push_back(eh.second);
        }

        return ans;
    }
};