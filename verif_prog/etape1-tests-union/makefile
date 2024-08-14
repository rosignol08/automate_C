
all: test-union assert-union

union:
	gcc -o union main-union-testable.c fonctions.c hashcode.c liste.c

test-union: debut-test-main-union.c
	gcc -DNDEBUG -o test-union debut-test-main-union.c fonctions.c hashcode.c liste.c

assert-union: debut-test-main-union.c
	gcc -o assert-union debut-test-main-union.c fonctions.c hashcode.c liste.c

clean:
	rm -f union test-union assert-union
