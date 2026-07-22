/* ------------------------------------------------- Manacher's Algorithm -------------------------------------------------

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Input: s = "cbbd"
Output: "bb"

------------------------------------------------------------------------------------------------------------------------- */


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {

        string ms = "@";

        for (char c : s) {
            ms += "#";
            ms += c;
        }
        ms += "#$";

        int m = ms.size();
        vector<int> p(m, 0);

        int l = 0, r = 0;

        for (int i = 1; i < m - 1; i++) {

            if (i < r) {
                p[i] = min(r - i, p[l + r - i]);
            }

            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                p[i]++;
            }

            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }

        int start = 0;
        int maxLen = 1;

        for (int i = 1; i < m - 1; i++) {

            int len = p[i];

            if (len > maxLen) {
                maxLen = len;
                start = (i - len) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};


int main() {
    Solution obj;

    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << obj.longestPalindrome(s) << endl;

    return 0;
}

// Time Complexity : O(N²)
// Space Complexity : O(1)

/* --------------------------------------------------------------------------------------------------------------------------

Manacher's Algorithm (Longest Palindromic Substring)
Manacher's Algorithm is the fastest algorithm to find the Longest Palindromic Substring in a string.

Time Complexity: O(N)
Space Complexity: O(N)
Why do we need Manacher's Algorithm?
Suppose the string is

abba
It has an even-length palindrome.

Now consider

aba
It has an odd-length palindrome.

Handling odd and even palindromes separately makes the algorithm more complicated.

So Manacher converts every palindrome into an odd-length palindrome by inserting # between every character.

Example:

Original : aba
Modified : @#a#b#a#$
Original : abba
Modified : @#a#b#b#a#$
@ and $ are sentinels that prevent index out-of-bounds.

Variables used
ms
Modified string.

Example

s  = forgeeksskeegfor

ms = @#f#o#r#g#e#e#k#s#s#k#e#e#g#f#o#r#$
p
p[i] stores the radius of the palindrome centered at i.

Example

ms = @#a#b#a#$

Index:
0 1 2 3 4 5 6 7 8

Chars:
@ # a # b # a # $

p:
0 0 1 0 3 0 1 0 0
At center 'b'

#a#b#a#
Radius = 3

So

p[4]=3;
l
Left boundary of the current longest palindrome.

r
Right boundary of the current longest palindrome.

Current known palindrome is

l...............r
Everything inside is already processed.

Constructor
ms="@";
Starts modified string.

for(char c:s)
{
    ms+="#"+string(1,c);
}
Adds # before every character.

Example

abc
becomes

@#a#b#c
ms+="#$";
Adds ending sentinel.

Final

@#a#b#c#$
runManacher();
Runs the algorithm.

runManacher()
int n=ms.size();
Length of modified string.

p.assign(n,0);
Initially every radius is zero.

int l=0,r=0;
Initially no palindrome exists.

for(int i=1;i<n-1;i++)
Visit every possible center.

Mirror concept
Suppose

      l             r
      |             |
@#a#b#c#b#a#$
        ^
        center



If
i
is inside

[l,r]
then its mirror is

mirror=l+r-i
if(r+l-i>=0 && r+l-i<n)
Checks whether mirror exists.

p[i]=max(0,min(r-i,p[r+l-i]));
This is the most important line.

It copies already known information.

Instead of expanding from zero every time,

we copy

mirror radius
or

remaining distance till r
whichever is smaller.

So expansion becomes much faster.

Expansion
while(ms[i+1+p[i]]==ms[i-1-p[i]])
Try expanding.

If left and right characters match,

increase radius.

++p[i];
Palindrome grows by one character.

Update boundaries
if(i+p[i]>r)
If newly found palindrome goes farther than current right boundary,

update it.

l=i-p[i];
New left boundary.

r=i+p[i];
New right boundary.

getLongest()
int pos=2*cen+2+!odd;
Original string index and modified string index are different.

This formula converts

Original index

↓

Modified index.

Examples

Original

a b c
Modified

@ # a # b # c # $
Original index 0 → Modified index 2
Original index 1 → Modified index 4
Original index 2 → Modified index 6
return p[pos];
Returns radius stored there.

check()
int res=getLongest(...);
Gets palindrome radius.

return (r-l+1)<=res;
If required substring length is smaller than radius,

then it is a palindrome.

Finding answer
for(int i=0;i<n;i++)
Checks every original character as center.

oddLen=M.getLongest(i,1);
Longest odd palindrome.

evenLen=M.getLongest(i,0);
Longest even palindrome.

if(oddLen>maxLen)
Update answer.

start=i-(oddLen-1)/2;
Calculates starting index in original string.

if(evenLen>maxLen)
Update for even palindrome.

start=i-(evenLen-1)/2;
Starting index.

maxLen=max(maxLen,max(oddLen,evenLen));
Stores longest palindrome found so far.

return s.substr(start,maxLen);
Returns the longest palindromic substring.

Why is it O(N)?
Normally, expanding around every center can revisit the same characters many times (O(N²)).

Manacher avoids this by:

Keeping the current palindrome boundaries [l, r].
Using the mirror of the current center to initialize the radius instead of starting from 0.
Expanding only when necessary beyond the known boundary.
Because each character contributes to at most a constant amount of new expansion beyond the current right boundary, 
the total work across the entire string is linear, giving O(N) time complexity.






Dry Run of Manacher's Algorithm
Input
s = "babad"
Step 1: Transform the string

Insert # between every character and add sentinels.

Original : b a b a d
Modified : @ # b # a # b # a # d # $

| Index |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |
| ----: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  Char |  @  |  #  |  b  |  #  |  a  |  #  |  b  |  #  |  a  |  #  |  d  |  #  |  $  |


Initially

p = [0 0 0 0 0 0 0 0 0 0 0 0 0]
l = 0
r = 0

Dry Run

______________________________________________________________________________________
|  i | Char | Mirror | Initial p[i] | Expansion Result      | Final p[i] |  l  |  r  |
| -: | :--: | :----: | :----------: | :-------------------- | :--------: | :-: | :-: |
|  1 |   #  |    -   |       0      | No expansion          |      0     |  1  |  1  |
|  2 |   b  |    0   |       0      | `#=#` → radius=1      |      1     |  1  |  3  |
|  3 |   #  |    1   |       0      | No expansion          |      0     |  1  |  3  |
|  4 |   a  |    0   |       0      | `#=#`,`b=b`,`#=#`     |      3     |  1  |  7  |
|  5 |   #  |    3   |       0      | No expansion          |      0     |  1  |  7  |
|  6 |   b  |    2   |       1      | Cannot expand further |      1     |  1  |  7  |
|  7 |   #  |    1   |       0      | No expansion          |      0     |  1  |  7  |
|  8 |   a  |    0   |       0      | `#=#`,`d≠b`           |      1     |  7  |  9  |
|  9 |   #  |    7   |       0      | No expansion          |      0     |  7  |  9  |
| 10 |   d  |    6   |       0      | `#=#`                 |      1     |  9  |  11 |
| 11 |   #  |    9   |       0      | No expansion          |      0     |  9  |  11 |


How each expansion happened
i = 2 ('b')

Center

@ # b # a # b # a # d # $
    ^

Compare

# == #

Palindrome

#b#

Radius = 1

i = 4 ('a')

Center

@ # b # a # b # a # d # $
        ^

Expansion

# == #
b == b
# == #

Palindrome becomes

#b#a#b#

Radius = 3

This corresponds to

bab

Update

l = 1
r = 7
i = 6 ('b')

Mirror index

mirror = l + r - i
       = 1 + 7 - 6
       = 2

Already know

p[2]=1

So

p[6]=1

No further expansion possible.

This is where Manacher saves time.

i = 8 ('a')

Expand

# == #

Next

d != b

Stop.

Radius = 1

i = 10 ('d')

Expand

# == #

Stop.

Radius = 1

Final p Array
______________________________________________________________________________________
| Index |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 |  11 |  12 |
| ----: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|  Char |  @  |  #  |  b  |  #  |  a  |  #  |  b  |  #  |  a  |  #  |  d  |  #  |  $  |
|  p[i] |  0  |  0  |  1  |  0  |  3  |  0  |  1  |  0  |  1  |  0  |  1  |  0  |  0  |


Finding the answer

The largest value in p[] is

p[4] = 3

Compute the starting index:

start = (4 - 3) / 2
      = 0

Length:

maxLen = 3

Substring:

s.substr(0,3)

Output

"bab"

("aba" is also a valid answer, but this implementation finds "bab" first.)

-------------------------------------------------------------------------------------------------------------------------- */