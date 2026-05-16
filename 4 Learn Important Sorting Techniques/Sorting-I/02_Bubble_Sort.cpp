/*
Bubble Sort : 

Input: N = 5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting we get 1,2,3,4,5

Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: After sorting we get 9,13,20,24,46,52

------------------------------------------------------------
Working of Selection sort : 
1. It chaeaks values of elements which are adjecent to each other 
2. them swap them until array is sorted

// Each pass → largest element goes to the end

→ [4 5 7 8 2 1 9]   // Pass 1: largest (9) moved to end
→ [4 5 7 2 1 8 9]   // Pass 2: next largest (8) moved to correct position
→ [4 5 2 1 7 8 9]   // Pass 3: 7 placed correctly
→ [4 2 1 5 7 8 9]   // Pass 4: 5 placed correctly
→ [2 1 4 5 7 8 9]   // Pass 5: 4 placed correctly
→ [1 2 4 5 7 8 9]   // Pass 6: 2 and 1 sorted → array complete

*/



#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    vector<int> selectionSort(vector<int>& nums) {
        int n = nums.size() ;
        for (int i=0 ; i < n-1 ; i++ ) {
            for (int j = 0 ; j < n-i-1 ; j++ ){
                if (nums[j] > nums[j+1] ) {
                    swap (nums[j] , nums[j+1]);
                }
            }
        }
        return nums ;
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




