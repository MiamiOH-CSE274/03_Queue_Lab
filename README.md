Author
==========
"Stilgenbauer, Kendall", stilgeki
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

1. Remove does indeed take constant time, because none of the code depends on numItems.  It just executes each line once (or fewer times) no matter how many things are in the queue or array.
2. Add also occurs in constant time, because, much like remove, each line is executed one or fewer times, no matter how many items are in the queue.
3. Yep, grow is only called if numItems == backingArraySize, and grow creates a new array twice the size of backingArraySize.
4. Grow takes O(n) time, because for each item it has to copy it over to the new array.
5. I believe grow and the destructor operate properly and do not leak memory, but I'm honestly not entirely sure what all goes into a destructor since they are new to me.
6. Yes, getNumItems takes O(1) time; all it does is return numItems.  While the number itself may grow with n, the time it takes to return does not.
7. Yes, the exceptions are implemented properly, as far as I can tell.
8. No linear arrays here, no sir, only circular ones!

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

We could get rid of the front variable, because a Stack adds and removes from the back, so it doesn't need to know where the front is.  It still needs all of the other variables and functions, though.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I wasn't sure how to handle deletion of the old backingArray in the grow function.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

You use a colon instead of "extends," like so: class ArrayQueue : Queue.

#### 5. What is the purpose of "templates" in C++?

Templates sort of take the place of interfaces or abstract classes in Java.  They provide an outline of a class that you will flesh out later in a class that extends that one.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* array = new int[10]

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

A class destructor deletes the elements of the class object to free up memory for later things.  We don't need them in Java because Java handles such garbage collection duties for us.  In C++ however, that is left to the programmer.