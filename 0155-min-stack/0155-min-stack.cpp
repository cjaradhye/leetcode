class MinStack {
public:
    vector<int> eh;
    map<int, int> mpp;

    MinStack() {
        return;
    }
    
    void push(int val) {
        mpp[val]++;
        eh.push_back(val);
    }
    
    void pop() {
        if(eh.size()>0) {
            int temp = *(eh.end()-1);
            mpp[temp]--;

            if(mpp[temp]==0) mpp.erase(temp);
            eh.pop_back();
        }
    }
    
    int top() {
        if(eh.size()>0) return *(eh.end()-1);
        else return 0;
    }
    
    int getMin() {
        if(eh.size()>0){
            auto oof = mpp.begin();
            return oof->first;
        }
        else return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */