#include<bits/stdc++.h>
using namespace std ;

class Solution{
    public:
    int findPlatform(vector<int>& arr, vector<int>& dep){
        int n = arr.size();
        if(n == 0) return 0;
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int count = 1;
        int i = 1;
        int j = 0;
        int maxCount = 1;
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> arr(n), dep(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> dep[i];
    Solution obj;
    cout << obj.findPlatform(arr, dep) << endl;
    return 0;
}



// Time Complexity : O(N logN)
// Space Complexity : O(1)