#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int count1 = 0, count2 = 0, count3 = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') count1++;
            else if(s[i] == '(') count2++;
            else count3++;
            if(count1 > count2 + count3) return false;  
            // while going from 1st to last , if ')' becomes more than '(' , then return true
        }
        
        count1 = 0;
        count2 = 0;
        count3 = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')') count1++;
            else if(s[i] == '(') count2++;
            else count3++;
            if(count2 > count1 + count3) return false;
            // while going from 1st to last , if '(' becomes more than ')' , then return true
        }

        return true;
    }
};


int main() {
    string s;
    cin >> s;
    Solution obj;
    cout << (obj.checkValidString(s) ? "true" : "false") << endl;
    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(1)