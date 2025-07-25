class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stub;
        for (int num : nums) {
            auto it = lower_bound(stub.begin(), stub.end(), num);
            if (it == stub.end()) {
                stub.push_back(num);
            } else {
                *it = num;
            }
        }
        return stub.size();
    }
};