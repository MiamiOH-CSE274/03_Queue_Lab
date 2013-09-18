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

1. Working. Remove takes constant time because we are simply removing the last item that was placed into the queue. 
2. Working. Add takes constant time because we are adding the element to the next avaliable spot in the array which is constant time as we have learned based on the runtime of add.
3. Working. I used an if statement to test for a full array and if full the array grows to double its size if necessary.
4. Working. Grow takes linear time because we are simply copying each element and adding it to the new array so the time is proportional to the number of elements in the array. 
5. Working. By calling delete [] backingArray (as I did) in both the grow and destructor methods there shouldn't be a memory leak.
6. Working. Because we are using an array we have to keep track of how many items are in that array with a variable. So we simply return the tracking variable which is constant time.
7. Working. I know for sure my remove exception is working since it was tested with Dr. Brinkman's code. I am pretty sure that my add (which is really in grow) exception is working because Dr. Brinkman helped me to figure out how to do it. 
8. Working. My array is using the circular fashion because tests 1, 2 and 3 were all passed and based on how my code is written users should be able to tell I am using a circular array. 

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
The one variable we could get rid of in is front since the stack is based on LIFO, thus not needing to have a front variable. We need to keep grow,  numItems and backingArraySize because we still need to grow the array if it becomes full and we use backingArraySize and numItems to test for this. 

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
One thing that confused me in the beginning was the exception handling for the add method which you really place in the grow method.  

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
class ArrayQueue : public queue 

#### 5. What is the purpose of "templates" in C++?
The purpose of templates in C++ is so that we can use different data types as necessary without having to state this up front. This allows for us to not have to change the implementation files everytime we want to use a different variable type. 

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
The purpose of the class destructor is to make sure we don't have a memory leak after we are done using the allocated memory that we needed so the destructor de-allocates this memory. We don't need them in java because the garbage collector does this for us. 