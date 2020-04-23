EXEC := operations

all: operations.c main.c operations.h
	gcc operations.c main.c -g -o $(EXEC)

run: 
	./$(EXEC)

test:

valgrind:
	valgrind --leak-check=yes $(EXEC)

gdb:
	gdb --args $(EXEC)

clean:
	$(RM) $(EXEC) vgcore.*
