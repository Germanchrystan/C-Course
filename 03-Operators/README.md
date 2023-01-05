# Operators
## Overview
Operators are functions that use a symbolic name, to perform mathematical or logical functions.
Operators are predefined in C, just like they are in most other languages, and most operators tend to be combined with the infix style.

* A *logical operator* (sometimes called a "Boolean operator") is an operator that returns a Boolean result that is based on the Boolean result of one or two other expressions.

- An arithmetic operator is a mathematical function that takes two operators and performs a calculation on them.

- Other operatos include assignment, relational(<,>, !=), bitwise(<<,>>,~).

## Expressions and Statements
- Statement form the basic program steps of C, and most statements are constructed from expressions. Most statements are constructed from expressions. You may see an expression inside of a statement.

- An expression consists of a combination of operators and operands.
    - operands are what an operator operates on.
    - operands can be constants, variables, or combinations of the two.
    - every expression has a value.

examples of expressions

~~~c
-6
4+21
a*(b + c/d)/20
q=5*2
x= ++q % 3
q > 3
~~~
Statements are the building block of a program (declaration). A program is a series of statements with special syntax ending with a semicolon (simple statements). Each is a complete instruction to the computer.

~~~c
// Declaration statement
int Jason;

// Assignement statement
Jason = 4;

// Function call statement
printf(Jason);

// Structure statement
while(Jason < 20) Jason = Jason + 1;

// Return statement
return 0;
~~~

C considers any expression to be a statement if you append a semicolon (expression statements). So, `8;` and `3-4;` are perfectly valid in C.

## Compound Statements
Two or more statements grouped together by enclosing them in braces (block)

~~~
while(index < 10)
{
    printf("Hello");
    index = index + 1;
}

~~~

## Operators
### Basic Operators
We are going to define the four different types of operators: `arithmetic`, `logical`, `assignment` and `relational`.

An arithmetic operator is a mathematical function that takes two operands and performs a calculation on them. A logical ooperator (sometimes called a "boolean operator") is an operator that returns a boolean based on the results of one or two other expressions

Assignement operators set variables equal to values. They assign the value of the expression at its right to the variable at its left.

A relational operator will compare variables against eachother.

### Arithmetic operators in C
| Operator | Description  | Example |
|----------|:------------:|:------------:|
| +       | Adds two operands.| A+B = 30 | 
| -       | Substracts second operand from the first. | A-B = -10 |
| *       | Multiplies both operands. | A*B = 200|
| /       | Divides numerator by de- numerator | B/A = 2|
| %       | Modulus Operator and remainder of after an integer division. | B%A = 0 |
| ++       | Increment operator increaes the integer value by one. | A++ = 11 |
| --       | Decrement operator decreases the integer value by one. | A-- = 9 |

### Logical operators
| Operator | Description  | Example |
|----------|:------------:|:------------:|
| `&&`       | Called Logical AND Operator. If both the operands are non-zero, then the condition becomes true | `(A && B)` is false |
| `\|\|` | Called Logical OR Operator. If any of the two operands is non-zero, then the condition becomes true. | ` !(A \|\| B)` is true |
| `!` | Called Logical NOT Operator. It is used to reverse the logical state of its operand. If a condition is true, then Logical NOT operator will make it false | `!(A && B)` is true |
 
### Assignment Operators
| Operator | Description  | Example |
|----------|:------------:|:------------:|
| `=` | Simple assignment operator | `C = A + B` |
| `+=` | Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand | `C += A ` |
| `-=` | Substract AND assignment operator. It substracts the right operand from the left operand and assigns the result to the left operand. | `C -= A` |
| `*=` | Multipĺy AND assignment operator. It multiplies the right operand with the left operand and assigns the result to the left operand | `C *= A` |
| `/=` | Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand | `C /= A` |
| `%=` | Modulus AND assignment operator. It takes modulus using two operands and asigns the result to the left operand | `C %= A` |
| `<<=` | Left shift AND assignment operator | `C <<= 2` is same as C = C << 2|
| `>>=` | Right shift AND assignment operator | `C >>= 2` is same as C = C >> 2|
| `&=` | Bitwise AND assignment operator | `C &= 2` is same as C = C & 2|
| `^=` | Bitwise exclusive OR and assignment operator | `C ^= 2` is same as C = C ^ 2|
| `|=` | Bitwise inclusive OR and assignment operator | `C |= 2` is same as C = C | 2|

