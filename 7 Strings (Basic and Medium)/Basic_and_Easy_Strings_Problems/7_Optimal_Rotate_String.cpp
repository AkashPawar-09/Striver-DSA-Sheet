/*

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false

*/


#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size())                    // if size of s and goal is not same 
            return false;                               // then return false (saves more time)

        string double_str = s + s;                      // new string named double_str to find s in it

        return (double_str.find(goal) != string::npos); // return true , if s is found in double_str not returning string::npos
    }
};

int main() {
    Solution obj;

    string s, goal;
    cin >> s >> goal;

    if (obj.rotateString(s, goal))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// Time Complexity : O(N)
// Space Complexity : O(N)




/* --------------------------------------------------------------------------------------------------------------------------

What is string::npos?

string::npos is a special constant provided by the C++ string class.
It means:
"No Position Found"

It is returned by functions like:
find()
rfind()
find_first_of()
find_last_of()
etc.

when the requested substring or character does not exist.

Example :
------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main() {

    string s = "Hello";

    cout << s.find("ll") << endl;
    cout << s.find("abc") << endl;

}
------------------------------------------------------------------------------
Output :
2
18446744073709551615

Why such a huge number?

Because : 
string::npos
is actually
size_t(-1)

--------------------------------------------------------------------------------------------------------------------------

What is size_t?

size_t is an unsigned integer type.
It cannot store negative numbers.

Example (64-bit system) : 

Signed int
-2
-1
0
1
2

Unsigned (size_t)
0
1
2
3
...
18446744073709551615

So what happens?
C++ defines

string::npos
as
static const size_t npos = -1;
But remember,

size_t
cannot store
-1

So
-1
wraps around to the largest possible unsigned value.

On most 64-bit systems

18446744073709551615

------------------------------------------------------------------------------

Visualization

Suppose
string s = "apple";
Search

s.find("pl");
apple
  ^^

index = 2
Returns
2

Now search
s.find("xyz");
xyz not present

Returns
string::npos

which is internally
18446744073709551615

Why not return -1?
Because
find()

returns
size_t

not
int

Its return type is
size_t find(...);

Since size_t is unsigned,
it cannot return
-1

So C++ created
string::npos

to represent
Not Found
------------------------------------------------------------------------------

Why do we compare with string::npos?

Suppose
string s = "abcdef";

Searching
s.find("cd")
returns
2

Searching
s.find("xy")

returns
string::npos

Hence
if(s.find("xy") == string::npos)

means
substring not found
Why does != -1 also work?

Suppose
size_t x = -1;
Actually stored as
18446744073709551615
Now

if(find(...) != -1)

becomes
if(find(...) != 18446744073709551615)
which is exactly

if(find(...) != string::npos)
So both work.


Small Example
------------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main() {

    string s = "flower";

    if (s.find("ow") != string::npos)
        cout << "Found";
    else
        cout << "Not Found";

}
------------------------------------------------------------------------------
Output

Found


Search another

if(s.find("xyz") != string::npos)

Output
Not Found


-------------------------------------------------------------------------------------------------------------------------- */