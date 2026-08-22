#include <bits/stdc++.h>
using namespace std;



class MinStack {
public:
    stack<long long> st;                        // to overcome Runtime Error
    long long minimum;

    MinStack() {
        minimum = INT_MAX;                      // give maximum value for minimum for easy comparision
    }

    void push(int value) {
        long long valuee = value ;
        if(st.empty()) {                        // for starting element in stack 
            st.push(valuee);                    // push it in stack 
            minimum = valuee;                   // then make it minimum 
        }
        else if(valuee >= minimum) {            // if value is greater than minimum 
            st.push(valuee);                    // push it in stack 
        }
        else {                                  // value is samller than current minimum 
            st.push(2 * valuee - minimum);      // push fake element in stack (but gives correct output in other operations)
            minimum = valuee;                   // make the value minimum
        }
    }

    void pop() {
        if(st.top() < minimum) {                // if top element is smaller than minimum (i.e. st.top() is smallest)
            minimum = 2 * minimum - st.top();   // then change the minimum element in current stack
        }
        st.pop();                               // the pop upper element 
    }

    int top() {
        if(st.top() < minimum) {                // if top element is smaller than minimum (i.e. st.top() is smallest)
            return minimum;                     // return that minimum (REAL st.top())
        }
        return st.top();                        // if uppermost is not minimum then return it as it is
    }

    int getMin() {
        return minimum;                         // return calculated minimum
    }
};




int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;

    st.pop();

    cout << "Top: " << st.top() << endl;
    cout << "Min: " << st.getMin() << endl;

    return 0;
}


// Time Complexity : O(1)
// Space Complexity : O(N)


/* --------------------------------------------------------------------------------------------------------------------

if long long is not there infront of minimum and in stack 
there is RUNTIME ERROR : from this teat case ;
-----------------------------------------------------------------------------------------------------------------------
INPUT : 
["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop"
,"push","top","getMin","push","top","getMin","pop","getMin"]

OUTPUT :
[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

-------------------------------------------------------------------------------------------------------------------- */