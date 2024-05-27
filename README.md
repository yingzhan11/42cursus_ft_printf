# IMPORTANT!
The Bonus Part is not perfect now, only half scores. 

I already find the problem and will try to fix it (see the Bonus Part), but I don't want to retry it, maybe in the future.

# Mandatory Part
## Notes
1.Remember to check the return vaule of write everytime you call the write function. If write fail, always return (-1);

2.For %s, if the input string is empty, write (null) derictly, and remember check the return value of write.

3.Check NULL input

4.For %p, `if (nb < base)`, also need to use `hex[nb % 16]`. This is differ to convert base for normal number.

5.Check single % without any specifier follow it.

6.If test `ft_printf(NULL);` the program would segament fault, but the standard printf also segament fault with this input, so it's ok.

## Useful Links
  **about printf** https://www.geeksforgeeks.org/printf-in-c/
  
  **va_list** https://www.youtube.com/watch?v=Hb2m7htiKWM
  
  **mini printf tutorial** https://www.youtube.com/watch?v=byRw36Y3Hjs&list=PLc4DnsRQbs6YsGjxHE-UgoI0ZGsuD8VQY&index=3
  _ATTENTION!! This tutorial is not match to subject perfectly, so just learn the method and write your own code_


# Bonus Part
I have two version code for bonus part, one is similar with Mandatory part without useing buffer, but write as soon as it need to be print. It's work well, but slow, if the width value is large, like 100 or 1000, it may timeout.

The newest one which I submit is use a large buffer to collect all contents need to be print, and only call write function when the buffer is full or reach the end of format string.

It is failed in moulinette in the bouns-one, "Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions."

The reason is I didn't consider with a negative width value, I will fix it later.

## Notes
1.It is better to use a buffer to reduce the times to call write function.

2.When use a buffer, remember to initialize it at begining and refresh it after write.

3.Check fail of write function, if use a buffer only need to check it when write the buffer.

4.The correct order of printf input is % [-+ 0#][width][.precision][specifier], but for a wrong order, if cc without -W -W -W, printf can also give a corret output and return value.

5.Check negative width value.

6.Precision has two input format .nb or .*

## Useful Links
  **flags & description** https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

  **visual printf**
        https://github.com/Nuno-Jesus/42_ft_printf/tree/main/ft_printf 
        https://zhxnlai.github.io/printf/#/

  **full printf tutorial** https://www.youtube.com/watch?v=kM-DOhKR080&list=PLc4DnsRQbs6YsGjxHE-UgoI0ZGsuD8VQY&index=3
  _ATTENTION!! This tutorial is not match to subject perfectly, so just learn the method and write your own code_

should be careful with:
(...to be continued)
