# Sudoku in C

**If we generate all combinations of numbers 1..9 with length 81 we get 9^81 of combinations => BAD!**

### What we will do:

Let's take an example: **3x3 'sudoku'**
        
```
We will check only rows and columns

0 1 0
2 0 1
0 0 3

How it looks like:

solve(0,0)
0 1 0
2 0 1
0 0 3

=> in loop:
    n = 1  (now we check combinations like 1 _ _)
        we find out: found = 1(true)
        digit 1 is not valid for cell [0,0]
        all combinations like 1 _ _ are not valid
        
    n = 2  (now we check combinations like 2 _ _)
        we find out: found = 1(true)
        digit 2 is not valid for cell [0,0]
        all combinations like 2 _ _ are not valid

    n = 3  (now we check combinations like 3 _ _)
        we find out: found = 0(false)
        digit 3 is valid for cell [0,0]
        sudoku[0][0] = n, n = 3

       Now we have:
       
       solve(0,1)
       3 1 0
       2 0 1
       0 0 3

          => we skip this cell, because sudoku[0][1] != 0

             now we are interested only in combinations like 3 1 _
             we skip 3 2 _ and 3 3 _
             
             solve(0,2)
             3 1 0
             2 0 1
             0 0 3

               => in loop:
                  ~ repeat the task ~
```
