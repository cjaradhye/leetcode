class Solution {
public:
    bool dryRun(vector<int>& piles, int speed, int h){
        int time = 0;
        for(int i = 0; i < piles.size(); i++){
            time += (piles[i] + speed - 1) / speed;            
            if(time > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = (low + high) / 2;

            if(dryRun(piles, mid, h)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};