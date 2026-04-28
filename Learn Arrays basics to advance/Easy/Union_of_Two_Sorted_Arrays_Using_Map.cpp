/*

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
        Distnict Elements in arr1 are : 1
        Distnict Elemennts in arr2 are : No distinct elements.
        Union of arr1 and arr2 is {1,2,3,4,5}

Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
Output: {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
        Distnict Elements in arr1 are : 1,6,7,8,9,10
        Distnict Elemennts in arr2 are : 11,12
        Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, int> freq;   // stores frequency (also keeps keys sorted)
        vector<int> Union;    // result vector

        for (int x : nums1) {
            freq[x]++;              // Insert elements of nums1
        }

        for (int x : nums2) {
            freq[x]++;              // Insert elements of nums2
        }

        for (auto &it : freq) {
            Union.push_back(it.first);      // Collect unique elements (keys are already sorted)
        }

        return Union;
    }
};


int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;

    vector<int> nums1(n);
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> nums2(m);
    cout << "Enter elements of second array: ";
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution obj;
    vector<int> result = obj.unionArray(nums1, nums2);

    cout << "Union of arrays: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

// Time Compleixty : O( (m+n)log(m+n) )
// Space Complexity : O(m+n) 

