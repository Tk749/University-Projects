# Taha Kinali - Assignment 3 - Report - Grade: `85`

- Test 0 ---> `20 of 20` Points
- Test 1 ---> `15 of 15` Points
- Test 2 was failed ---> `0 of 15` Points
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
No STDIN file provided
Thread Finished
Terminating Process
return_code 0
```

- Input File: **values.txt**

```
12.5 5 67.89 -6 -13.37
```

- Input File: **polynomial.txt**

```
5x+23.5x^3-x^2
```

- output file

```
45804.69 
2937.50 
7349081.25 
-5142.00 
-56410.13 

```

- Correct Output File: **evaluations.txt**

```
45804.69
2937.50
7349081.25
-5142.00
-56410.13

```

- std_output

```

```

- diff

```
- 45804.69

+ 45804.69 

?         +

- 2937.50

+ 2937.50 

?        +

- 7349081.25

+ 7349081.25 

?           +

- -5142.00

+ -5142.00 

?         +

- -56410.13

+ -56410.13 

?          +


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

- Input File: **values.txt**

```
1 2 3 4 5
```

- Input File: **polynomial.txt**

```
2x^2
```

- output file

```
2.00 
8.00 
18.00 
32.00 
50.00 

```

- Correct Output File: **evaluations.txt**

```
2.00
8.00
18.00
32.00
50.00

```

- std_output

```

```

- diff

```
- 2.00

+ 2.00 

?     +

- 8.00

+ 8.00 

?     +

- 18.00

+ 18.00 

?      +

- 32.00

+ 32.00 

?      +

- 50.00

+ 50.00 

?      +


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

- Input File: **values.txt**

```
1 2 3 4 5 6 7 1000 2000 3000 4000 0
```

- Input File: **polynomial.txt**

```
x
```

- output file

```

```

- Correct Output File: **evaluations.txt**

```
1.00
2.00
3.00
4.00
5.00
6.00
7.00
1000.00
2000.00
3000.00
4000.00
0.00

```

- std_output

```

```

- diff

```
- 1.00

- 2.00

- 3.00

- 4.00

- 5.00

- 6.00

- 7.00

- 1000.00

- 2000.00

- 3000.00

- 4000.00

- 0.00


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

- Input File: **values.txt**

```
1 10 20 0 -1
```

- Input File: **polynomial.txt**

```
100x^2+100x^2
```

- output file

```
200.00 
20000.00 
80000.00 
0.00 
200.00 

```

- Correct Output File: **evaluations.txt**

```
200.00
20000.00
80000.00
0.00
200.00

```

- std_output

```

```

- diff

```
- 200.00

+ 200.00 

?       +

- 20000.00

+ 20000.00 

?         +

- 80000.00

+ 80000.00 

?         +

- 0.00

+ 0.00 

?     +

- 200.00

+ 200.00 

?       +


```

------

### Test 4

------

```
Thread Started
No STDIN file provided
Thread Finished
Terminating Process
return_code -9
```

- Input File: **values.txt**

```
-1 1 0 2
```

- Input File: **polynomial.txt**

```
-3x^3+20x^2
```

- output file

```
23.00 
17.00 
0.00 
56.00 

```

- Correct Output File: **evaluations.txt**

```
23.00
17.00
0.00
56.00

```

- std_output

```

```

- diff

```
- 23.00

+ 23.00 

?      +

- 17.00

+ 17.00 

?      +

- 0.00

+ 0.00 

?     +

- 56.00

+ 56.00 

?      +


```

------
