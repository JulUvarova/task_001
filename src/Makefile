CFLAGS=-Wall -Wextra -Werror

roman_to_arabic: clean roman_to_arabic.c 
	gcc $(CFLAGS) roman_to_arabic.c

universal_convert: clean universal_convert.c 
	gcc $(CFLAGS) universal_convert.c

clean:
	rm -rf *.o *.a

check:
	clang-format -n *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./a.out