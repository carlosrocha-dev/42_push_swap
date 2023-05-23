<div align="center"> 

![image](https://github.com/carlosrocha-dev/42_push_swap/assets/3737837/0a006021-b54b-48cb-b1d1-a59ee0435dfd)

# 42 Push Swap

</div> 

https://github.com/carlosrocha-dev/42_push_swap/assets/3737837/fae34478-1b6b-41b9-82a6-92309e4dfab4

</div>

## Because Swap_push isn’t as natural
   
---

This project is about sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed it must have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

## Optimized Sorting Algorithm: Radix Sort with Bitwise Operations

During our journey at 42 São Paulo, we faced a complex challenge: to sort data on a stack with a restricted set of instructions, and to minimize the number of actions taken. To accomplish this task, it was necessary to manipulate and adapt different types of algorithms, choosing the most suitable solution for optimized data sorting.

Data sorting is fundamental in computer science, especially when dealing with large volumes of data. In this situation, choosing an efficient sorting algorithm that fits the restrictions of the problem is crucial.

Facing this challenge, I chose to use Radix Sort, an efficient and effective method of data sorting. This algorithm, despite its simplicity, has speed and accuracy that allow for efficient data sorting.

Radix Sort begins by identifying the number with the most digits, which will be the basis for determining how many times the sorting process will be repeated. It then goes through the stack of numbers, but instead of analyzing the digits in a conventional way, it uses bitwise operations. This allows the algorithm to analyze the binary digits of each number, from right to left, reorganizing the stack according to the value of each bit.

If the analyzed bit is 1, the number is moved to the top of the stack. If the bit is 0, the number is moved to a second stack. This process is repeated until all bits of all numbers have been analyzed.

Finally, all the numbers from the second stack are returned to the original stack, completing one pass of the algorithm. This process is repeated until the entire stack is sorted.

While it may seem complex at first reading, the execution of Radix Sort using bitwise operations is simple and efficient, making it an excellent option for sorting data on a stack.

## How to run

1. Clone the project: ```git@github.com:carlosrocha-dev/42_push_swap.git```
2. Go to the folder: ```cd 42_push_swap```
3. Run the commands
```Bash
> make
```

```Bash
> make test100
```

```Bash
> make test500
```
