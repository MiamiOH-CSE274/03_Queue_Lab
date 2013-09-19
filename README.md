Author
==========
"Contini, Nick", continnd
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

1. Remove definitely has a constant O-efficiency, since all the method has to do is store a value in a space in memory, but it does not have to move any other values.
2. Add, just as remove, is constant as well, only writing a value without moving any other values
3. The only way grow can be used is if backingArraySize == numItems, and backingArraySize is doubled everytime it is called.
4. Grow is linear due to the fact that the amount of operations grows linearly the numbers of items increase. Although grow in reality has O-effiency of n^2, grow gets called less and less the more it is called, giving it an O-effieciency of n. 
5. Grow and the destructor make sure to delete the unsused array.
6. getNumItems literally only has to return one variable... it definitely has a constant O-efficiency.
7. Remove throws a string when there is nothing to remove. Add has no need for a thrown string.
8. Array is used circularly. n (the next spot to add at) and front both wrap around to the front when they reach the end of the array.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
Our add, grow, and getNumItems methods would mostly stay the same. However in add there would be no need to wrap around. Remove would be different in that it would remove the last item added, and then move n (the next index to add at) would decrease by one rather than increase. 

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
First think about what you are doing through a real life example. It helps to visualize what you are doing before you jump into the programming.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
class ArrayQueue: public Queue

#### 5. What is the purpose of "templates" in C++?
To tell C++ that there are several data types that we may use in our data structure, so we will use the class "T" which may represent may diffent classes.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
To free up memory when an object is no longer needed. Java does this automatically for us, thus we don't need a destructor.
