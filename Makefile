CC := gcc
CFLAGS := -Wall -O2
EXEC := vector

$(EXEC): src/main.c src/vector.c
	$(CC) $(CFLAGS) src/main.c src/vector.c -o $(EXEC)

run: $(EXEC)
	@./$(EXEC)

clean: $(EXEC)
	@rm $(EXEC)
