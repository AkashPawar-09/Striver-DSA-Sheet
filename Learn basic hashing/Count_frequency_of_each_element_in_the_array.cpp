/*

Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
        5   2
        15  1
Explanation: 10 occurs 3 times in the array
5 occurs 2 times in the array
15 occurs 1 time in the array

Input: arr[] = {2,2,3,4,4,2};
Output: 2  3
	    3  1
        4  2

Explanation: 2 occurs 3 times in the array
3 occurs 1 time in the array
4 occurs 2 time in the array
            
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        
        int hash[100000 + 1] = {0};

        // Count frequency
        for(int x : nums){
            hash[x]++;
        }

        // Store result
        vector<vector<int>> result;

        for(int i = 0; i <= 100000; i++){
            if(hash[i] > 0){
                result.push_back({i, hash[i]});
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;   // size of array

    vector<int> nums(n);

    // input array
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.countFrequencies(nums);

    // output
    for(auto &v : ans){
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}











#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        
        int hash[100000 + 1] = {0};

        // Step 1: Count frequency
        for(int x : nums){
            hash[x]++;
        }

        // Step 2: Store result
        vector<vector<int>> result;

        for(int i = 0; i <= 100000; i++){
            if(hash[i] > 0){
                result.push_back({i, hash[i]});
            }
        }

        return result;
    }
};


int main() {
    int n;
    cin >> n;   // size of array

    vector<int> nums(n);

    // input array
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.countFrequencies(nums);

    // output
    for(auto &v : ans){
        cout << v[0] << " " << v[1] << endl;
    }

    return 0;
}


