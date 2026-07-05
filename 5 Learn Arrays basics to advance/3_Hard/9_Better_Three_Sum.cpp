/*          

Input: arr = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
arr[0] + arr[1] + arr[2] = (-1) + 0 + 1 = 0.
arr[1] + arr[2] + arr[4] = 0 + 1 + (-1) = 0.
arr[0] + arr[3] + arr[4] = (-1) + 2 + (-1) = 0. // but -1 and -1 are not distinct   
The distinct triplets are [-1,0,1] and [-1,-1,2].

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Input: arr = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/

#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;                                   // n = no. of elements in nums
        if (n<3) {return {} ;}                                  // if n is less than 3
        vector<vector<int>> ans ;                               // create 2D vector to return output
        set<vector<int>> row;                                   // create set to avoid duplicate vector row

        for (int i = 0 ; i < n ; i++) {             // iteration from 1st element
            set<int>seen ;                          // stores visited elements for the current i to find the required third element
            for (int j = i+1 ; j < n ; j++){        // iteration from 2nd element    
                    int k ;                         // stores the required third value to make the sum zero
                    k = nums[i] + nums[j] ;         // calculate sum of first two elements
                    // here k is required third element in triplet which we gonna find out 
                    // used formula is nums[i] + nums[j] + nums[k] == 0 (i.e. nums[i]+nums[j] = { - nums[k] } )
                    // Required value = -(nums[i] + nums[j])
                    k = (-1) * k ;                              // making k in negative k 

                    if(seen.find(k) != seen.end()){             // cheaks element k already exists or not in seen set
                        // if the required value already exists in seen 
                        vector<int>element;                     // create a elemenet vector 

                        element.push_back(nums[i]) ;            // push_back 1st element
                        element.push_back(nums[j]) ;            // push_back 2nd element 
                        element.push_back(k) ;                  // push_back 3rd calculated element

                        sort(element.begin(), element.end());   // sort element vector in ascending order
                        // to remove duplicate in set like [-1, 0, 1] and [1, 0, -1] 

                        row.insert(element) ;                   // insert element set in row
                    }
                    seen.insert(nums[j]);
                    // seen stores all the numbers that have already been visited in the current inner loop.
                    // So seen always contains the previous nums[j] values encountered during the current outer loop iteration.
                }
            }
        for(auto it : row) {                                    // iteration for inserting element in row
            ans.push_back(it);                                  // push_back all elements in row to ans vector 
        }
        return ans ;                                            // return updated ans vector 
    }
};


int main () {
    int n ; 
    cin >> n ;

    vector<int> nums ;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution obj ;
    vector<vector<int>> result = obj.threeSum(nums) ;
    for (auto &triplet : result) {
        for (auto &num : triplet) cout << num << " ";
        cout << endl;
    }

    return 0;

}

// Time Complexity : O(N²)
// Space Complexity : O(N)
