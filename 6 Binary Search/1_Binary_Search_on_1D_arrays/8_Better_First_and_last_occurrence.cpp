/*

Input: nums = [5, 7, 7, 8, 8, 10], target = 8
Output: [3, 4]
Explanation: The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]


Input: nums = [5, 7, 7, 8, 8, 10], target = 6
Output: [-1, -1]
Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].


Input: nums = [], target = 0
Output: [-1,-1]


Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
Output: [2, 5]
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5


Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
Output: [6, 6]
Explanation: First and last occurrence of 7 is at index 6


Input: arr[] = [1, 2, 3], x = 4
Output: [-1, -1]
Explanation: No occurrence of 4 in the array, so, output is [-1, -1]

*/

#include<bits/stdc++.h>
using namespace std ;

int lowerBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {   // The function returns two integers.
    int lb = lowerBound(arr, n, k);                 // Calls the lowerBound() function.
    if (lb == n || arr[lb] != k)                    // if lower bound exceeds size of nums OR target isn't present
        return {-1, -1};                            // return -1,-1
    return {lb, upperBound(arr, n, k) - 1};         // else return floor as lowebound and ceil as upperbound - 1
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter target element: ";
    cin >> k;

    pair<int, int> ans = firstAndLastPosition(arr, n, k);

    cout << "First Occurrence Index = " << ans.first << endl;
    cout << "Last Occurrence Index = " << ans.second << endl;

    return 0;
}


// Time Complexity : O(log N)
// Space Complexity : O(1)