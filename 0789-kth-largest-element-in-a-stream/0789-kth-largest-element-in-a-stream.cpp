class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> eh;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i : nums){
            eh.push(i);
        }
        int temp = eh.size()-k;
        for(int i = 0; i < temp; i++) eh.pop();
        // cout<<eh.size()<<k;
    }
    
    int add(int val) {
        if(eh.size() < k){
            // cout<<eh.size();
            // cout<<"here"<<val<<endl;
            eh.push(val);
        }else{
            eh.push(val);
            eh.pop();
        }

        return eh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */