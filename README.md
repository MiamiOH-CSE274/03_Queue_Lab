Author
==========
"Zirkle, Andrew", zirkleac
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
7. add and remove throw exceptions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Yes, it runs at constant time
2. Yes because it only runs the 1 function
3. Yes
4. It would be based on the the number of items so n time would be the correct timing
5. Yeah it gets rid of any extra 
6. Constant time yeah
7. remove has an exception, though I'm not sure what would be required for an add function to throw an exception
8. Well I got all of those working so I assume it worked circularly.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
add remove and resize would all need to be kept but the grow, front and numitems would not be needed.
#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?
I'm not even sure what to start with. There's no rules on getting started like "make a new file"
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
class ArrayQueue : public Queue <T>
#### 5. What is the purpose of "templates" in C++?
It seems to be a method that doesn't have a set type of variable. it can take strings or ints
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int *array= new int[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
A class destructor basicly gives you the memory back an object was using. Java automaticly sees if you use a variable again and cleans the memory if you don't.
