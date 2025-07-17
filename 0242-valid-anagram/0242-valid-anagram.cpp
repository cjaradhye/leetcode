class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];

        for(int i = 0; i < s.size(); i++){
            char a = s[i] - 'a';

            arr[a] = arr[a] + 1;
        }

        for(int i = 0; i < t.size(); i++){
            char a = t[i] - 'a';
            arr[a] = arr[a] - 1;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i]!=0) return false;
        }

        return true;
    }
};