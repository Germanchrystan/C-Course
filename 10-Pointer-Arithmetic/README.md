# Pointer Arithmetic
The real power of using pointers to arrays comes into play when we want to sequence through the elements of an array. Pointers and arrays are intimately related in C.
~~~c
*valuesPrt // can be used to access the first integer of the values array
~~~
To reference `values[3]` through the valuesPtr variable, we can add 3 to valuesPtr and then apply the indirection operator
~~~c
*(valuesPtr + 3)
~~~
The expression `*(valuesPtr + i)` can be used to access the value contained in `values[i]`. 
~~~c
*(valuesPtr + 10) = 27; // Yo set values[10] to 27
~~~

- To set calues Ptr to point to the second element of the values array, we can applu the address operator to `values[1]`.
~~~c
valuesPtr = &values[1];
~~~

- If valuesPtr points to `values[0]`, we can set it to point to `values[1]` simply by adding 1 to the value of valuesPtr
~~~c
valuesPtr += 1;
~~~
The increment and decrement operators `++` and `--` are particularly useful when dealing with pointers.


## Summary
~~~c
int urn[3];
int * ptr1, *ptr2;

// Valid
ptr1++;
ptr2 = ptr1 + 2;
ptr2 = urn + 1;


// Invalid
urn++;
ptr2 = ptr2 + ptr1;
ptr2 = urn * ptr1;
~~~

## Character pointers
If we have an array of characters called text, we could similarly deifne a pointer to be used to point to elements in text.
~~~c
char *textPtr;
~~~
if textPtr is set pointing to the beginning of an array of chars called text
~~~c
textPtr = text[0];
++textPtr;
~~~~
The above sets textPtr pointing to the next character in text, which is `text[1]`.
~~~c
--textPtr;
~~~
The aboce sets textPtr pointing to the previous character in text, assuming that textÑtr was not pointing ot the beginning of text prior to the execution of this statement.