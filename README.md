# IMPORTANT!
The Bonus Part is not perfect now, only half scores (117/125)

Not sure where is the bug now, there two possible problems(see the Bonus Part), but I don't want to retry it now, maybe in the future.



# Mandatory Part
## Notes
1.Remember to check the _**return vaule of write**_ everytime you call the write function. If write fail, always _**return (-1)**_;

2.For %s, if the input string is _**empty**_, write "(null)" derictly, and remember check the return value of write.

3._**Check NULL input**_

4.For %p, `if (nb < base)`, also need to use `hex[nb % 16]`. This is differ to convert base for normal number.

5.Check single % without any specifier follow it.

6.If test `ft_printf(NULL);` the program would segament fault, but the standard printf also segament fault with this input, so it's ok.

## Useful Links
  **about printf** https://www.geeksforgeeks.org/printf-in-c/
  
  **va_list** https://www.youtube.com/watch?v=Hb2m7htiKWM
  
  **mini printf tutorial** https://www.youtube.com/watch?v=byRw36Y3Hjs&list=PLc4DnsRQbs6YsGjxHE-UgoI0ZGsuD8VQY&index=3
  _ATTENTION!! This tutorial is not match to subject perfectly, so just learn the method and write your own code_


# Bonus Part
I have two version code for bonus part, one is similar with Mandatory part without useing buffer, but write as soon as it need to be print. It's work well, but slow, _**if the width value is large, like 100 or 1000, it may timeout.**_

The newest one which I submit is use a large buffer to collect all contents need to be print, and only call write function when the buffer is full or reach the end of format string.

## My Bug (I haven't fix them yet)

My code failed by moulinette in the bouns-one, "Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions."

### **The possible bug:**

#### 1.Precision for pointer (confirm it is an error)

For `ft_printf("%.p", (void *)0);` or `ft_printf("%.0p", (void *)0);`, the output should be `0x`, my output is `0x0`

#### 2.Max value for width? or return length? (not sure whether moulinette test this or not)
For a very large or small width value, like INT_MAX or INT_MIN, it should return -1.

I found some interesting? problems for this limitation

For example: 

If the width value is INT_MAX: `printf("%2147483647d", 42);` , the return value shoube be `-1`, and print nothing.

`printf("%2147483646d", 42);` can print correctly, and return value is 2147483646.

If use * sign to give a negative number to width, the '-' sign will be recognized as _**left_justified**_. 

So INT_MIN : `printf("%-2147483648d", 42);` and INT_MIN + 1 : `printf("%-2147483647d", 42);` , will return -1. 

It seems, the unsigned value of width should be smaller than INT_MAX. 

So the max width is 2147483646, and min is -2147483646.

_**BUT!**_ (moulinette does not test this, but standard printf does)

If there are some other chars before _%_ or after _d_, the limitation of width is not UINT_MAX - 1 (2147483646).

like:

`printf("INT_MAX WIDTH %2147483646d", 42);`, will return -1, and print nothing.

`printf("INT_MAX WIDTH %2147483645d", 42);` will also return -1, and print nothing.

...

`printf("INT_MAX WIDTH %2147483635d", 42);` will also return -1, and print nothing.

...until...

`printf("INT_MAX WIDTH %2147483632d", 42);` it print and return 2147483646

So _**INT_MAX - 1**_ is not the _**width**_ limitation, but the _**RETURN VALUE**_ of printf, the total length of the output string should smalle than INT_MAX

_Not sure why is must be smaller, can not be equal, I guess it is because of '\0'?_

_**How about two specifiers in a printf**_

   If test `printf(" >>>return value is %d\n", printf("a%d, b%2147483641d", 42, 42));`

   The result would be `a42 >>>return value is -1`

   For the first specifier, the total length is ['a' before %] + [nb1], so 1 + 2 = [3], and it can print correctly.

   But start from the first 'd', to the next specifier 'd', the total length is [3] + [', b' before '%' is 3] + [2147483641] = [2147483647], which is larger than the max return value mentioned before. so it print nothing and return (-1).

   So, this means, printf will print the output each time it meet a specifier, but add all write length of all specifiers together, and as soon as it larger than INT_MAX - 1, it will stop.

   This is why it is better to use buffer to do this.

   But moulinette didn't think so much now, so may not need to do as this.

## Notes
1. It is better to use a buffer method to reduce the times of calling write function.

2. When use a buffer, remember to _**initialize it at begining and refresh it after write.**_

3. Check fail of write function, if use a buffer only need to check it when write the buffer.

4. The correct order of printf input is _%[-+ 0#][width][.precision][specifier]_, but for a wrong order, if cc without -W -W -W, printf can also give a corret output and return value.

(moulinette does not check 5 & 6, but it is better to do as standard printf)

5. Width and Precision has two input format nb and .nb, or * and .*, like `ft_printf("%.3d", 42);` or `ft_printf("%.*d", 3, 42);`.

6. Handle with _**negative width value**_, like `ft_printf("%*d", -20, 42);`, the standard printf would recognized the '-' as _**left_justified**_, width value is 20.


## Useful Links
  **flags & description** https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

  **visual printf**
        https://github.com/Nuno-Jesus/42_ft_printf/tree/main/ft_printf 
        https://zhxnlai.github.io/printf/#/

  **full printf tutorial** https://www.youtube.com/watch?v=kM-DOhKR080&list=PLc4DnsRQbs6YsGjxHE-UgoI0ZGsuD8VQY&index=3
  _ATTENTION!! This tutorial is not match to subject perfectly, so just learn the method and write your own code_
