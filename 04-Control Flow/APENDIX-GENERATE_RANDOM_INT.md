# Generating a random number
To generate a random number from 0 - 20
- include the correct system libraries.
~~~c
#include<stdlib.h>
#include<time.h>
~~~

- create a time variable
~~~c
time_t t;
~~~

- initialize the random number generator
~~~c
srand((unsigned) time(&t));
~~~

- Get the random number (0-20) and store it in an int variable;
~~~c
int randomNumber = rand() % 21; // Number between 0 and 21 (not included)
~~~