### Relational Operators

| Operator | Description  | Example |
|----------|:------------:|:------------:|
| `==` | Checks if the values of two operands are equal or not. If yes, then the condition becomes true | `A == B` |
| `!=` | Checks if the values of two operands are equals or not. If the values are not equal, then the condition becomes true | `A != B` |
| `>` | Checks if the value of the left operand is greater than the value of the right operand. If yes, then the condition becomes true | `A > B` |
| `<` | Checks if the value of the right operand is greater than the value of the left operand. If yes, then the condition becomes true | `A < B` |
| `>=` | Checks if the value of the left operand is greater than or equal to the value of the right operand. If yes, then the condition becomes true | `A >= B` |
| `<=` | Checks if the value of the right operand is greater than or equal to the value of the left operand. If yes, then the condition becomes true | `A <= B` |

## Bitwise Operators
C offers bitwise logical operators and shift operators. They look like the logical operators seen earlier but they are quite different. This operators work on bits, inside integer values. 
This is not used in most programs, as this constitues very advance C programming. 
One major use of the bitwise AND `&`, and the bitwise OR `|`, is in operations to test and set individual bits in an integer variable. Remember, depending on the system we are running, an integer could be made out of 8 bytes. And so we could turn on and off each bit of the integer. 

We could use a single integer variable top store several chartacteristics of a person.
- Store whether the person is male or female with one bit.
- Use three other bits to specify whether the person can speak French, German or Italian.
- Another bit to record whether the person's salary is 50000 or more.
- In just four bits you have a substantial set of data recorded.

### Binary Numbers
A binary number is a number that includes only ones and zeroes. The number could be of any length.
Every binary number has a corresponding decimal value (and vice versa).
Each position for a binary number has a value. For each digit, we multiply the digit by its position value, and then add up all of the products to get the final result.
In general, the "position values" in a binary number are the powers of two.

The value of binary 01101001 is decimal 105.
|128 | 64  | 32 | 16 | 8 | 4 | 2  | 1 ||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|0|1|1|0|1|0|0|1||
||||||||1*1| = 1|
|||||||0*2|| = 0|
||||||0*4||| = 0|
|||||1*8|||| = 8| 
||||0*16||||| = 0| 
|||1*32|||||| = 32|
||1*64||||||| = 64|
|0*128|||||||| = 0| 
||||||||| Answer 105|

Bitwise Operators
| Operator | Description  | Example |
|----------|:------------:|:------------:|
| `&` | Binary AND Operator copies a bit to the result if it exists in both operands | `(A & B) = 12, i.e., 0000 1100` |
| `\|` | Binary OR Operator copies a bit if it exists in either operand. | `(A \| B) = 61, i.e., 0011 1101` |
| `^` | Binary XOR Operator copies the bit if it is set in one operand but not both | `(A ^ B) = 49`, i.e., 0011 0001 |
| `~` | Binary Ones Complement Operator is unary and has the effect of 'flipping' bits | `(~A) = -61`, i.e., 1100 0011 in 2's complement form |
| `<<` | Binary left shift operator. The left operands value is moved left by the number of bits specified by the right operand. | `A << 2 = 240`, i.e., 1111 0000 |
| `>>` | Binary right shift operator. The left operands value is moved right by the number of bits specified by the right operand. | `A >> 2 = 15`, i.e., 0000 1111 |

Truth Table
| p | q | p & q| p \| q| p ^ q|
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 |