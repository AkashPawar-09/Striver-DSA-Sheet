#include<bits/stdc++.h> 
using namespace std ;




/*

int main (){
    for(initilization ; condition ; updation )
}

*/

// printing table of any number 

// int main (){
//     int n = 1 ;
//     cout << "Enter your number for table : ";
//     cin >> n ;
//     for(int i = 1 ; i <= 10 ; i++ ){
//         cout<< i << " * " << n << " = " <<i*n << endl ;
//     }
// }






/*
for loop making right angled triangle star patter 

* 
* *
* * *
* * * *
* * * * * 
* * * * * *

*/

// int main (){
//     int n ;
//     cout << "Enter height / base of triangle : ";
//     cin >> n ;
//     for (int i = 1 ; i <=n ; i++){
//         for (int j = 1 ; j <= n - i + 1 ; j++){
//             cout << " *" ;
//         }
//     cout<< endl ;
//     }
// }






/*
while loop making star patter 

* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *

*/

// int main (){
//     int n ;
//     cout << "Enter height / base of triangle : ";
//     cin >> n ;
//     for (int i = 1 ; i <= n ; i++ ){
//         for (int j = 1 ; j <= n ; j++ ){
//             cout << "* ";
//         }
//     cout << endl ;
//     }
// }






/* for loop making right angled right side triangle pattern

     * 
    * *
   * * *
  * * * *
 * * * * *
* * * * * *

*/

// int main() {
//     int n;
//     cout << "Enter base of triangle : ";
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n - i; j++) {
//             cout << "  ";
//         }
//         for (int j = 1; j <= i; j++) {
//             cout << "* ";
//         }
//         cout << endl;
//     }

//     return 0;
// }






/*

Printing lower triangle by for loop 

* * * * * * *
  * * * * *
   * * * *
    * * *
     * *
      *

*/

// int main (){
//     int n ;
//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     for (int i = n ; i>=1 ; i--){
//         for (int j = 1; j <= n-i+1 ; j++) {
//             cout << " ";
//         }
//         for (int j = 1 ; j <= i ; j++ ){
//             cout << "* ";
//         }
//     cout<< endl ;
//     }
// }






/*

Printing lower triangle by for loop 

  * * * * * 
    * * * *
      * * *
        * *
          *
          
*/

// int main (){
//     int n ;
//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     for (int i = n ; i>=1 ; i--){
//         for (int j = 1; j <= n-i+1 ; j++) {
//             cout << "  ";
//         }
//         for (int j = 1 ; j <= i ; j++ ){
//             cout << "* ";
//         }
//     cout<< endl ;
//     }
// }




/*
for loop making number patter 

 1
 2 2
 3 3 3
 4 4 4 4
 5 5 5 5 5
 6 6 6 6 6 6
 7 7 7 7 7 7 7

*/

// int main (){
//     int n ;
//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     for (int i = 1 ; i <= n ; i++) {
//         for(int j = 1 ; j <= i ; j++){
//             cout <<  " " << i  ;
//         }
//     cout << endl ;
//     }
// }





/*
for loop making number patter 

 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
 1 2 3 4 5 6

*/

// int main (){
//     int n ;
//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     for (int i = 1 ; i <= n ; i++) {
//         for(int j = 1 ; j <= i ; j++){
//             cout <<  " " << j  ;
//         }
//     cout << endl ;
//     }
// }





/* 
for loop making star patter 

* * * * * *
* * * * *
* * * *
* * *
* *
*

*/

// int main (){
//     int n ;
//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     for (int i = 1 ; i <= n ; i++) {
//         for (int j = n ; j >= i ; j--){
//             cout << " *" ;
//         }
//     cout << endl ;
//     }
// }



/*
for loop making hollow square 

* * * * * *
*         *
*         *
*         *
*         *
* * * * * *

*/


// int main (){
//   int n ;
//   cout << "Enter height of square : ";
//   cin >> n ;

//   for (int i = 1 ; i<= n ; i++){
//     for (int j = 1 ; j <= n ; j++){
//       if (i==1 || j==1 || i==n || j==n){
//         cout<< "* ";
//       }
//       else {
//         cout << "  ";
//       }
//     }

//     cout<< endl ;
//   }
//   return 0 ;
// }







/*

Printing 1/0 by for loop 

1
01
101
0101
10101
010101

*/
// int main() {
//     int n;
//     cout << "Enter Number to print tranglr in 1/0 : ";
//     cin >> n;

//     for (int i = 1; i <= n; i++) {
//         int num;

//         if (i % 2 == 0)
//             num = 0;
//         else
//             num = 1;

//         for (int j = 1; j <= i; j++) {
//             cout << num;

//             if (num == 1)
//                 num = 0;
//             else
//                 num = 1;
//         }

//         cout << endl;
//     }

//     return 0;
// }
