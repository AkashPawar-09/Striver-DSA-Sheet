/*
Selection Sort : 

Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting the array is: 9, 13, 20, 24, 46, 52

Input: N=5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting the array is: 1, 2, 3, 4, 5
------------------------------------------------------------------------
Working of Selection sort : 
1. store index value in variable then comapre it nested loop 
2. cheak smallest element in array by comparing
3. swap smallest elements with 1st element in outer loop 

example : 
Q.[7 4 5 9 8 2 1]

→ [1 4 5 9 8 2 7]   // 1 swaped with 7
→ [1 2 5 9 8 4 7]   // 2 swaped with 4
→ [1 2 4 9 8 5 7]   // 4 swaped with 4
→ [1 2 4 5 8 9 7]   // 5 swaped with 9
→ [1 2 4 5 7 9 8]   // 7 swaped with 8
→ [1 2 4 5 7 8 9]   // 8 swaped with 9

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int index = i; 
            for (int j = i + 1; j < n; j++) {  
                if (nums[j] < nums[index]) { 
                    index = j;  
                }
            }
            swap(nums[i], nums[index]); 
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

    vector<int> result = obj.selectionSort(nums);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}



