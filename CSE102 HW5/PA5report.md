# Taha Kinali - Assignment 4 - Report - Grade: `100`

- Test 0 ---> `20 of 20` Points
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
gcc taha_kinali_19010426605.c -o executable

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

- Input File: **input.txt**

```
(A,(c,B,e),K,D,e,(f,(d,F)))

```

- output file

```
-A
--c
--B
--e
-K
-D
-e
--f
---d
---F
```

- Correct Output File: **output.txt**

```
-A
--c
--B
--e
-K
-D
-e
--f
---d
---F

```

- std_output

```

```

- diff

```
  -A

  --c

  --B

  --e

  -K

  -D

  -e

  --f

  ---d

- ---F

?     -

+ ---F

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

- Input File: **input.txt**

```
(A,(A,A,(A),A),A)

```

- output file

```
-A
--A
--A
---A
--A
-A
```

- Correct Output File: **output.txt**

```
-A
--A
--A
---A
--A
-A

```

- std_output

```

```

- diff

```
  -A

  --A

  --A

  ---A

  --A

- -A

?   -

+ -A

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

- Input File: **input.txt**

```
A,(A,A,(A),A),A

```

- output file

```
A
-A
-A
--A
-A
A
```

- Correct Output File: **output.txt**

```
A
-A
-A
--A
-A
A

```

- std_output

```

```

- diff

```
  A

  -A

  -A

  --A

  -A

- A

+ A

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

- Input File: **input.txt**

```
(G,(G,(G,(G,(G,(G,(G)))))))
```

- output file

```
-G
--G
---G
----G
-----G
------G
-------G
```

- Correct Output File: **output.txt**

```
-G
--G
---G
----G
-----G
------G
-------G

```

- std_output

```

```

- diff

```
  -G

  --G

  ---G

  ----G

  -----G

  ------G

- -------G

?         -

+ -------G

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

- Input File: **input.txt**

```
(A)

```

- output file

```
-A
```

- Correct Output File: **output.txt**

```
-A

```

- std_output

```

```

- diff

```
- -A

?   -

+ -A

```

------
