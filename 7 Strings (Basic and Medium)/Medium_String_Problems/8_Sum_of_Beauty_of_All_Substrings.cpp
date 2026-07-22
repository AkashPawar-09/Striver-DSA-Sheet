/*

Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.


Input: s = "aabcbaa"
Output: 17

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }

                ans += (maxi - mini);
            }
        }

        return ans;
    }
};



int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << obj.beautySum(s) << endl;

    return 0;
}


// Time Complexity : 
// Space Complexity : 




/* -------------------------------------------------------------------------------------------------------------------------

Input
s = "aabcb"

Beauty = Maximum Frequency − Minimum Frequency (ignoring frequency 0)

________________________________________________________________________________
|  # | Substring | Frequency     | Calculation | Beauty | Valid (Beauty > 0)?   |
| -: | :-------- | :------------ | :---------- | :----: | :-------------------- |
|  1 | `a`       | a=1           | 1−1=0       |    0   |          ❌          |
|  2 | `aa`      | a=2           | 2−2=0       |    0   |          ❌          |
|  3 | `aab`     | a=2, b=1      | 2−1=1       |    1   |          ✅          |
|  4 | `aabc`    | a=2, b=1, c=1 | 2−1=1       |    1   |          ✅          |
|  5 | `aabcb`   | a=2, b=2, c=1 | 2−1=1       |    1   |          ✅          |
|  6 | `a`       | a=1           | 1−1=0       |    0   |          ❌          |
|  7 | `ab`      | a=1, b=1      | 1−1=0       |    0   |          ❌          |
|  8 | `abc`     | a=1, b=1, c=1 | 1−1=0       |    0   |          ❌          |
|  9 | `abcb`    | a=1, b=2, c=1 | 2−1=1       |    1   |          ✅          |
| 10 | `b`       | b=1           | 1−1=0       |    0   |          ❌          |
| 11 | `bc`      | b=1, c=1      | 1−1=0       |    0   |          ❌          |
| 12 | `bcb`     | b=2, c=1      | 2−1=1       |    1   |          ✅          |
| 13 | `c`       | c=1           | 1−1=0       |    0   |          ❌          |
| 14 | `cb`      | c=1, b=1      | 1−1=0       |    0   |          ❌          |
| 15 | `b`       | b=1           | 1−1=0       |    0   |          ❌          |


Total Beauty :

_______________________________________
| Substrings with Beauty > 0 | Beauty |
| -------------------------- | :----: |
| `aab`                      |    1   |
| `aabc`                     |    1   |
| `aabcb`                    |    1   |
| `abcb`                     |    1   |
| `bcb`                      |    1   |

Total Beauty = 1 + 1 + 1 + 1 + 1 = 5

-------------------------------------------------------------------------------------------------------------------------

Example
Input
s = "abb"

Beauty = Maximum Frequency − Minimum Frequency (ignoring frequency 0)

_____________________________________________________________________________
|  # | Substring | Frequency | Calculation | Beauty | Valid (Beauty > 0)?   |
| -: | :-------- | :-------- | :---------- | :----: | :-------------------- |
|  1 | `a`       | a=1       | 1−1=0       |    0   |          ❌          |
|  2 | `ab`      | a=1, b=1  | 1−1=0       |    0   |          ❌          |
|  3 | `abb`     | a=1, b=2  | 2−1=1       |    1   |          ✅          |
|  4 | `b`       | b=1       | 1−1=0       |    0   |          ❌          |
|  5 | `bb`      | b=2       | 2−2=0       |    0   |          ❌          |
|  6 | `b`       | b=1       | 1−1=0       |    0   |          ❌          |



Total Beauty
_______________________________________
| Substrings with Beauty > 0 | Beauty |
| -------------------------- | :----: |
| `abb`                      |    1   |

Total Beauty = 1

-------------------------------------------------------------------------------------------------------------------------

Input
s = "aba"

_____________________________________________________________________________
|  # | Substring | Frequency | Calculation | Beauty | Valid (Beauty > 0)?   |
| -: | :-------- | :-------- | :---------- | :----: | :-------------------- |
|  1 | `a`       | a=1       | 1−1=0       |    0   |          ❌          |
|  2 | `ab`      | a=1, b=1  | 1−1=0       |    0   |          ❌          |
|  3 | `aba`     | a=2, b=1  | 2−1=1       |    1   |          ✅          |
|  4 | `b`       | b=1       | 1−1=0       |    0   |          ❌          |
|  5 | `ba`      | b=1, a=1  | 1−1=0       |    0   |          ❌          |
|  6 | `a`       | a=1       | 1−1=0       |    0   |          ❌          |

Total Beauty : 1


=========================================================================================================================


Explanation of the Optimal Approach (No Dry Run)

Idea :
We need to calculate the beauty of every substring.
Instead of generating every substring separately and recounting frequencies from scratch, 
we fix a starting index and gradually extend the substring one character at a time.
This allows us to update the frequency array in O(1) for each extension.

Line-by-Line Explanation


1.
int n = s.size();
Stores the length of the string.


2.
int ans = 0;
Stores the total beauty of all substrings.


3.
for (int i = 0; i < n; i++)
Choose every possible starting index of a substring.

Example

i = 0 → substrings start from index 0
i = 1 → substrings start from index 1
...


4.
vector<int> freq(26, 0);
Frequency array for lowercase letters.

freq[0] → a
freq[1] → b
...
freq[25] → z
It is created once for every starting index.


5.
for (int j = i; j < n; j++)
Extend the substring one character at a time.

Example

Start = i

j=i      → first character
j=i+1    → two characters
j=i+2    → three characters
...
So we generate every substring beginning at i.


6.
freq[s[j]-'a']++;
Increase the frequency of the newly added character.

Instead of recounting the entire substring, we only update the frequency of one character.

This is what makes the solution efficient.


7.
int maxi = 0;
Stores the maximum frequency in the current substring.


8.
int mini = INT_MAX;
Stores the minimum frequency among characters that appear.


9.
for (int k = 0; k < 26; k++)
Traverse all lowercase letters.

There are only 26, so this loop is considered constant time.


10.
if(freq[k] > 0)
Ignore characters that do not appear.

Only characters with positive frequency participate in beauty calculation.


11.
maxi = max(maxi, freq[k]);
Find the largest frequency.


12.
mini = min(mini, freq[k]);
Find the smallest non-zero frequency.


13.
ans += (maxi - mini);
Beauty of the current substring is

Maximum Frequency
        -
Minimum Non-zero Frequency
Add it to the final answer.


14.
return ans;
Return the total beauty of all substrings.

Why do we create freq only once for each i?
Suppose

s = "abcde"
When

i = 0
Substrings are

a
ab
abc
abcd
abcde

Instead of counting frequencies from scratch every time,

a
↓
ab
↓
abc
↓
abcd

we simply add the newly appended character.
This saves a lot of work.
Why don't we recreate freq inside the j loop?
If we wrote

for(int j=i;j<n;j++)
{
    vector<int> freq(26,0);
}
then every substring would start with an empty frequency array, and we'd have to count all characters again.
That would increase the complexity to approximately O(N³).
Keeping freq outside the inner loop lets us reuse the counts while extending the substring.

Complexity : 

Time Complexity
Outer loop → O(N)
Inner loop → O(N)
Frequency scan → 26 (constant)
Overall:

O(N × N × 26)
≈ O(N²)
Space Complexity
Only one frequency array of size 26 is used:

O(26)
≈ O(1)

------------------------------------------------------------------------------------------------------------------------- */