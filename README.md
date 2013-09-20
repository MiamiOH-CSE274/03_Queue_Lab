Author
==========
"Vutisalchavakul, Pob", vutisat
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

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. It works
2  It works
3. It works
4. It works
5. It works
6. It works
7. Done
8. I've gotten the program to work, and I believe that computing time is O(1) but I am uncertain on how to check them.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
I think that end would be deletable because it stacks up, keep others? Unsure.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
The grow function really puzzles me, Go to office hours!!
Also what different does delete & and delete[] means? I ran into error using the wrong one.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
queue::ArrayQueue

#### 5. What is the purpose of "templates" in C++?
When you arn't exactly sure what type of data you'll work on but you have a way of treating it

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
"int* arrayName = new int[10];"

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
To get rid of classes that are no longer in used. Java has a garbage collector that does this for you.
