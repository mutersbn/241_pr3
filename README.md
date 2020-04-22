# 241_pr3

1) A linked list must be implemented and maintained for data being processed in
memory. Information about a product (item) is stored in a node on the list.
Each node is a C structure.

2) On the list, each node has the following data fields (members of the
	structure) describing a product:
	a) Product name - a string of fewer than 20 characters without white spaces
	b) Quantity value - a float point variable, representing the numerical
	amount of a prodcut.
	c) Quantity unit (e.g. pounds, bottles, pieces, etc.) - a string of fewer
	than 20 characters without white spaces.
	d) Price value - a float point variable, representing the numerical value
	of the price.
	e) Price unit (e.g. dollars-per-pound, dollars-per-bottle, dollars-each,
		etc.) - a string of fewer than 20 characters without white spaces.

3) When the program starts, load available products from file, though when it
starts for the FIRST TIME, file will be empty. Then, provide the user with a
menu of choices. 

4) The following functionalities must be included:

	   i) Add product to the store
	  ii) Purchase product from the store
	 iii) Check price of a product
	  iv) Show products in the store
	   v) Clean up a product from the store
	  vi) Find product
	 vii) Inventory
	viii) Done for today

5) Implement project in separate files. 
	a) main.c
	b) operations.h
	c) operations.c

6) Makefile must include:
	a) all
	b) run
	c) clean


