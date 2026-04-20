/*

Input : N=7,arr[]={3,2,8,5,1,4,23}
Output : {1,2,3,4,5,8,23}
Explanation : Given array is sorted in non-decreasing order.

Input : N=5, arr[]={4,2,1,6,7}
Output : {1,2,4,6,7}
Explanation : Given array is sorted in non-decreasing order.

*/





#include<bits/stdc++.h>
using namespace std ;


void merge (vector<int> &arr , int low ,int mid,int high) {
    vector<int> temp ;
    // for 1st half ----> low to mid 
    // for 2nd half ----> mid+1 to high 
    int left = low ;
    int right = mid+1 ;
    while(left <= mid && right <= high ) {
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++ ;
        }
        else {
            temp.push_back(arr[right]) ;
            right++ ;
        }
    }

    while (left <= mid){
        temp.push_back(arr[left]);
        left++ ;
    }

    while (right <= high){
        temp.push_back(arr[right]);
        right ++ ;
    }

    for (int i = low ; i <= high ; i++ ){
        arr[i] = temp[i - low];
    }
}


void mergeSort (vector<int> &arr , int low , int high ) {
    if(low == high ) return ;
    int mid = (low + high ) / 2 ;
    mergeSort (arr , low , mid ) ; 
    mergeSort (arr , mid+1 , high ) ;
    merge(arr , low ,mid , high) ;
}

void mergeSORT (vector<int> &arr ,int n ) {
    mergeSort(arr , 0 , n-1 );

}





int main() {
    int n;
    cin >> n;  

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSORT(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}





