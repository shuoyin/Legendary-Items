# Legendary-Items
This is my answer for onlie judge problem  *Legendary Items* which can be found [here](http://hihocoder.com/problemset/problem/1489?sid=1078755).

### Solving Idea
Use dynamic programming.<br>
Use *K(n)* to illustrate the expected number of quests, *n* is the number of legendary items we want to get.<br>
We have `K(n) = P1\*(K(n-1)+1) + P2\*(K(n-1)+2) + ... `, where `Pi` is the probability that the first legendary items cost i quests. `Pi=(1-p1)\*(1-p2)\*...\*pi`, where `pk=p1+Q*(k-1)`. `p1` is the probability that get the first legendary items at the first quest.<br>
Now we have the recursive formula. It a sum of many sub-formulas. If you rearrange it to a form like`K(n) = A*K(n-1)+B`, you can use recursion to solve this problem.
