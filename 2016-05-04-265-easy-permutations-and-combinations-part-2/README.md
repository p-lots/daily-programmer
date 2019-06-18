Basically the same challenge as Monday's, but with much larger numbers and so code that must find permutation and combination numbers without generating the full list.

# Permutation number

https://en.wikipedia.org/wiki/Factorial_number_system is the traditional technique used to solve this, but a very similar recursive approach  can calculate how many permutation indexes were skipped in order to set the next position.

**Input:**  
what is the 12345678901234 permutation index of 42-length list

**Output:**

```
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 35 32 36 34 39 29 27 33 26 37 40 30 31 41 28 38
```

**Input 2:**  

```
what is the permutation number of:  25 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 35 32 36 34 39 29 27 33 26 37 40 30 31 41 28 38
```

**Output2:**  

```
836313165329095177704251551336018791641145678901234
```

# Combination number

https://en.wikipedia.org/wiki/Combinatorial_number_system and https://msdn.microsoft.com/en-us/library/aa289166%28VS.71%29.aspx show the theory.

It may also be useful to know that the number of combinations of 4 out of 10 that start with 0 1 2 3 4 5 6 are (in J notation `!` is out of operator)

```
3 ! 9 8 7 6 5 4 3 
84 56 35 20 10 4 1
```

with the last combination `6 7 8 9` (84 combinations for 4 out of 10 start with 0, 56 start with 1...)

**Input:**  (find the combination number)

```
0 1 2 88  from 4 out of 100
```

**Output:**

```
85
```

**Challenge input:**  (find the combination number)

```
0 1 2 88 111  from 5 out of 120
15 25 35 45 55 65 85 from 7 out of 100
```

**Challenge input 2**  
what is the 123456789 combination index for 5 out of 100

**Bonus:**  
how many combinations from `30 out of 100` start with `10 30 40`

**Bonus2:**  
write a function that compresses a sorted list of numbers based on its lowest and highest values.  Should return: low, high, count, combination number.

example list:  
`15 25 35 45 55 65 85`

output with missing combination number (x):  
`15 85 7 x`

https://www.reddit.com/r/dailyprogrammer/comments/4htg9t/20160504_challenge_265_easy_permutations_and/
