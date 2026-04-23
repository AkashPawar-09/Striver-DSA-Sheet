/*

Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.

Input: N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.
Here element 5 is not smaller than or equal to its future elements.

*/


#include<iostream> 
#include<vector>
using namespace std ;

class Solution{	
	public:
		bool isSorted(vector<int>& nums){
			int n = nums.size();

			for (int i = 0; i < n - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					return false;
				}
			}
			return true;
		}
};

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    vector<int> nums(n) ;

    for (int &x : nums) {cin >> x;}

    Solution obj;   
    bool result = obj.isSorted(nums);  
    cout << result << endl;
    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)