CC = gcc 
EXEC = output

output: $(EXEC).o 
	$(CC)  $(EXEC).o  -nostartfiles -no-pie

output.o :  $(EXEC).asm
	 nasm -f elf64 $(EXEC).asm


clean:
	rm -f *.o 
