/*  ---------------------------------------- Examples ----------------------------------------

No.       s                      t	        Answer
1	"ADOBECODEBANC"	            "ABC"	    "BANC"
2	"AAABBC"	                "AABC"	    "ABBC"
3	"aabbcc"	                "abc"	    "abbc"
4	"aabbcc"	                "aa"	    "aa"
5	"aabbcc"	                "aaa"	    ""
6	"abc"	                    "ac"	    "abc"
7	"bba"	                    "ab"	    "ba"
8	"this is a test string"	    "tist"	    "t stri"
9	"a"	                        "aa"	    ""
10	"abcdef"	                "xyz"	    ""
----------------------------------------------------------------------------------------------
*/




#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m > n) {return "";}

        vector<int> freq(128, 0);

        for(char c : t){
            freq[c]++;
        }

        int left = 0;
        int count = m;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < n; right++) {

            if(freq[s[right]] > 0) count--;

            freq[s[right]]--;

            while(count == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0) count++;

                left++;
            }
        }

        if(minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};




int main() {

    Solution obj;

    vector<pair<string, string>> testCases = {
        {"ADOBECODEBANC", "ABC"},
        {"AAABBC", "AABC"},
        {"aabbcc", "abc"},
        {"aabbcc", "aa"},
        {"aabbcc", "aaa"},
        {"abc", "ac"},
        {"bba", "ab"},
        {"this is a test string", "tist"},
        {"a", "aa"},
        {"abcdef", "xyz"}
    };

    for(int i = 0; i < testCases.size(); i++) {

        string s = testCases[i].first;
        string t = testCases[i].second;

        cout << "Test Case " << i + 1 << endl;
        cout << "s = " << s << endl;
        cout << "t = " << t << endl;
        cout << "Answer = " << obj.minWindow(s, t) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}