# Taha Kinali - Assignment 5 - Report - Grade: `95`

- Test 0 ---> `15 of 20` Points
- Test 1 ---> `15 of 15` Points
- Test 2 ---> `15 of 15` Points
- Test 3 ---> `15 of 15` Points
- Test 4 ---> `15 of 15` Points

## Coding
- Comments: 

## Submission
- Comments: 

## Compile Log


```
gcc taha_kinali.1901042660.c -o executable -lm

```


## Test Logs

### Test 0

------

```
Thread Started
STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- STDIN 

```
Bicycle
2*Wheel+1*Frame
1*Rim+28*Spoke+1*Hub
60.0
12.0
6*Gear+1*Axle
25.0
7*Nut+5*Bolt
0.15
0.1
1*Rearframe+1*Frontframe
170.0
1*Fork+1*Handle
21.5
12.0

```

- Correct STDOUT 

```
Define the object:
What is Bicycle?:
What is Wheel?:
What is Rim?:
What is Spoke?:
What is Hub?:
What is Gear?:
What is Axle?:
What is Nut?:
What is Bolt?:
What is Frame?:
What is Rearframe?:
What is Frontframe?
What is Fork?:
What is Handle?:
Total cost of Bicycle is 1298.60

```

- std_output

```

Define the object:

What is Bicycle


What is Wheel

What is Rim

What is Spoke

What is Hub

What is Gear

What is Axle

What is Nut

What is Bolt

What is Frame

What is Rearframe

What is Frontframe

What is Fork

What is Handle
Total cost of 2 is 1295.000000 
```

- diff

```
+ 

  Define the object:

+ 

- What is Bicycle?:

?                --

+ What is Bicycle

+ 

+ 

- What is Wheel?:

?              --

+ What is Wheel

+ 

- What is Rim?:

?            --

+ What is Rim

+ 

- What is Spoke?:

?              --

+ What is Spoke

+ 

- What is Hub?:

?            --

+ What is Hub

+ 

- What is Gear?:

?             --

+ What is Gear

+ 

- What is Axle?:

?             --

+ What is Axle

+ 

- What is Nut?:

?            --

+ What is Nut

+ 

- What is Bolt?:

?             --

+ What is Bolt

+ 

- What is Frame?:

?              --

+ What is Frame

+ 

- What is Rearframe?:

?                  --

+ What is Rearframe

+ 

- What is Frontframe?

?                   -

+ What is Frontframe

+ 

- What is Fork?:

?             --

+ What is Fork

+ 

- What is Handle?:

?               --

+ What is Handle

- Total cost of Bicycle is 1298.60

+ Total cost of 2 is 1295.000000 

```

------

### Test 1

------

```
Thread Started
STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- STDIN 

```
A
1*B
1*C
1*D
1*E
1*F
1*G
1*I
1*J
1*K
1*L
1*N
123
```

- Correct STDOUT 

```
Define the object:
What is A?:
What is B?:
What is C?:
What is D?:
What is E?:
What is F?:
What is G?:
What is I?:
What is J?:
What is K?:
What is L?:
What is N?:
Total cost of A is 123.00

```

- std_output

```

Define the object:

What is A


What is B

What is C

What is D

What is E

What is F

What is G

What is I

What is J

What is K

What is L

What is N
Total cost of 1 is 123.000000 
```

- diff

```
+ 

  Define the object:

+ 

- What is A?:

?          --

+ What is A

+ 

+ 

- What is B?:

?          --

+ What is B

+ 

- What is C?:

?          --

+ What is C

+ 

- What is D?:

?          --

+ What is D

+ 

- What is E?:

?          --

+ What is E

+ 

- What is F?:

?          --

+ What is F

+ 

- What is G?:

?          --

+ What is G

+ 

- What is I?:

?          --

+ What is I

+ 

- What is J?:

?          --

+ What is J

+ 

- What is K?:

?          --

+ What is K

+ 

- What is L?:

?          --

+ What is L

+ 

- What is N?:

?          --

+ What is N

- Total cost of A is 123.00

?               ^          ^

+ Total cost of 1 is 123.000000 
?               ^          ^^^^^


```

------

### Test 2

------

```
Thread Started
STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- STDIN 

```
Object
1*PART1+200*PART2
10*PART3
2000*PART4+1*PART5
1
1
1

```

- Correct STDOUT 

```
Define the object:
What is Object?:
What is PART1?:
What is PART3?:
What is PART4?:
What is PART5?:
What is PART2?:
Total cost of Object is 20210.00

```

- std_output

```

Define the object:

What is Object


What is PART1

What is PART3

What is PART4

What is PART5

What is PART2
Total cost of 1 is 20210.000000 
```

- diff

```
+ 

  Define the object:

+ 

- What is Object?:

?               --

+ What is Object

+ 

+ 

- What is PART1?:

?              --

+ What is PART1

+ 

- What is PART3?:

?              --

+ What is PART3

+ 

- What is PART4?:

?              --

+ What is PART4

+ 

- What is PART5?:

?              --

+ What is PART5

+ 

- What is PART2?:

?              --

+ What is PART2

- Total cost of Object is 20210.00

?               ^^^^^^            ^

+ Total cost of 1 is 20210.000000 
?               ^            ^^^^^


```

------

### Test 3

------

```
Thread Started
STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- STDIN 

```
Bicycle
2*      Wheel+            1          *Frame
10
3

```

- Correct STDOUT 

```
Define the object:
What is Bicycle?:
What is Wheel?:
What is Frame?:
Total cost of Bicycle is 23.00

```

- std_output

```

Define the object:

What is Bicycle


What is Wheel

What is Frame
Total cost of 2 is 23.000000 
```

- diff

```
+ 

  Define the object:

+ 

- What is Bicycle?:

?                --

+ What is Bicycle

+ 

+ 

- What is Wheel?:

?              --

+ What is Wheel

+ 

- What is Frame?:

?              --

+ What is Frame

- Total cost of Bicycle is 23.00

?               ^^^^^^^         ^

+ Total cost of 2 is 23.000000 
?               ^         ^^^^^


```

------

### Test 4

------

```
Thread Started
STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- STDIN 

```
Tree
2*Branch+1000*Leaf
10.3
2*cell
12.0

```

- Correct STDOUT 

```
Define the object:
What is Tree?:
What is Branch?:
What is Leaf?:
What is cell?:
Total cost of Tree is 24020.60

```

- std_output

```

Define the object:

What is Tree


What is Branch

What is Leaf

What is cell
Total cost of 2 is 24020.000000 
```

- diff

```
+ 

  Define the object:

+ 

- What is Tree?:

?             --

+ What is Tree

+ 

+ 

- What is Branch?:

?               --

+ What is Branch

+ 

- What is Leaf?:

?             --

+ What is Leaf

+ 

- What is cell?:

?             --

+ What is cell

- Total cost of Tree is 24020.60

?               ^^^^          - ^

+ Total cost of 2 is 24020.000000 
?               ^           ^^^^^^


```

------
