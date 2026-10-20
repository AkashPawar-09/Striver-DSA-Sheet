/*
Given one meeting room and N meetings represented by two arrays, start and end, 
where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, 
determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time. 
A meeting starting at the same time another meeting ends is considered overlapping.

Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]
Output : 4
Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).


Input : Start = [10, 12, 20] , End = [20, 25, 30]
Output : 1
Explanation : Given the start and end time, only one meeting can be held in meeting room.

Input : Start = [1, 4, 6, 9] , End = [2, 5, 7, 12]
Output : 4

*/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std ;

class Solution{
    public:
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
        vector<pair<int,int>> meetings;
        for(int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        sort(meetings.begin(), meetings.end());
        int left = -1, right = 0, count = 0;
        while(right < n) {
            if(left == -1 || meetings[right].second > meetings[left].first) {
                count++;
                left = right;
            }
            right++;
        }
        return count;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> start(n), end(n);
    for(int i = 0; i < n; i++) {
        cin >> start[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> end[i];
    }
    Solution obj;
    cout << obj.maxMeetings(start, end) << endl;
    return 0;
}

// Time Complexity: O(N log N)
// Space Complexity:O(N)