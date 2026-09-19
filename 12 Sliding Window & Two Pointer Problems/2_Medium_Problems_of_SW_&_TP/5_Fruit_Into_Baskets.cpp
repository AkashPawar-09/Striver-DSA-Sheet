/*

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.


Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].


Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 
*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() ;
        int i = 0;
        int maxLength = 0 ;
        unordered_map<int, int> freq;

        for (int j = 0; j < n; j++) {
            freq[fruits[j]]++;
            while (freq.size() > 2) {
                freq[fruits[i]]--;

                if (freq[fruits[i]] == 0) {
                    freq.erase(fruits[i]);
                }

                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength ;
    }
};




int main() {
    Solution obj;
    vector<int> fruits = {1, 2, 1};
    cout << obj.totalFruit(fruits);
    return 0;
}