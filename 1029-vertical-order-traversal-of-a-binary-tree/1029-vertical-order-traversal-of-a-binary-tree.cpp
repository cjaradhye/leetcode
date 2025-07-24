class Solution {
public:
    void pleaseWork(pair<int, int> pos, map<pair<int, int>, vector<int>>& mpp, TreeNode* root){
        if(!root){
            return;
        }
        cout<<root->val<<pos.first<<pos.second<<"\n";
        mpp[pos].push_back(root->val);
        if(root->left){
            pos.first-=1;
            pos.second++;
            pleaseWork(pos, mpp, root->left);
            pos.first++;
            pos.second--;
        }if(root->right){
            pos.second++;
            pos.first+=1;
            pleaseWork(pos, mpp, root->right);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<pair<int, int>, vector<int>> mpp;
        pair<int, int> pos = make_pair(0,0);

        pleaseWork(pos, mpp, root);
        int prev = INT_MAX;
        vector<int> temp;
        for(auto it: mpp){
            if(it.first.first>prev){
                ans.push_back(temp);
                vector<int> newnew;
                temp = newnew;
                prev = it.first.first;
            }if(it.first.first <= prev){
                prev = it.first.first;
                sort(it.second.begin(), it.second.end());
                temp.insert(temp.end(), it.second.begin(), it.second.end());
            }
        }
        if(!temp.empty()){
            ans.push_back(temp);
        }

        return ans;
    }
};