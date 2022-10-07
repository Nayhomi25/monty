<h1> Monty Interpreter</h1>
This is a language interpreter made in the C programming language to            manage stacks and queues (LIFO and FIFO). The aim of this Interpreter is        to interpret Monty bytecodes files. Monty is a language that aims to close      the gap between scripting and programming languages.
<h2>Requirements</h2>
<ul>
<li>Allowed editors: vi, vim, emacs</li>
<li>All your files will be compiled on Ubuntu 20.04 LTS using gcc, using        the options -Wall -Werror -Wextra -pedantic -std=c90</li>
<li>All your files should end with a new line</li>
<li>A README.md file, at the root of the folder of the project is               mandatory</li>
<li>Your code should use the Betty style. It will be checked using betty-       style.pl and betty-doc.pl</li>
<li>You allowed to use a maximum of one global variable</li>
<li>No more than 5 functions per file</li>
<li>You are allowed to use the C standard library</li>
<li>Don’t forget to push your header file</li>
<li>All your header files should be include guarded</li>
 </ul>
<h2>Compilation</h2>
To compile this project, you can use the following command:
 $ make

<h2>opcode and their functionality</h2>

1. push: add element to the 'top' of stack and 'end' of queue

2. pop:  remove element from 'top' of stack and 'end' of queue

3. pall:     print every member of the structure

4. pint:     prints the member value at the top of stack

5. swap:   swaps the order of the 1st and 2nd elements in stack

6. add:    add top two member values

7. sub:    subtract the top element from the 2nd top element

8. div:   divide the 2nd element by the top element

9. mul        multiply the top two elements of the stack

10. mod       the remainder when the 2nd element is divided by the top elementcomment    there is the ability to parse comments found in bytecode ->

11. pchar     print character at the top of the stack

12. pstr  print the character at the top of the stack

13. rotl  moves element at the top to the bottom of the stack

14. rotr  the bottom of the stack becomes the top

15. queue,  stack    toggles the doubly link list implementation style

16. nop       opcode should do nothing.

Examples: $ cat opcodetestfile.m

push 1

push 2

push 3

pall

$ ./montyfile opcodetestfile.m

3

2

1

$

$ cat opcodetestfile.m

push 1

push 2

push 3

pall

rotl

pall

$ ./montyfile opcodetestfile.m

3

2

1

2

1

3

<h2>Exit Status</h2>
Exits with status EXIT_FAILURE
<h2>Compilation</h2>
All files were compiled on Ubuntu 14.04 LTS.

All programs and functions were compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic.
<h2>Styling</h2>
All files have been written in the Betty Style.

<h2>Authors</h2>

Nsisong-Akpakpan Nsisong

Martin4dbest Martin Agoha - martin4dtruth@gmail.com
