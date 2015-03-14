# Things I want to do

- Rehink the build and execution system to minimize compile time.

Problems I want to do:
    - Problem 22
    - Problem 33
    - Get rid of GMP where it is not needed.



# Problem 18 and 67
I think that the solution here could be someway related to dynamic programming.
What I have in mind is to first parse the triangle into a DAG (Directed acyclic
graph) and then create a function named F(node) which would be the maximum path
sum to that node.

F(node) would be implemented with a lookup table, terminating a search if
the current value was lower than that of the current chain. This would reduce
the amount of paths that would have to be visited dramatically and cut the
needed computations by orders of magnitude.

What is yet to see is if this is indeed fast enough, especially for problem 67.

A note about the answer is that it must be a natural number x so that:

Problem 18:  15*1  <= x <= 99*15  <=> 15  <= x <= 1485
Problem 67:  100*1 <= x <= 99*100 <=> 100 <= x <= 9900

This means that we can operate with unsigned 16-bit integers, for added
performance.

# Problem 34
We only need to test up to 7 digits as that is when n * 9! no longer exceeds
the maximum 7 digit number.

# Problems I want to clean up.
## Problem 349
This solution is very fast and is working great, but I feel like I added some
uneeded complexity to it, that I could strip away. The goal of these exercises
is not to write a lot of code to solve one problem.

I am unsure if I want to go for a mathematical formula, as some of the fun was
computing the first part before going on to looping 104 steps.

# Problem 2
Optimize problem 2, since each third term will be even.

# Problem 12
Things could really be a lot quicker here. Look at the summary.

# Problem 81-83
I think I have implemented 81 and 83 in an okay matter. The running time is not
superb, but it will have to do for now, before I go over and optimize all my
solutions.

Problem 82 is a problem however! I have only ran the solution once, and it
gave me the correct answer, but it did so in about 10 minutes. This is way to
slow for a speedster such as myself. I think a complete rethink of the problem
is required to do this. It will involve dynamic programming of some kind, that
I know.

Another idea is to run dijsktra repetadly. I wonder if this could work better
than what we currently have. It is worth a try.

# Things I want to implement
    - Integer factorization
