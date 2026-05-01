/*
hashing 


Hashing = storing data in a way that allows fast access (O(1) time).

properties :
Instead of searching linearly (O(n)), hashing directly jumps to the value using a key → index mapping.

without hasing :
find frequency of 5
for(int i=0;i<n;i++) if(arr[i]==5) count++;
O(n)

for big data it takes more time like data for 10 ^ 5 


-------------------------------------------

Without hashing:

Each query = O(n)
Total = O(n * q) 

------------------------------------------------------------------------------

With hashing:

Build = O(n)
Each query = O(1)
Total = O(n + q) 

------------------------------------------------------------------------------

you can declare array in int main       -----> 10 ^ 6
you can declare array outside int main  -----> 10 ^ 7

*/






