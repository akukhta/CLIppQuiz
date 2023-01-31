# CLIppQuiz
CLIppQuiz is a command line version of cppquiz.org.

## What is this?<br>
This is a simple online quiz that you can use to test your knowledge of the C++ programming language.

## How do I use it?<br>
Most of the questions will compile and have deterministic output, for these you just need to press 1 and enter the output of the program in the terminal. Some programs do however have a compilation error, unspecified behaviour, or undefined behaviour. In that case, print 2, 3 or 4.

## Which version of the standard is used?
C++17

# Preview
![image](https://user-images.githubusercontent.com/45069472/215766508-7e2b7a78-4ab0-4286-b693-b017a8472f88.png)

## Dependencies:
* libcurl 
* boost program options

## C++ Version:
C++20

## Command Line Arguments:
* --help [-h] print help message
* --specific=num [-snum] solve question with provided ID
* --count=num [-cnum] amount of questions to solve
* --explain [-e] TBA
