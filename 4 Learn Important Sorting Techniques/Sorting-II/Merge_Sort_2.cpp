/*

Input : N=7,arr[]={3,2,8,5,1,4,23}
Output : {1,2,3,4,5,8,23}
Explanation : Given array is sorted in non-decreasing order.

Input : N=5, arr[]={4,2,1,6,7}
Output : {1,2,4,6,7}
Explanation : Given array is sorted in non-decreasing order.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp; // temporary array to store merged sorted elements

        int left = low;        // pointer for left half
        int right = mid + 1;   // pointer for right half

        // merge both halves into temp in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]); // take smaller from left
                left++;                    // move left pointer
            }
            else {
                temp.push_back(arr[right]); // take smaller from right
                right++;                    // move right pointer
            }
        }

        // copy remaining elements from left half (if any)
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // copy remaining elements from right half (if any)
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // copy sorted elements back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSortHelper(vector<int>& arr, int low, int high) {
        if (low == high) return; // base case: single element is already sorted

        int mid = (low + high) / 2; // find middle index

        mergeSortHelper(arr, low, mid);       // sort left half
        mergeSortHelper(arr, mid + 1, high);  // sort right half

        merge(arr, low, mid, high);           // merge both sorted halves
    }

    vector<int> mergeSort(vector<int>& nums) {
        mergeSortHelper(nums, 0, nums.size() - 1); // call merge sort on full array
        return nums;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    vector<int> result = sol.mergeSort(arr);

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}