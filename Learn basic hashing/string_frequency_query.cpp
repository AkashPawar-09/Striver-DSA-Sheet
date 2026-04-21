/*
formula used : 
using ascii values 
index = character - 'a'


input : 
akash       // input string 
3           // number of queries
a b s       // querires to be find

output :
2           // appearence of a
0           // appearence of b
1           // appearence of s
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencyQuery(string& s, vector<char>& queries) {
        int hash[256] = {0}; // for 'a' to 'z'

        // precompute
        for(char ch : s) {
            hash[ch - 'a']++;   // map character to index
        }

        // answer queries
        vector<int> result;
        for(char q : queries) {
            result.push_back(hash[q - 'a']);
        }

        return result;
    }
};

int main() {
    string s;
    cin >> s;   // example: abacaba

    int q;
    cin >> q;

    vector<char> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    Solution obj;
    vector<int> ans = obj.frequencyQuery(s, queries);

    for(int x : ans) {
        cout << x << endl;
    }

    return 0;
}


// Time Complexity: O(n + q)
// Space Complexity: O(n)