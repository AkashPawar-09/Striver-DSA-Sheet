#include<bits/stdc++.h> 
using namespace std ;






// while loop for printing table of number 

// int main (){
//     int n = 1 ;
//     int num ;
//     cout << "Enter number to make table of it : ";
//     cin >> num ;

//     cout<< "table of number is : "<< endl ;

//     while (n<11){
//         cout << num << " * " << n << " =  " << num*n << endl;
//         n++ ;
//     }
// }









/*
while loop making right angled triangle star patter 

* 
* *
* * *
* * * *
* * * * * 
* * * * * *

*/

// int main (){
//     int i = 1 , n ;
//     cout << "Enter height / base of triangle : ";
//     cin >> n ;
//     while (i<=n){
//         int j = 1 ;
//         while (j<=i){
            
//             cout<<"* ";
//             j++ ;
//         }
//         cout << endl ;
//         i++;
//     }
//     return 0 ;
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
//     int i = 1 , n ;
//     cout << "Enter Length of Square : ";
//     cin >> n ;
//     while (i<=n){
//         int j = 1 ;
//         while (j<=n){
//             cout<<"* ";
//             j++ ;
//         }
//         cout<<endl ;
//         i++;
//     }
//     return 0 ;
// }










/* while loop making parallelogram pattern  

     * * * * * * 
    * * * * * * 
   * * * * * * 
  * * * * * * 
 * * * * * * 
* * * * * * 
*/

// int main(){
//     int i = 1 , n ;

//     cout << "Enter side of parallelogram : ";
//     cin >> n ;

//     while (i<=n){
//         int space = n-i ;
//         int j = 1 ;

//         while (space >= 1)
//         {
//             cout<< " ";
//             space--;
//         }

//         while (j <= n) 
//         {
//             cout<<"* ";
//             j++ ;
//         }
    
//         cout<<endl;
//         i++ ;
//     }
//     return 0 ;
// }








/* while loop making right angled right side triangle pattern

     * 
    * *
   * * *
  * * * *
 * * * * *
* * * * * *

*/


// int main(){
//     int i = 1, n;

//     cout << "Enter height of equilateral triangle : ";
//     cin >> n;

//     while (i <= n){
//         int space = n - i;   // reset every row
//         int j = 1;

//         // print spaces
//         while (space >= 1){
//             cout << " ";
//             space--;
//         }

//         // print stars
//         while (j <= i){
//             cout << "* ";
//             j++;
//         }

//         cout << endl;
//         i++;
//     }

//     return 0;
// }







/* while loop making right angled right side triangle pattern

          * 
        * *
      * * *
    * * * *
  * * * * * 
* * * * * *

*/



// int main(){
//     int i = 1 , n ;

//     cout << "Enter height of triangle : ";
//     cin >> n ;

//     while (i<=n){
//         int space = n-i ;
//         int j = 1 ;

//         while (space >= 1)
//         {
//             cout<< "  ";          // IMPORTANT SPACE IS ALWAYS 2 
//             space--;
//         }

//         while (j <= i) 
//         {
//             cout<<"* ";
//             j++ ;
//         }
    
//         cout<<endl;
//         i++ ;
//     }
//     return 0 ;
// }






/*
while loop making number patter 

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6

*/

// int main (){
//     int i = 1 , n ;
//     cout << "Enter height of number triangle : ";
//     cin >> n ;
//     while (i<=n){
//         int j = 1 ;
//         while (j<=i){
            
//             cout<<" "<<j;
//             j++ ;
//         }
//         cout << endl ;
//         i++;
//     }
//     return 0 ;
// }






/*
while loop making number patter 

1
2 2 
3 3 3
4 4 4 4
5 5 5 5 5
6 6 6 6 6 6

*/

// int main (){
//     int i = 1 , n ;
//     cout << "Enter height of number triangle : ";
//     cin >> n ;
//     while (i<=n){

//         int j = 1 ;
//         while (j<=i){
            
//             cout<< i << " ";
//             j++ ;
//         }

//         cout << endl ;
//         i++;
//     }
//     return 0 ;
// }






/* 
while loop making star patter 

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

//     int i = n ;

//     while (i>=1){
//         int j = 1 ;

//         while(j <= i){
//             cout<<"* ";
//             j++ ;
//         }

//         cout<<endl;
//         i--;
//     }

//     return 0 ;
// }






/*
while loop making star patter 

1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/

// int main (){
//     int i = 1 , n ;
//     cout << "Enter height of number triangle : ";
//     cin >> n ;
//     while (i<=n){
//         int j = 1 ;
//         while (j<=n-i+1){
            
//             cout<<j<< " ";
//             j++ ;
//         }
//         cout << endl ;
//         i++;
//     }
//     return 0 ;
// }








/*
Half Diamond Star Pattern

*
* *
* * *
* * * *
* * * * * 
* * * * * * 
* * * * * * *
* * * * * * 
* * * * * 
* * * * 
* * * 
* *
*

*/

// int main (){
//     int n ;
//     cout << " Enter height half : ";
//     cin >> n ;

//     int i = 1 ;

//     while(i<= n) {
//         int j = 1 ;
//         while(j <= i){
//             cout<< "* " ;
//             j++ ;
//         }
//         cout << endl;
//         i++;
//     }


//     i = n - 1;
//     while (i >= 1 ) {
//         int j = 1;
//         while (j <= i) {
//             cout << "* ";
//             j++;
//         }
//         cout << endl;
//         i--;
//     }
//     return 0;
// } 







/*
Diamond Star Pattern 

          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
* * * * * * * * * * *
  * * * * * * * * *
    * * * * * * *
      * * * * *
        * * *
          *
*/

// int main(){
//     int n ;
//     cout << "Enter hight of diamond star pattern : ";
//     cin >> n ;
//     int i = 1 ;

//     // Upper part of triangle 

//     while (i<=n){
//         int space = n - i ;
//         while (space--){
//           cout<<"  ";
//         }     
//         int j = 1 ;
//         while ( j <= 2*i - 1){
//           cout << " *" ;
//           j++ ;
//         }
//         cout<<endl ;
//         i++ ;
//     }

//     // Lower part of triangle 
//     i = n - 1 ;
//     while (i >= 1){
//         int space = n - i;

//         while (space--){
//             cout<< "  ";
//         }

//         int j = 1;
//         while (j <= 2*i - 1){
//             cout << " *";
//             j++;
//         }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
//       cout<<endl ;
//       i-- ;
//     }
// }





