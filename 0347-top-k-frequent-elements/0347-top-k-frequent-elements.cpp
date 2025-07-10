class Solution {
public:
    static bool Descending(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        vector<int> ans;

        // Count frequencies
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }

        // Transfer map to vector of pairs
        vector<pair<int, int>> freqVec(mpp.begin(), mpp.end());

        // Sort by frequency descending
        sort(freqVec.begin(), freqVec.end(), Descending);

        // Get top K frequent elements
        for(int i = 0; i < k; i++){
            ans.push_back(freqVec[i].first);
        }

        return ans;
    }
};
