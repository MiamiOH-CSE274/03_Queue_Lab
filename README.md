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

1. works.  The element to return is accessed by a single array access, backingArray[front], which always
takes the same amount of time.
2. works.  As with remove(), add() accesses the array directly with 
backingArray[(front + numItems) % backingArraySize].
3. works.  when adding an element, if numItems is >= backingArraySize, grow() is called.
4. works.  grow() uses a single array that runs from i = 0 to i < backingArraySize, which has a time
complexity of O(n) where n is the size of the array.
5. works.  both grow() and the destructor use delete[] when necessary.
6. works.  simply returns the value numItems, no calculations need to be done.
7. works.  remove() and grow() both have checks to test if there are no items left to remove or if we have
run out of room to store new objects.  the check done in grow() will most likely never happen, because
unsigned int's can store very large numbers, and you would probably run out of RAM before that happened, but
its good to check anyway (especially if the assignment wants you to) 
8. works.  The array is used as a circular array, just as is described in the first reading for the homework.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

keep:
1. grow()
2. backingArray
3. numItems (just an index of last thing added)
4. backingArraySize

remove:
1. front

the 'keep' methods and variables were chosen because a Stack will still be stored as an array in the background, so
the actual array and its size will need to be stored, as well as the ability to grow() the array when we need to.
numItems will need to be kept because, unlike a Queue, the first thing remove()'d from a Stack is the last thing you
added, so all you need to store is the index of were the top of the Stack is, because the first element you added
will always be at location backingArray[0], which is why we dont need to store front anymore.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I've never used a circular array before, but I had heard of them before doing this HW, so advice for next semester
students would be to make sure you really understand circular arrays, because they are very important.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

class ArrayQueue : public Queue

#### 5. What is the purpose of "templates" in C++?

To make the data the class is working on more abstract, so instead of using int throught the class, you would use 
T (or whatever you named the template class) so one class could handle any type of data, whether the user wants
to use int, std::string or even a custom class they have made.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int *array = new int[10];

(or std::vector<int> array(10) if using the STL, which you usually use more often in c++ projects)

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

To free up any heap data the class used, such as anything created with 'new'.  Java doesnt need destructors because
it has automatic garbage collection, meaning that whenever a class is done being used, the JVM will free any memory
it was using for use again without the user needing to do anything, (standard) c++ doesnt have this.