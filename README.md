03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. TODO
2. TODO
3. TODO
4. TODO
5. TODO
6. TODO
7. TODO
8. TODO

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
Start early on homework, and take notes during class. 

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
class ArrayQueue : public Queue <T>

#### 5. What is the purpose of "templates" in C++?
A template lets the user create a class of any type of data. By using "T" it doesn't restrict the class from
being only strings, or ints, or floats, etc. Methods can return any type, and any type can be an input.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* arr = new arr[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The deconstructor closes everything you opened or created. So, it deletes any remaining variables, 
and "cleans up" once everything has run. The garabge collector is the deconstructor in java. The language cleans up for you.
