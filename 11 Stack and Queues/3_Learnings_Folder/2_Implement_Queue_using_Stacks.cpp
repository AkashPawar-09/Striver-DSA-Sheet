#include <bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
        // Empty 
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int x = output.top();
        output.pop();
        return x;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Peek: " << q.peek() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;

    cout << "Empty: " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}



// Time Complexity : O(1)  FOR ALL OPERATIONS 
// Space Complexity : O(N)


/* --------------------------------------------------------------------------------------------------------------------


Example: push(10) , push(20) , push(30) , push(40) 
Que. pop() ;

therefore : top is 40 then 30 then 20 then 10 , which is represented from (right to left)) as (top to bottom)
________________________________________________________________________________________________________
| Step | Code / Condition                 | input         | output        | Action            | Result |
| ---- | -------------------------------- | ------------- | ------------- | ----------------- | ------ |
| 1    | Before pop()                     | [10,20,30,40] | []            | Start             | -      |
| 2    | if (output.empty())              | [10,20,30,40] | []            | TRUE → enter if   | -      |
| 3    | while (!input.empty())           | [10,20,30,40] | []            | TRUE              | -      |
| 4    | output.push(input.top())         | [10,20,30,40] | [40]          | Move 40           | -      |
| 5    | input.pop()                      | [10,20,30]    | [40]          | Remove 40         | -      |
| 6    | while (!input.empty())           | [10,20,30]    | [40]          | TRUE              | -      |
| 7    | output.push(input.top())         | [10,20,30]    | [40,30]       | Move 30           | -      |
| 8    | input.pop()                      | [10,20]       | [40,30]       | Remove 30         | -      |
| 9    | while (!input.empty())           | [10,20]       | [40,30]       | TRUE              | -      |
| 10   | output.push(input.top())         | [10,20]       | [40,30,20]    | Move 20           | -      |
| 11   | input.pop()                      | [10]          | [40,30,20]    | Remove 20         | -      |
| 12   | while (!input.empty())           | [10]          | [40,30,20]    | TRUE              | -      |
| 13   | output.push(input.top())         | [10]          | [40,30,20,10] | Move 10           | -      |
| 14   | input.pop()                      | []            | [40,30,20,10] | Remove 10         | -      |
| 15   | while (!input.empty())           | []            | [40,30,20,10] | FALSE → exit loop | -      |
| 16   | x = output.top()                 | []            | [40,30,20,10] | x = 10            | 10     |
| 17   | output.pop()                     | []            | [40,30,20]    | Remove 10         | -      |
| 18   | return x                         | []            | [40,30,20]    | Return 10         | 10     |


--------------------------------------------------------------------------------------------------------------------


Example: push(10) , push(20) , push(30) , push(40) 
Que. peek() ;

________________________________________________________________________________________________
| Step | Code / Condition         | input         | output        | Action            | Result |
| ---- | ------------------------ | ------------- | ------------- | ----------------- | ------ |
| 1    | Before peek()            | [10,20,30,40] | []            | Start             | -      |
| 2    | if (output.empty())      | [10,20,30,40] | []            | TRUE → enter if   | -      |
| 3    | while (!input.empty())   | [10,20,30,40] | []            | TRUE              | -      |
| 4    | output.push(input.top()) | [10,20,30]    | [40]          | Move 40           | -      |
| 5    | input.pop()              | [10,20,30]    | [40]          | Remove 40         | -      |
| 6    | while (!input.empty())   | [10,20,30]    | [40]          | TRUE              | -      |
| 7    | output.push(input.top()) | [10,20]       | [40,30]       | Move 30           | -      |
| 8    | input.pop()              | [10,20]       | [40,30]       | Remove 30         | -      |
| 9    | while (!input.empty())   | [10,20]       | [40,30]       | TRUE              | -      |
| 10   | output.push(input.top()) | [10]          | [40,30,20]    | Move 20           | -      |
| 11   | input.pop()              | [10]          | [40,30,20]    | Remove 20         | -      |
| 12   | while (!input.empty())   | [10]          | [40,30,20]    | TRUE              | -      |
| 13   | output.push(input.top()) | []            | [40,30,20,10] | Move 10           | -      |
| 14   | input.pop()              | []            | [40,30,20,10] | Remove 10         | -      |
| 15   | while (!input.empty())   | []            | [40,30,20,10] | FALSE → exit loop | -      |
| 16   | return output.top()      | []            | [40,30,20,10] | Read top element  | **10** |


Important: peek() only reads the front element. It does not remove 10.

Final: peek() → 10
_________________________
| input | output        |
| ----- | ------------- |
| []    | [40,30,20,10] |

-------------------------------------------------------------------------------------------------------------------- */