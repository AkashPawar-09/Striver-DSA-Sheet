/*

Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]
Explanation : Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6] intervals.


Input : [[1,4],[4,5]]
Output :  [[1,5]]
Explanation :  Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].


Input: intervals = [[5,7],[1,3],[4,6],[8,10]]
Output: [[1,3],[4,7],[8,10]]
Explanation: Intervals [4,6] and [5,7] overlap and are merged into [4,7].


Input: intervals = [[1,5],[3,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].


Input: arr[][] = [[6, 8], [1, 9], [2, 4], [4, 7]]
Output: [[1, 9]]
Explanation: In the given intervals all the intervals overlap with the interval [1, 9]. Therefore we will return [1, 9].

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = arr[i][0];
            int end = arr[i][1];
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    Solution obj;

    vector<vector<int>> ans = obj.mergeOverlap(arr);

    for (auto &interval : ans) {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}



// Time Complexity : O(N²)
// Space Complexity : O(N) 








/* -------------------------------------------------- ANSWER ----------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int start = arr[i][0];
            int end = arr[i][1];
            if (!ans.empty() && end <= ans.back()[1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                }
                else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};



-------------------------------------------------- Explanation --------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------


Example : nums = (1,3) , (2,6) , (8,9) , (9,11) , (8,10) , (2,4) , (15,18) , (16,17) 

-----------------------------------------------------------------------------------------------------------------------

STEP 0 : Declare seprate ans 2D vector To store all vector of output 

-----------------------------------------------------------------------------------------------------------------------

STEP 1  : SORT = sorting works element by element of array 
          It sorts 1st element then 2nd element

nums = (1,3) , (2,4) , (2,6) , (8,9) , (8,10) , (9,11) , (15,18) , (16,17) 

-----------------------------------------------------------------------------------------------------------------------

STEP 2 : For loop from 1st Sub-interval (Duo) to last to cheak every Duo

-----------------------------------------------------------------------------------------------------------------------

STEP 3 : define 1st and 2nd element of Duo as start and end 

int start = arr[i][0];          -- First element 
int end = arr[i][1];            -- Last element (2nd element)

-----------------------------------------------------------------------------------------------------------------------

STEP 4 : Cheak if new vector AND Boundries of current answer vector

+-----------------------------------------------------+
| if (!ans.empty() && end <= ans.back()[1]) {         |
|     continue;                                       |
| }                                                   |
+-----------------------------------------------------+

Terms :
ans.empty = cheaks wheather answer vector is empty or not
end = current end (int) in loop i=0 to n (updating)
ans.back = gives last vector in ans vector (2D vector)
ans.back()[1] = gives last (2nd) element of last vector in ans vector (2D vector)


!ans.empty() = If answer vector is not empty 
&& = and
end <= ans.back()[1] = 2nd elmenet (end) is smaller or equal to last element of current 2nd element of answer vector

-----------------------------------------------------------------------------------------------------------------------

STEP 5 : Create For inside a main for loop to compare Duo with next Duo 


for (int j = i + 1; j < n; j++) {
    if (arr[j][0] <= end) {
        end = max(end, arr[j][1]);
    }
    else {
        break;
    }
}



if (arr[j][0] <= end) {         = If first element of Next Duo is smaller than or equal to current end (cheaking range STEP)
    end = max(end, arr[j][1]);  = Then update the end by max function (max of current end and Next Duo's end(2nd element))


else { break ; }                = if first element is not small then break loop , go for next itearation of j

-----------------------------------------------------------------------------------------------------------------------

STEP 6 : If all conditions are satisfied then push it to answer vector

ans.push_back({start, end});

----------------------------------------------------------------------------------------------------------------------- */