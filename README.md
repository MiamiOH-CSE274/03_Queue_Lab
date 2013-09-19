Author
==========
"Emrick, Garrett", emrickgj
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

1. Remove takes 0(1) time as required, it runs in constant time.
2. add takes 0(1) time as it is also constant, unless it has to grow. Add also does not catch the possible throwing caused by the grow method.
3. grow is called from the when the number of items is equal to the backingArraySize, and the array is doubled.
4. grow will only take 0(n) time, assigning the old array to the new, larger array.
5. Memory is not leaked, the old array is deleted when grown, and the new one is deleted within the destructor of the ArrayQueue.
6. getNumItems only takes 0(1) time.
7. add and remove both throw exceptions. Remove throws if the array is empty. Add will throw an exception thrown from the grow method, when not enough memory is available.
8. The array is in a circular fashion, and works as specified rather nicely.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

We would keep the backingArraySize, the array, and also the add, remove, and grow methods. We wouldn't need a front index, and remove would simply remove the index in the array : backingArray[numItems-1]

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

I wasn't really too confused. The only thing I didn't like was that there was no syntax highlighting in visual studio. That made it a little more difficult to read than I would have liked.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
      class ArrayQueue : public Queue    - I believe
#### 5. What is the purpose of "templates" in C++?
      They allow the use of generics as the type. This allows it to be changed upon creation, so the same class could hold ints, doubles, floats, etc, etc, and makes the class a lot more useful.
#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
      int* array = new int[10];
#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
      This is to prevent memory leakage. This allows to delete any variables that may have been created using the new keyword. It can also be useful to do last minute operations upon an objects deletion. I always liked this kind of functionality when working with Android.
