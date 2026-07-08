/* 

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].


Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]
Output: [-5, -3, -2, 1, 4, 5, 8]
Explanation: The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2


Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]
Output: [-7, -3, -1, 0, 2, 7, 8]
Explanation: The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {

            int left = 0;
            int right = left + gap;

            while (right < len) {

                // left in nums1 and right in nums2
                if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                }

                // left in nums2 and right in nums2
                else if (left >= m) {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }

                // left in nums1 and right in nums1
                else {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }

                left++;
                right++;
            }

            if (gap == 1) break;

            gap = (gap / 2) + (gap % 2);
        }

        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};


int main() {

    int m, n;

    cin >> m;

    vector<int> nums1(m);

    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cin >> n;

    vector<int> nums2(n);

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    // Resize nums1 to hold m+n elements (like LeetCode)
    nums1.resize(m + n);

    Solution obj;
    obj.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";

    for (int x : nums1) {
        cout << x << " ";
    }

    return 0;
}


// Time Complexity : O(m+n)
// Space Complexity : O(1)