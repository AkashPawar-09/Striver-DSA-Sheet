#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;   // number of elements

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int m = 10;   // size of hash table (you can change this)

    // hash table (each index stores multiple elements → chaining)
    vector<vector<int>> hash(m);

    // Division Hashing
    for(int i = 0; i < n; i++){
        int key = arr[i];
        int index = key % m;   // core formula

        hash[index].push_back(key);  // store in bucket
    }

    // Print hash table
    cout << "Hash Table:\n";
    for(int i = 0; i < m; i++){
        cout << i << " -> ";
        for(int x : hash[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}