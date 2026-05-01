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


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;
        vector<int> Union;

        while (i < nums1.size() && j < nums2.size()) {

            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }

            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }

            if (nums1[i] < nums2[j]) {
                Union.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                Union.push_back(nums2[j]);
                j++;
            }
            else {
                Union.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        while (i < nums1.size()) {
            if (i == 0 || nums1[i] != nums1[i - 1]) {
                Union.push_back(nums1[i]);
            }
            i++;
        }

        while (j < nums2.size()) {
            if (j == 0 || nums2[j] != nums2[j - 1]) {
                Union.push_back(nums2[j]);
            }
            j++;
        }

        return Union;
    }
};





int main() {
    int n, m;

    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++) cin >> nums2[i];

    Solution obj;
    vector<int> result = obj.unionArray(nums1, nums2);

    for (int x : result) cout << x << " ";

    return 0;
}


// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
