class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int len = 1;
        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++){
            vector<int> temp(len,1);

            for(int j = 1; j < i; j++){
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            len++;
            ans.push_back(temp);

        }

        return ans;

    }
};