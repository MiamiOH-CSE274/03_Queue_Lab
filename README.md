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

1. I think remove takes O(1) time because I wrote it according to what the book described. I do not really understand the big-oh notation, so expect to see me in office hours soon.
2. Add calls grow, so it takes O(n) time.
3. I think this requirement was met. I only called grow() in the add method, and only if numItems == backingArraySize. Grow does create an array that is twice the size of the original.
4. I think grow takes O(n) time. I followed the model in the book, which also takes O(n) time.
5. As far as I can tell I am not leaking memory. The destructor deletes the backing array, and then takes care of backingArray, which has become a dangling pointer, by setting it to NULL.
6. I think getNumItems takes O(1) time. All it does is return a value.
7. Remove throws an exception if there are no elements in the array. I am not sure what exceptions I should throw in add.
8. I did use a circular array. When adding and removing elements, I made sure that the elements could "wrap around" to the beginning as needed, and that the front would always point to the true front of the queue.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
According to Open Data Structures, if you were to implement an Stack instead of an Queue, only some methods and variables would change. Stack and Queue both have private variables for the backing array, the length of the array, and the number of items in that array. Stack, however, does not have a variable for the front of the queue like ArrayQueue does. Since elements are added and removed from the back of the queue, the front of the queue would not be used for operations. Stack would have push(x), which would function much like the add(x) method in Queue - it would add the element to the back of the queue. Both add(x) and push(x) should call on a grow() function that doubles the size of the array if the number of elements in the queue equals the size of the backing array. The final method would be the one that removes an element. For Queue, this would be the remove() function, and it would remove an element from the front of the queue. For Stack, the pop() method would remove and element from the back of the queue. To do this a variable that keeps track of the last element in the queue could be useful. 
#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
I do not understand the notion of O(1), O(n), etc. time or how to determine the appropriate time a function takes. One piece of advice I would give to students next semester would be to take notes on the reading and really make sure you understand it. Doing that really helped me on this assignment and helped me better understand circular arrays and Array-Based Lists.
#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
To write the equivalent of "class ArrayQueue extends Queue" in C++, you would write "class ArrayQueue : public Queue". In more general terms, the syntax is as follows: "class derivedClass : access-specifier baseClass". Source: http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
#### 5. What is the purpose of "templates" in C++?
A template is used when you do not want to specify the data type of an object, return type, or parameter type. This allows for more flexibility in the code, because a user can use whatever data type they want in place of T (ex: int, String, etc.). "T" acts as a placeholder, and it is "filled in" with the correct type at run time.
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
The syntax is as follows: int* arrayName = new int[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The destructor deallocates the memory used in the class to prevent memory leaks. It makes sure that there are no dangling pointers, which point to a space in memory that no longer holds an object, or a memory leak where the space in memory still holds an object but is no longer reachable. Java does not need the destructor because it has a "garbage collector" that looks at the heap and deletes objects that are not in use. Therefore, the deallocation of memory is automatic, so the programmer need not explicitly destruct the class. Source used: http://www.oracle.com/webfolder/technetwork/tutorials/obe/java/gc01/index.html