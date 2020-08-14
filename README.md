# LS-List
Repository for list library for C++ I created.

## Class Summary
This header file includes 4 template classes, `list`, `stack`, `queue`, and a binary search tree  `bst` class. 

## list
`list` is a template class that can be created with any data. list grows and shrinks dynamically.
### Features
list is general purpose, and allows:
- adding items to the front or back of list
- removing items either by finding them or by specifying an index
- getting items either by finding them or by specifying an index, both allowing item to be changed with `=`
- sorting list using quicksort algorithm, including using basic `>` operator or by pointer to function
- condensing list with condensing algorithm
- find the size of the list

### Memory
Lists will automatically free all memory upon destruction. 
Lists can also free all memory by a call to the `clear()` function.

### Exceptions
Exception `exp_out_of_bounds` will only be thrown when trying to access out of bounds elements in the list.
