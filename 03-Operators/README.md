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

## The cast and sizeof operators
### Type conversions
Conversion of between different types can happen automatically (implicit conversion) by the language or explicit by the program. To effectively develop C programs, you must understand the rules used for the implicit conversion of floating-point and integer values in C.
We are often going to have integers and floating point numbers, and we are going to be intermixing them sometimes. For these situations, we should know how things are being converted. We should not mix types. Remember, C is flexible, it gives us a lot of freedom, but we should not abuse it.

* Whenever a floating point value is assigned to an integer variable in C, the decimal portion of the number gets truncated.

~~~c
int x = 0;
float f = 12.125;
x = f; // value stored in x is the number 12
~~~

* Assigning an integer variable to a floating variable, it does not cause any change in the value of the number. The value is converted by the system and stored in the floating variable.

* When performing integer arithmetic: if two operands in an expression are integers then any decimal portion resulting from a division operation is discarded, even if the result is assigned to a floating variable.
if one operand is an int and the other is a float then the operation is performed as a floating point operation. This is an impĺicit conversion.

### Cast operator
As mentioned, we should usually steer clear of automatic type conversions, especially of demotions, as it is better to do an explicit conversion.

It is possible for us to demand the precise type conversion. This is called a cast and consists of preceding the quantity with the name of the desired type in parentheses. 
Parentheses and type name together constitute a cast operator, i.e., (type).

The type cast operator has a higher precedence than all the arithmetic operators except the unary minus and unary plus.

~~~c
(int) 21.51 + (int) 26.99 // 21 + 26
~~~

Usually, we don't cast to a more precise type because we are not going to get more precise. We cast from a more precise type to a less precise.


### sizeof operator
You can find out how many bytes are occupied in memory by a given type by using the `sizeof` operator. This is evaluated at compile time and not at runtime, unless a variable-length array is used in its argument.
The argument to the sizeof operator can be a variable, an array name, the name of a basic data type, the name of a derived data type, or an expression.

`sizeof(int)` will result in the number of bytes occupied by a variable of type int.

We can also apply the sizeof operator to an expression. The result is the size of the value that results from  evaluating the expression.

This operator will come into play a lot more when we talk about pointers, because then we are calculating how much memory to allocate (which is what pointers are), we use sizeof to be precise.

### ? Operator
This is the ternary operator. Is a way to write if/else statements in one line.
The structure goes like this.
~~~
If Condition is true ? then value X : otherwise value Y
~~~

## Operator precedence
Operator precedence determines the grouping of terms in an expression and decides how an expression is evaluated. It dictates the order of evaluation when two operators share an operand.

~~~c
x = 7 + 3 * 2; // equals 13, not 10 
~~~

In this last case, multiplication precedes addition.

C provides specificrules for choosing what is the precedence of operators. Each operator is assigned a precedence level.

Whenever an operation is enclosed in parentheses, it will be executed first, as in the mathematical language.

### Associativity
What if two operators have the same precedence? Then associativity rules are applied.
If they share an operand, they are executed according to the order in which they occur in the statement. For most operators, the order is from left to right.

~~~c
1 == 2 != 3
~~~

operators `==` and `!=` have the same precedence. Associativity of both `==` and `!=` is left to right.

~~~c 
((1 == 2) != 3)
(1 == 2) // false (0)
(0 != 3) // true
~~~

### Table (highest to lowest)

| Category | Operator | Associativity |
|:---:|:---:|:---:|
| Postfix | ()[]->. ++ -- | left to right |
| Unary | + - ! ~ ++--(type)*& sizeof | right to left |
| Multiplicative | * / % | left to right |
| Additive | + - | left to right |
| Shift | 0 | left to right |
| Relational | < <= > >= | left to right |
| Equality | == != | left to right |

| Category | Operator | Associativity |
|:---:|:---:|:---:|
| Bitwise AND | & | left to right |
| Bitwise XOR | ^ | left to right |
| Bitwise OR | \| | left to right |
| Logical AND | && | left to right |
| Logical OR | \|\| | left to right |
| Conditional | ?: | right to left |
| Assignment | = += -= *= /= %= >>= <<= &= ^= \|=| right to left |
| Comma | , | left to right |