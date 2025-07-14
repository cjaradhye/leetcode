class myComp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second > b.second) {
            return true;
        }
        else if (a.second == b.second
                 && a.first < b.first) {
            return true;
        }

        return false;
    }
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        vector<int> ans;

        for(int i : nums){
            mpp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> eh;
        int count = 0;
        for(auto [x, y] : mpp){
            eh.push({x,y});
            if(count>=k){   
                eh.pop();
            }
            count++;
        }

        while(!eh.empty()){
            auto [x,y] = eh.top();
            ans.push_back(x);
            eh.pop();
        }

        return ans;
    }
};