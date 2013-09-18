Author
==========
"Kojs, Michelle", kojsmn
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

1. This requirement works. I know that remove takes 0(1) time because it takes constant time to run each iteration. Also looking at the number of iterations for each line in the remove method, I see that each takes 1 iteration for the worst case scenario. Therefore the running time for the remove function is 0(1).
2. This requirement works. The method add takes 0(1) time if grow is not called, but if grow is called it takes 0(n) time. The methods in add at worst case scenario take 1 iteration while the time per iteration is constant. Therefore the running time for the add method if we ignore the grow call is 0(1). If we look at the grow call, we see that the running time will be 0(n) because the grow method takes O(n) running time. 
3. This requirement works. I made an if statement in the add function where if numItems == backingArraySize the method grow is called.  In grow the size of the array is doubled.
4. This requirement works. The method grow takes 0(n) running time since there is a for loop present. Each line in the for loop is ran n times in the worst case scenario. This means that the time per iteration is linear, n. Therefore the running time for the grow method is 0(n).
5. This requirement works. Memory is not leaked because grow creates new memory for the second ArrayQueue and the destructor deletes the previous ArrayQueue. Each time memory is created with the new operator, the destructor deletes it when it is no longer needed.
6. This requirement works. The method getNumItems takes 0(1) time because there is one line in the method. This one line takes constant time per iteration and always has 1 iteration. Therefore the running time is 0(1).
7. This requirement works. An exception is thrown when the remove function is called on an ArrayQueue that has 0 items.
8. This requirement works. The array is used in a circular fashion. I tested this by changing the front value and making sure all the methods still returned SUCCESS.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
If we did a Stack instead of a Queue, the private methods we would need to keep would be grow. Grow allows the arraySize to increase if more items needed to be added than there is space in the Stack.
The private variable that we would need to keep would include backingArray, numItems, and backingArraySize. Since Stack is LIFO (Last In First Out) the size of the Stack needs to be known, as well as how many items are in the Stack.  
The private variable front is not needed because in a Stack it is LIFO which means last in first out. The front index does not need to be known, only the size of the Stack so that the last element can be removed first.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
The constructor confused me.  It took awhile for me to realize how to properly construct the backingArray with new.
One piece of advice that I would share with students next semester is to make sure all your variables are initialized in the constructor.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
To write the same thing you would write class ArrayQueue : public Queue <T>, where the child class is ArrayQueue and the parent class is Queue.

#### 5. What is the purpose of "templates" in C++?
The purpose of templates in C++ is to allow adaptability to more than one type or class. For instance, a template can be used by different types or classes. It saves space and times because then the entire code does not have to be repeated for each type.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
The syntax for allocating an array of 10 ints in C++ would be int* arrayName = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The purpose of a class destructor in C++ is to free up memory and clean up when an object is not needed anymore.  A class destructor is not needed in Java because Java has a garbage collector. This garbage collector frees up memory but it cannot be called like a destructor is.