#include <set>

class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (data.empty()) {
            data.insert(num);
            mid = data.begin();
        } else {
            data.insert(num);
            if (num < *mid) {
                if (data.size() % 2 == 0) mid--;
            } else {
                if (data.size() % 2 != 0) mid++;
            }
        }
    }

    double findMedian() {
        int n = data.size();
        if (n % 2 == 0) {
            auto nextMid = next(mid);
            return ((double)(*mid) + *nextMid) / 2.0;
        }
        return (double)(*mid);
    }
};



// class MedianFinder {
// public:
//     double median = 0;
//     vector<int> ans;

//     MedianFinder() {
//         return;
//     }
    
//     void addNum(int num) {
//         ans.push_back(num);
//         int i = ans.size()-1;
//         int parent = (i-1)/2;

//         while(parent>=0 && ans[parent]<ans[i]){
//             swap(ans[parent], ans[i]);
//             i = parent;
//         }
//     }
    
//     double findMedian() {
//         int temp = ans.size();
//         // cout<<median<<" "<<temp<<endl;

//         if(temp%2!=0){
//             median = (double) ans[(temp/2)];
//         }else{
//             temp/=2;
//             // cout<<ans[temp-1]<<" "<<ans[temp]<<endl;
//             median = (double) (ans[temp-1] + ans[temp])/2;
//         }
//         return median;
//     }
// };



// class MedianFinder {
// public:
//     double median;
//     vector<int> ans;

//     MedianFinder() {
//         return;
//     }
    
//     void addNum(int num) {
//         ans.push_back(num);
//         // fillVector();
//         sort(ans.begin(), ans.end());
//         int temp = ans.size();

//         if(temp%2!=0){
//             median = (double) ans[(temp/2)];
//         }else{
//             temp/=2;
//             median = (double) (ans[temp-1] + ans[temp])/2;
//         }
//     }
    
//     double findMedian() {
//         return median;
//     }

//     // void fillVector(){
//     //     priority_queue<int> temp = eh;
//     //     vector<int> newnew;
//     //     ans = newnew;
//     //     while(!eh.empty()){
//     //         int a = eh.top();
//     //         ans.push_back(a);
//     //         eh.pop();
//     //     }
//     //     eh = temp;
//     // }
// };






// class MedianFinder {
// public:
//     priority_queue<int> eh;
//     double median;
//     vector<int> ans;

//     MedianFinder() {
//         return;
//     }
    
//     void addNum(int num) {
//         eh.push(num);
//         fillVector();
//         int temp = ans.size();

//         if(temp%2!=0){
//             median = (double) ans[(temp/2)];
//         }else{
//             temp/=2;
//             median = (double) (ans[temp-1] + ans[temp])/2;
//         }
//     }
    
//     double findMedian() {
//         return median;
//     }

//     void fillVector(){
//         priority_queue<int> temp = eh;
//         vector<int> newnew;
//         ans = newnew;
//         while(!eh.empty()){
//             int a = eh.top();
//             ans.push_back(a);
//             eh.pop();
//         }
//         eh = temp;
//     }
// };