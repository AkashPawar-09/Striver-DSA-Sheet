/*
------------------------------Division hashing ---------------------------

Division hashing is a hash function technique 
used to map a key to an index in a hash table 
using the modulus operation.


it uses mathematical equation : 

h(k) = k mod m

k = key (input value)
m = size of hash table
h(k) = index where key is stored

Division hashing = key % table_size
Performance depends on table size (m)
Use prime number for m
Collisions must be handled separately
Fast but not always optimal


Properties :

Very simple to compute
Fast → O(1)
Works well for many distributions

Deterministic : Same key → always same index

Uniform Distribution : Spread keys evenly , Avoid clustering

Fast Computation : Modulo is constant time


Collision happen because : 
k1​ mod m = k2 ​mod m
when two different keys map to the same index in a hash table.


Properties :

Collision handling methods used to :
Chaining
Open addressing (linear probing, quadratic probing, double hashing)




*/