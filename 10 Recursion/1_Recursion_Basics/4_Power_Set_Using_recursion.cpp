#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void generate(vector<int>& nums, int index, vector<int>& current) {
        if (index == nums.size()) {
            for (int x : current) {
                cout << x << " ";
            }
            cout << endl;
            return;
        }
        // Include
        current.push_back(nums[index]);
        generate(nums, index + 1, current);         // this function will call till index == 3 
        // after index==size then return statement will give chance to below fuction of pop (Don't include)

        // Don't include
        current.pop_back();
        generate(nums, index + 1, current);
    }
};



int main() {
    Solution obj;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> current;
    obj.generate(nums, 0, current);
    return 0;
}



// Time Complexity: O(2^N × N)
// Space Complexity: O(N)