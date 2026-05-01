/*

Input : nums = [1, 2, 2, 4, 3, 1, 4]
Output : 3
Explanation : The integer 3 has appeared only once.

Input : nums = [5]
Output : 5
Explanation : The integer 5 has appeared only once.

Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.

Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

*/

#include<bits/stdc++.h>
using namespace std; 
class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n = nums.size();
        if (n == 0) return -1; 
        if (n == 1) return nums[0];  
        for (int i = 0; i < n; i++){
            int count = 0;  
            for (int j = 0; j < n; j++){
                if (nums[i] == nums[j]){
                    count++;
                }
            }
            if (count == 1) return nums[i];  
        }
        return -1;  
    }
};

int main () {
    int n ; 
    cin >> n ; 

    vector < int > nums ;
    for (int  i = 0 ; i < n ; i++ ){
        cin >> nums[i] ;
    }

    Solution obj ;
    int result = obj.singleNumber(nums) ;
    cout << result ;

    return 0 ; 
}











