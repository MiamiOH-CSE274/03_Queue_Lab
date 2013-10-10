Author
==========
"Bickley, Daniel", bickledb
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

1. Remove takes O(1) time, as the implementation is not based on the number of items in the array.
2. Add takes O(1) time without grow, because its implementation does not depend on the number of items in the array. With grow, it achieves O(n) time, because the method time depends on the number of items in the array, in a linear fashion.
3. Grow is only called when items == backingArraySize, and the array is doubled every use of grow.
4. Grow does take O(n) time, because it must read through the array and copy each individual number, forcing the grow method to take linear time, as it has to read everything in the array once.
5. In grow and the destructor, the correct variables are destructed to avoid a memory leak.
6. GetNumItems takes O(1) time, as the total number of items is stored in a variable and is not calculated each time the method is run.
7. Add throws an exception if the array cannot be correctly allocated, while remove throws an exception if remove is called when there is no valid data in the array.
8. The array is in a circular fashion, as it wraps around itself in the correct way.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
The grow() method would have to be removed or reimplemented. If you use the same logic that governs resizing a queue, the new, larger stack would be in the reverse order. The definition of a stack means that the most recent item added would be removed first, which then would be added to the new stack, and be the first thing added to the stack instead of being the most recent. Then, you would only need one of either "numItems" or "front". The definition of a stack restricts the addition and removal of items on one end of the array, so you only need one variable to store the length of the array. The number of items in the array will always be one more than the index of the array that contains the most recently added data.
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I would tell the students next semester to really be careful with your thinking before you code. I jumped in to coding, and I was not really sure what I was doing. I was able to figure it out after class on Monday, but I made my life much harder by acting before thinking. I also did not really think through my intial implementations of the methods, which caused issues with add() and remove(). Then, really pay attention that you change the instance variables, I forgot to reset variables or increment them in various places suprisingly often.
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
The ":" symbol denotes inheritance. In the example given, in C++ it would be written class ArrayQueue: desiredVariableScope Queue
#### 5. What is the purpose of "templates" in C++?
Templetes in C++ allow for containers to be created independent of a specific data type. This allows the template to be versitle, and be used with any data type. Without using a template, the container would only work for a specific data type, which is nowhere close to as useful as a container defined using a template.
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
You need to declare an int pointer, by using int*. This gives a pointer that points to an integer value. Then, you declare that it is an array using the statement int* variableName = new dataType[numberOfSlots]. 
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The class destructor allows the program to reallocate a specific part of memory in C++. It is important to destruct the class to avoid a memory leak, which is caused by a program using too much memory, and the only way to prevent this is to delete old instances of classes. Java does not need the destructor because it utilizes a garbage collector, that automatically deletes instances of variables after they are not needed.