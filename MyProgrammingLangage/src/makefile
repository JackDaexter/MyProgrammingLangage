CC=gcc
CFLAGS=-Wall
LDFLAGS=-Wall -ly -lfl
EXEC=exo1




compil:   $(EXEC).o lex.yy.c table-symbol.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(EXEC).tab.c $(EXEC).tab.h: $(EXEC).y  table-symbol.h
	bison -d  $(EXEC).y

$(EXEC).tab.o: $(EXEC).tab.c $(EXEC).tab.h 

table-symbol.o: table-symbol.c table-symbol.h 
	$(CC) -o $@ -c $< $(FLAGS)

lex.yy.o: lex.yy.c $(EXEC).tab.h

lex.yy.c: $(EXEC).lex $(EXEC).tab.h  
	  flex -o lex.yy.c $(EXEC).lex

#$(EXEC).o: $(EXEC).c $(EXEC).h
#	$(CC) -c  $(EXEC).c $(CFLAGS)

.%.o: %.c 
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f lex.yy.* *.o
