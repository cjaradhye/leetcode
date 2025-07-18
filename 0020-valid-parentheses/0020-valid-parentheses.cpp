class Solution {
public:
    bool isValid(string s) {
        stack<char> nums;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                nums.push(s[i]);
            }else if(nums.size()==0){
                return false;
            }else if(s[i]==')' && nums.top()=='('){
                nums.pop();
            }else if(s[i]=='}' && nums.top()=='{'){
                nums.pop();
            }else if(s[i]==']' && nums.top()=='['){
                nums.pop();
            }else{
                return false;
            }
        }

        if(nums.empty()) return true;
        else return false;
    }
};