# Iterators-and-Algorithms
An iterator has a Node<T>* data member called curr, which is initialized to nullptr. Also a boolean called past-
the-end, which is initialized to false.
▪ The DoublyLinkedList begin() method: This method belongs to the DoublyLinkedList class. It returns an
Iterator<T> object. The logic of the method starts by creating a local iterator object. Then set the iterator
object’s pastTheEnd to false (unless the list is empty, then set it to true), and the iterator object’s pointer should
be assigned to the list's head. Finally, the iterator object is returned. 
▪ The assignmentReverse() function works with iterators and not with the collection itself. Note that the
parameters begin and end are iterator objects. Use only these two iterators to find a way to reverse the
containers. These iterators are not node pointers, so this function has no mechanism to request a node’s forward
or backward pointer. In fact, the function will be used on containers that don’t have nodes at all. Only use the
operators ++ (prefix), ++ (postfix), -- (prefix), ==
, !=, and *
. Note that it is easy to solve this for a container of an
odd number of items. An ugly solution is to somehow count up the number of items, then start over and loop
half of that count. A better way is given below.
Suppose a container contains these items: A B C D E. An iterator returned by begin() points to item A, and an
iterator returned by end() points to the past-the-end virtual state just past item E. The first step should be to
decrement that iterator at past-the-end so it is at item E. Now swap the values of the two iterators. The container
should now be E B C D A. Verify if the iterators are the same (operator== or operator!=). They are not the same.
Move the two iterators inwards so they point to items B and D. Swap data. The container should now be E D C
B A. Move the two iterators inwards, so they both point to item C. Verify if the iterators are the same. They are
the same, so the algorithm is done. When the list contains an even number of items, reversing gets a bit tricker,
and so another if statement should check if the iterators are the same after moving the begin forward but before
moving the end backward.
