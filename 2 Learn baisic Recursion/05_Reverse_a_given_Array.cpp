/*
Input: N = 5, arr[] = {5,4,3,2,1}
Output: {1,2,3,4,5}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.

Input: N=6 arr[] = {10,20,30,40}
Output: {40,30,20,10}
Explanation: Since the order of elements gets reversed the first element will occupy the fifth position, the second element occupies the fourth position and so on.
*/


#include <bits/stdc++.h>
using namespace std ;

class Solution{
public:
    void reverse(int arr[], int n){
        for(int i = 0; i < n/2; i++){
            swap(arr[i], arr[n - i - 1]);
        }
    }
};




int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution obj;
    obj.reverse(arr, n); 
    
    for(int i = 0; i < n; i++){   // Printing 
        cout << arr[i] << " ";
    }

    return 0;
}






