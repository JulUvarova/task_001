CFLAGS=-Wall -Wextra -Werror -std=c11

all: clean roman_to_arabic universal_convert

roman_to_arabic: roman_to_arabic.c
	gcc $(CFLAGS) roman_to_arabic.c -o roman_to_arabic

universal_convert: universal_convert.c
	gcc $(CFLAGS) universal_convert.c -o universal_convert

clean:
	rm -rf *.o *.a universal_convert roman_to_arabic

check:
	clang-format -n *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./universal_convert

# test:
# 	pytest --color=yes -v --tb=short tests