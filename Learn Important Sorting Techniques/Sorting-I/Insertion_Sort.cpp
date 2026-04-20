/*
Insertion Sort :

Input:
nums = [7, 4, 1, 5, 3]  
Output:
[1, 3, 4, 5, 7]  
Explanation:
The array is sorted in non-decreasing order: 1 ≤ 3 ≤ 4 ≤ 5 ≤ 7.

Input:
nums = [5, 4, 4, 1, 1]  
Output:
[1, 1, 4, 4, 5]  
Explanation:
The array is sorted in non-decreasing order: 1 ≤ 1 ≤ 4 ≤ 4 ≤ 5.

*/

#include<bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size() ;
        for (int i = 1; i < n; i++ ) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        }
        return nums;
    }
};



int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    vector<int> result = obj.insertionSort(nums);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}



// time Complexity: O(n²)
// Space Complexity: O(1)