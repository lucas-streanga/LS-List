# LS-List
Repository for list library for C++ I created. Everything is in the namespace `ls`. 

## Class Summary
This header file includes 4 template classes, `list`, `stack`, `queue`, and a binary search tree  `bst` class. 

## list
`list` is a template class that can be created with any data. lists grow and shrink dynamically.

### Overhead
An empty `list` has an overhead of 16 bytes on a 64-bit system. Each additional item added to the list will result in another 8 bytes of overhead. 

### Features
`list` is general purpose, and allows:
- adding items to the front or back of list
- removing items either by finding them or by specifying an index
- getting items either by finding them or by specifying an index, both allowing item to be changed with `=`
- sorting list using quicksort algorithm, including using basic `>` operator or by pointer to function
- condensing list with condensing algorithm
- find the size of the list

In addition, `list` can be inherited from, as it has a virtual destructor.

### Function Summary
- `is_empty` will return a `bool`. `true` indicates the list is empty, `false` indicates the list is not.
- `add_front(data)` will add data to the front of the list.
- `add_back(data)` will add data to the back of the list.
- `at(int index)` will return a reference to whatever data is at the specified index. Note counting begins at 0, so the first item is at index 0. Will throw exception if index is out of bounds. 
- `operator []` same functionality as `at`
- `remove(int index)` will return `void` and will delete an item in the list at the specified index.
- `remove_item(data)` will return `void` and will delete the specified item in the list. This is done using the equivilence operator. Nothing will be removed if the item is not found.
- `size()` will return an `int` corresponding to the size of the list. Empty list is 0.
- `clear()` will return `void` and `delete` all data within the list.
- `swap(int index1, int index2)` will return `void` and will swap the data at the given index.
- `sort()` will return `void` and will sort the list via the quicksort algorithm. Note: sorting uses `<` operator.
- `csort(bool(*lessthan) (data, data))` will return `void` and will sort the list using quicksort and a specified pointer to a function to circumvent the usual `<` operator. This allows customized sorting.
- `find(data)` will return a pointer to the data you want to find in the list. If it is not found, `nullptr` is returned. Note: equivilance operator is used.
- `find_index(data)` will return an `int` corresponding to the index in the list of a specified item. -1 will be returned if the item is not found. Note: this uses the equivilance operator.
- `condense()` will return `void` and will delete any repeating items in the list, condensing it. Note: equivilance operator is used. 

### Memory
Lists will automatically free all memory upon destruction. 
Lists can also free all memory by a call to the `clear()` function.

### Exceptions
Exception `exp_out_of_bounds` will only be thrown when trying to access out of bounds elements in the list.

## stack
`stack` is a template class inherited from `list`. Stacks will also grow and shrink dynamically and function very similar to lists, with restricted access to provide LIFO functionality.

### Features
`stack` is general purpose, and allows:
- pushing a new item onto the stack
- popping an item off the stack
- peaking at the item on top of the stack

In addition, `stack` can be inherited from, as it has a virtual destructor. 

### Function Summary
- `pop()` will return the top element in the stack and will remove it from the stack.
- `peak()` will return a reference to the top element in the stack.
- `push(data)` will return void and will add the data to the top of the stack.

### Memory
Stacks will automatically free all memory upon destruction. 
Stacks can also free all memory by a call to the `clear()` function.

### Exceptions
Exception `exp_out_of_bounds` will only be thrown when trying to access out of bounds elements in the stack.

## queue
`queue` is a template class inherited from `list`. Queues will also grow and shrink dynamically and function very similar to lists, with restricted access to provide FIFO functionality.

### Features
`queue` is general purpose, and allows:
- enqueueing a new item onto the queue
- dequeueing an item off the queue
- peaking at the item at the front of the queue

In addition, `queue` can be inherited from, as it has a virtual destructor. 

### Function Summary
- `dequeue()` will return the first element in the queue and will remove it from the queue.
- `peak()` will return a reference to the first element in the queue.
- `enqueue(data)` will return void and will add the data to the front of the queue.

### Memory
Queues will automatically free all memory upon destruction. 
Queues can also free all memory by a call to the `clear()` function.

### Exceptions
Exception `exp_out_of_bounds` will only be thrown when trying to access out of bounds elements in the queue.

