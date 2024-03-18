# thembi-ls

STAT

It's basically used to retrieve information about the file pointed to by the pathname, 
so it stores information about files that will later be used.


  "	struct stat			status;
	struct passwd		*u_inf;
	struct group		*g_inf; "

In the above context the "struct stat status" would retrieve information about a file. 
The "struct passwd u-inf" would retrieve information about user id for the file.
The "struct group g-inf" would retrieve information about the group id for the file.

There is stat and lstat. There's not much difference between the two only the fact that with lstat, 
if the pathname is a symbolic link, then it returns information about the link itself, 
not the file that it refers to.
	
MAKEFILE

A Makefile is basically commands with variable names and targets to create object file and to remove them. 
In a single Makefile there can be multiple targets to compile and to remove object.

.H FILE

A header file is a file with extension ".h" which contains declarations for your functions, 
which can be shared or used across your source files.

LINKED LISTS

A linked list is a linear collection of data elemets, 
who's order is not given by their physical placement in memory.

Each element points to the next.It is a data structure consisting of 
nodes which together represents a sequence.

Linked lists are often used because of their efficient insertion and deletion. Can be used to implement stacks, 
queues and other abstract data types.
