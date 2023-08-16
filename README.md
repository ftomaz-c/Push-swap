# Push-swap
> "This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting."

## Introduction
The main objective of the "push swap" project is to develop a sorting algorithm that uses the provided operations to rearrange the given list of numbers in the minimum number of moves. You'll be working with constraints on memory usage and optimizing for speed, making this project a comprehensive test of your coding and algorithmic skills.

## Strategy
- Understand the problem and constraints;
- Choose a sorting strategy to use as the basis for the push swap algorithm;
- Plan your algorithm;
- Implement the algorithm using the stack operations;
- Test the chosen algorithm;
- Optimize and refine;
- Iterate and improve (until satisfied);
- Handle special cases;
- Documentation and clean the code;
- Final testing (large inputs) and make sure it meets the project requirements.

## Topics to study:
- Sorting Algorithms;
- Data Structures - Stacks;
- Time and Space Complexity;
- Big O Notation;
- Divide and Conquer technique;
- Greedy Algorithms;
- Dynamic Programming technique;
- Space and Time Trade-offs;
- Practice and Implementation;
- Project-Specific Topicst;

## Sorting Algorithms:

Simpler Algorithms:
- Bubble Sort
- Selection Sort
- Cocktail Sort
- Comb Sort
- Odd-Even Sort / Brick Sort
- Pancake Sorting
- Insertion Sort

Intermediate Algorithms:
- ShellSort
- Tag Sort (To get both sorted and original)
- Tree Sort
- Heap Sort

Advanced Algorithms:
- Merge Sort
- Quick Sort
- Counting Sort
- Radix Sort

### Table of Complexity Comparison:
| Name	| Space Complexity| Best Case	| Average Case	| Worst Case	|
|---	|---	|---		|---			|---			|
|Bubble Sort| O(1)| O(n)| O(n^2)| O(n^2)|
|Selection Sort|
|Quick Sort| O(log n) | O(n log n) | O(n^2) | O(n log n) |

[geeksforgeeks - Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/);

[flexiple - Big O Notation Cheat Sheet](https://flexiple.com/algorithms/big-o-notation-cheat-sheet/);

[Frontend Masters - The Last Algorithms Course You'll Need](https://frontendmasters.com/courses/algorithms/);

## Stack Data Sctructure

**Stacks** are a collection of elements 'piled' on top of one another - Abstract Data Type (ADT) - so we only need to know what type of operations can we do with it and the type of struct we want to use to construt a stack, ArrayLists ([Stacks are not arrays!](https://www.tutorialspoint.com/difference-between-stack-and-array)), LinkedLists (Double LinkedLists if there is a need to access the in between data) and ArrayBuffers. It always depends on the porpuse of it. The **LIFO principle**, states that the element put last is the first to be removed from the list, is the foundation of stacks.

<center> !!The project specifically says to use Lists as our arguments!! </center>

### Operations:

- push(data): inserts data into the stack;
- pop(): deletes/moves the last inserted data element from the stack;
- top(): returns the last inserted data element without removing it;
- size(): returns the size or the number of element in teh stack;
- isEmpty(): returns TRUE if the stack is empty, else return FALSE;
- isFull(): returns TRUE if the stack is full, else returns FALSE;

### Operations permited in the Project:

- **sa** or **sb** (swap a or b): swap the first 2 elements of stack a or b. Do nothing if there is only one or no elements;
- **ss**: sa and sb at the same time;
- **pa** or **pb**: (push a or b): take the first element at the top of b and put it at the top of a, or vice versa. Do nothing if b is empty;
- **ra** or **rb**: (rotate a or b): Shift up all elements of the stack by 1. The first element becomes the last one;
- **rr**: ra and rb at the same time;
- **rra** or **rrb**: (reverse rotate a or b):  Shift down all elements of the stack by 1. The last element becomes the first one;
- **rrr**: rra and rrb at the same time.

*the push operations is a pop-push - first pop then push.
