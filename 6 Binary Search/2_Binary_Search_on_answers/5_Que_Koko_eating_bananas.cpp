/* =====================================    CODE GIVEN AT LAST    =======================================================

+---------------------------------------------------+
|   Koko Eating Bananas (Binary Search on Answer)   |
+---------------------------------------------------+

----------------+
Question:       |===>
----------------+
Given n piles of bananas where piles[i] is the number of bananas in the ith pile.

Koko has h hours to finish all the bananas.

She chooses an eating speed k (bananas/hour).

Goal:
Find the MINIMUM integer k such that Koko can finish all bananas within h hours.

--------------------------------------------------------------------------------------------------------------------------

--------+
Rules:  |===>
--------+

1. Koko eats from ONLY ONE pile in one hour.

2. She eats at most k bananas in that hour.

3. If a pile has less than k bananas, she eats all of them.

4. After finishing a pile, she CANNOT start another pile in the same hour.

--------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------

Example:

piles = [3,6,7,11]
h = 8

There are 4 piles:

Pile 1 --> 3 bananas
Pile 2 --> 6 bananas
Pile 3 --> 7 bananas
Pile 4 --> 11 bananas

We need the minimum eating speed.

--------------------------------------------------------------------------------------------------------------------------

Try k = 1

Hours required:

3 -> 3 hours
6 -> 6 hours
7 -> 7 hours
11 -> 11 hours

Total = 3 + 6 + 7 + 11 = 27 hours

27 > 8
Not Possible

--------------------------------------------------------------------------------------------------------------------------

Try k = 2

Hours for each pile:

ceil(3/2) = 2
ceil(6/2) = 3
ceil(7/2) = 4
ceil(11/2) = 6

Total = 2 + 3 + 4 + 6 = 15 hours

15 > 8
Not Possible

--------------------------------------------------------------------------------------------------------------------------

Try k = 3

ceil(3/3) = 1
ceil(6/3) = 2
ceil(7/3) = 3
ceil(11/3) = 4

Total = 1 + 2 + 3 + 4 = 10 hours

10 > 8
Not Possible

--------------------------------------------------------------------------------------------------------------------------

Try k = 4

Pile 3:
Hour 1 -> Eat 3 -> Finish

Pile 6:
Hour 2 -> Eat 4 (Remaining 2)
Hour 3 -> Eat 2 -> Finish

Pile 7:
Hour 4 -> Eat 4 (Remaining 3)
Hour 5 -> Eat 3 -> Finish

Pile 11:
Hour 6 -> Eat 4 (Remaining 7)
Hour 7 -> Eat 4 (Remaining 3)
Hour 8 -> Eat 3 -> Finish

Hours:

3  -> 1
6  -> 2
7  -> 2
11 -> 3

Total = 1 + 2 + 2 + 3 = 8 hours

Possible

--------------------------------------------------------------------------------------------------------------------------

Try k = 5

ceil(3/5) = 1
ceil(6/5) = 2
ceil(7/5) = 2
ceil(11/5)= 3

Total = 8 hours

Possible

--------------------------------------------------------------------------------------------------------------------------

Possible Speeds:

k = 1 -> No
k = 2 -> No
k = 3 -> No
k = 4 -> Yes
k = 5 -> Yes
k = 6 -> Yes
...

Question asks for MINIMUM valid speed.

Answer = 4

--------------------------------------------------------------------------------------------------------------------------

Why do we use ceil() ?

Example:

Pile = 7
Speed = 4

Hour 1 -> Eat 4
Remaining = 3

Hour 2 -> Eat 3

Total = 2 hours

7 / 4 = 1.75

Since we cannot take fractional hours,

ceil(1.75) = 2

Formula:

hours = ceil((double)pile / k);

OR (Integer Formula)

hours = (pile + k - 1) / k;

--------------------------------------------------------------------------------------------------------------------------

Observation (Binary Search on Answer)

As speed increases,
required hours decrease or remain same.

Speed : Hours

1 -> 27
2 -> 15
3 -> 10
4 -> 8
5 -> 8
6 -> 6
7 -> 5
...

---------------------------------------------------------------------------
Pattern:

No  No  No  Yes  Yes  Yes ...

Once a speed works,
every larger speed also works.

This monotonic property allows Binary Search.

---------------------------------------------------------------------------
Search Space:

Minimum speed = 1
Maximum speed = max(piles)

---------------------------------------------------------------------------
Answer lies between:

[1 , max(piles)]

---------------------------------------------------------------------------
Time Complexity:
O(n * log(max(piles)))

Space Complexity:
O(1)

======================================================================================================================= */