/* --------------------------------------------- BASED ON MERGE SORT ---------------------------------------------    

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.


Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.


Input: nums = [2, 3, 7, 1, 3, 5]
Output: 5
Explanation: The responsible indexes are:
nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5


Input: nums = [-10, -5, 6, 11, 15, 17]
Output: 0
Explanation:
nums is sorted, hence no inversions present.

*/

#include <bits/stdc++.h>
using namespace std;

// Merge two sorted halves and count inversions.
int merge(vector<int> &arr, int low, int mid, int high) {

    // Temporary array to store the merged sorted elements.
    vector<int> temp;

    // Pointer for the left half.
    int left = low;

    // Pointer for the right half.
    int right = mid + 1;

    // Stores the number of inversions found during merging.
    int cnt = 0;

    // Compare elements from both halves and merge them in sorted order.
    while (left <= mid && right <= high) {

        // If the left element is smaller or equal,
        // simply place it into the temporary array.
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }

        // Otherwise, the right element is smaller,
        // so it forms inversions with every remaining element
        // from the left half.
        else {
            temp.push_back(arr[right]);

            // Number of inversions =
            // Remaining elements in left half.
            cnt += (mid - left + 1);

            right++;
        }
    }

    // Copy remaining elements of the left half.
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements of the right half.
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged sorted elements back
    // into the original array.
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    // Return the inversion count found during this merge.
    return cnt;
}

// Merge Sort function that recursively sorts the array
// and counts inversions.
int mergeSort(vector<int> &arr, int low, int high) {

    // Stores the total inversion count.
    int cnt = 0;

    // Base case:
    // If the subarray contains only one element,
    // it is already sorted.
    if (low >= high)
        return cnt;

    // Find the middle index.
    int mid = (low + high) / 2;

    // Count inversions in the left half.
    cnt += mergeSort(arr, low, mid);

    // Count inversions in the right half.
    cnt += mergeSort(arr, mid + 1, high);

    // Count inversions while merging both halves.
    cnt += merge(arr, low, mid, high);

    // Return the total inversion count.
    return cnt;
}

// Driver function that starts Merge Sort.
int numberOfInversions(vector<int> &a, int n) {

    // Perform Merge Sort and return
    // the total number of inversions.
    return mergeSort(a, 0, n - 1);
}

int main() {

    // Input size of the array.
    int n;
    cin >> n;

    // Input array.
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Count inversions.
    int cnt = numberOfInversions(a, n);

    // Print the answer.
    cout << "The number of inversions are: " << cnt << endl;

    return 0;
}



// Time Complexity : O(N log N)
// Space Complexity : O(N)




/* ----------------------------------------------- ANOTHER ANSWER METHOD -------------------------------------------



#include <iostream>
#include <vector>
using namespace std;

// This function merges two sorted subarrays arr[l..m] and arr[m+1..r] 
// and also counts inversions in the whole subarray arr[l..r]
int countAndMerge(vector<int>& arr, int l, int m, int r) {
  
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
      	// the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}

int main(){
    vector<int> arr = {4, 3, 2, 1};
    
    cout << inversionCount(arr);
    return 0;
}


// Time Complexity : O(N log N)
// Space Complexity : O(N)


*/