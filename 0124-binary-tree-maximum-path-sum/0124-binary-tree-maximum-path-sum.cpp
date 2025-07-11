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
    int maxPath = INT_MIN;
    
    int pleaseWork(TreeNode* root) {
        if(root==nullptr) return 0;

        int left = max(0, pleaseWork(root->left));
        int right = max(0, pleaseWork(root->right));

        int curr = root->val + left + right;
        maxPath = max(curr, maxPath);
        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root){
        int x = pleaseWork(root);

        return maxPath;
    }
};