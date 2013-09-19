Author
==========
"Harvey, Steven", harveysd
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

1. This takes O(1) time because it constantly does the same thing.
2. This also takes O(1) time by simply changing an array point value, unless grow is called.
3. The if statement "if (numItems == backingArraySize)grow();" makes sure that grow is only called when we want to add to a full array, and grow doubles the array size.
4. Grow takes O(n) time because it doubles based on the numItems variable.
5. Both the grow function and the destructor will delete the array by using delete[].
6. getNumItems is O(1) time because it just returns a single variable.
7. Both add and remove throw an exception if needed.
8. This is a circular array, as the 'front' just circles from the back to the front of the array.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

We would need to keep grow(), T* backingArray, unsigned long numItems, and unsigned long backingArraySize. We could get rid of unsigned long front. We would no longer need to keep track of where the "front" of the stack was because we would always pull the last item that was put into the array, or another way to put it would be pull backingArray[numItems]. We would still have to know how many items where in it, the size of the backing array, and have a function to make the array bigger if the stack got full.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

The only thing that really confused me about this exercise was the .ipp file. I think that the difference between .ipp and .h should be gone over before this assignment, and the reasoning behind using it should also be explained.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

class ArrayQueue : public Queue <T> 

#### 5. What is the purpose of "templates" in C++?

Templates allow us to make code that can function with multiple different types of objects and data types; e.g. int, char, string, foo, bar. It gives us greater flexibility by allowing us to create the code without declaring what type of data that code will use.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int* intArray = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

Class destructors clean up any memory space that we used for that object. We need them in c++ because the compiler doesn't keep track of what is and isn't being used any more. Java has built in garbage collecting that will clean objects up if they aren't used any more.
