# IMPORTANT!
The Bonus Part is not perfect now, only half scores (117/125)

I already find the bug (see the Bonus Part) and will try to fix it, but I don't want to retry it now, maybe in the future.



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

It is failed in moulinette in the bouns-one, "Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions."

The reason is I didn't consider with _**a negative width value**_, I will fix it later.

## Notes
1.It is better to use a buffer method to reduce the times to call write function.

2.When use a buffer, remember to _**initialize it at begining and refresh it after write.**_

3.Check fail of write function, if use a buffer only need to check it when write the buffer.

4.The correct order of printf input is _%[-+ 0#][width][.precision][specifier]_, but for a wrong order, if cc without -W -W -W, printf can also give a corret output and return value.

5.Check _**negative width value**_, like `ft_printf("%-*d", -20, 42);`, the standard printf would convert the "-20" to "20" then print out.

6.Precision has two input format .nb or .*, like `ft_printf("%.3d", 42);` or `ft_printf("%.*d", 3, 42);`.

7.For a very large or small width value or precision there would be a lot of problem, like `ft_printf("%2147483647d", 42);` and `ft_printf("INT_MAX WIDTH %2147483647d", 42);`, it seems what before % also matters, we didn't find the reason and method to handle this yet. But good news is moulinette doesn't test a extremely large or small value.

## Useful Links
  **flags & description** https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

  **visual printf**
        https://github.com/Nuno-Jesus/42_ft_printf/tree/main/ft_printf 
        https://zhxnlai.github.io/printf/#/

  **full printf tutorial** https://www.youtube.com/watch?v=kM-DOhKR080&list=PLc4DnsRQbs6YsGjxHE-UgoI0ZGsuD8VQY&index=3
  _ATTENTION!! This tutorial is not match to subject perfectly, so just learn the method and write your own code_
