# Taha Kinali - Assignment 3 - Report - Grade: `85`

- Test 0 ---> `20 of 20` Points
- Test 1 ---> `15 of 15` Points
- Test 2 ---> `0 of 15` Points
- Test 3 ---> `15 of 15` Points
- Test 4 ---> `15 of 15` Points

## Coding
- Comments: 

## Submission
- Comments: 

## Compile Log


```
gcc taha_kinali_19010426601.c -o executable -lm

```


## Test Logs

### Test 0

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **circuit.txt**

```
INPUT a b c d
AND and1 a b
OR or1 and1 c
NOT n1 d
FLIPFLOP f1 n1
AND a2 or1 f1

```

- Input File: **input.txt**

```
1 1 0 1
1 0 1 0
1 1 1 0

```

- output file

```

```

- Correct STDOUT 

```
0
1
0

```

- std_output

```
0
1
0

```

- diff

```
  0

  1

  0


```

------

### Test 1

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **circuit.txt**

```
INPUT a b c d e f
AND and1 a b
AND and2 and1 c
AND and3 and2 d
AND and4 and3 e
AND and5 and4 f
```

- Input File: **input.txt**

```
1 1 1 1 1 1
0 0 0 0 0 0
1 0 1 0 1 0
0 0 0 0 0 0
1 0 0 0 0 0
1 1 0 0 0 0 
1 1 1 0 0 0
1 1 1 1 0 0 
1 1 1 1 1 0
1 1 1 1 1 1

```

- output file

```

```

- Correct STDOUT 

```
1
0
0
0
0
0
0
0
0
1

```

- std_output

```
1
0
0
0
0
0
0
0
0
1

```

- diff

```
  1

  0

  0

  0

  0

  0

  0

  0

  0

  1


```

------

### Test 2

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **circuit.txt**

```
INPUT a
FLIPFLOP f1 a
FLIPFLOP f2 f1
FLIPFLOP f3 f2

```

- Input File: **input.txt**

```
1
0
1
0
1
0
1
0

```

- output file

```

```

- Correct STDOUT 

```
1
1
1
1
0
0
0
0

```

- std_output

```
1
1
0
0
1
1
0
0

```

- diff

```
- 1

- 1

  1

  1

  0

  0

+ 1

+ 1

  0

  0


```

------

### Test 3

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **circuit.txt**

```
INPUT a b
OR o1 a b

```

- Input File: **input.txt**

```
1 1
1 0
0 0
0 1
1 1
1 0
0 0
0 1
1 1
1 0
0 0
0 1
1 1
1 0
0 0
0 1
1 1
1 0
0 0
0 1

```

- output file

```

```

- Correct STDOUT 

```
1
1
0
1
1
1
0
1
1
1
0
1
1
1
0
1
1
1
0
1

```

- std_output

```
1
1
0
1
1
1
0
1
1
1
0
1
1
1
0
1
1
1
0
1

```

- diff

```
  1

  1

  0

  1

  1

  1

  0

  1

  1

  1

  0

  1

  1

  1

  0

  1

  1

  1

  0

  1


```

------

### Test 4

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **circuit.txt**

```
INPUT a b
NOT n1 a
NOT n2 b
AND a1 n1 n2

```

- Input File: **input.txt**

```
1 1
1 1
1 1
0 0
0 0
0 0
1 0
0 1
1 0
0 1

```

- output file

```

```

- Correct STDOUT 

```
0
0
0
1
1
1
0
0
0
0

```

- std_output

```
0
0
0
1
1
1
0
0
0
0

```

- diff

```
  0

  0

  0

  1

  1

  1

  0

  0

  0

  0


```

------
