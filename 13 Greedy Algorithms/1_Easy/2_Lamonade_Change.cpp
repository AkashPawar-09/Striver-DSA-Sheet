#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size() ;
        int count5 = 0 ;
        int count10 = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(bills[i] == 5){
                count5++;
            }
            if(bills[i] == 10){
                count10++;
                count5--;
                if(count5 < 0){
                    return false ;
                }
            }
            if(bills[i] == 20){
                if(count10 > 0 && count5 > 0){
                    count10--;
                    count5--;
                }
                else if(count5 >= 3){
                    count5 = count5 - 3;
                }
                else{
                    return false;
                }
            }
        }
        return true ;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    vector<int> bills(n);
    for(int i = 0; i < n; i++) cin >> bills[i];
    cout << boolalpha << sol.lemonadeChange(bills) << endl;
    return 0;
}