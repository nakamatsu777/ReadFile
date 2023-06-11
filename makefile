CC = gcc
PGNAME = ReadFile.exe
OBJS = main.o logger.o
COMP = $(CC) -Wall -I ./include -c

$(PGNAME): $(OBJS)
	$(CC) -o $@ $^

logger.o: logger.c
	$(COMP) $<

main.o: main.c
	$(COMP) $<
clean:
	rm -f $(PGNAME) $(OBJS)
