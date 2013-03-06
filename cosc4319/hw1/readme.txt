Hard copy due by Wednesday September 5th, 5:45PM in class.
This is an individual work (not a group effort). Please be aware
of Academic Dishonesty Policy.

The following information may be useful in solving the homework.

(a) At least one VTable is created for each class with virtual functions.
(b) The order of functions in the table will be consistent with the order
of functions in the corresponding base class VTable.
(c) Each virtual function will have an entry in the respective VTable.
		Non-virtual functions won't.
(d) If a function is overridden by a class, then the VTable entry in this 
	class' VTable will refer to the overridden implementation.
(e) If a function is not overridden by a class, then the VTable entry in this
	class' VTable will refer to the one from the base class.
(f) Destructors in derived class are generally considered to be overriding
	the destructors in base class, even though the names are different. 
	(of course these do not behave 100% like virtual functions, but not
	an issue for what our focus is here).

You may refer to an example at the following URL: 
http://www.cs.uh.edu/~svenkat/lib/assignments/OOP/Summer2000/HW4

For the given code (in file code.cpp), answer the following questions:

1. How many VTables will be created for the given program?


2. Draw the VTables showing the function pointers in the table and 
what they refer to. Also show how the one object relates to the 
VTable(s).





