CPPFLAGS += -std=c++11 -g #-W -Wall #-g -Wno-unused-parameter
CPPFLAGS += -I include
CFLAGS += -g
#CPPFLAGS = -W -Wall


all : clean bin/c_compiler

test : all m

t:
	bin/c_compiler --translate b.c -o b.py

m:
	bin/c_compiler -S test.c -o result.s


src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/c_compiler : src/c_compiler.o src/parser.tab.o src/lexer.yy.o src/parser.tab.o include/ast_implement.o include/mips_implement.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^


#src/c_compiler.o : src/c_compiler.cpp
	#g++ $(CPPFLAGS) -c -o src/c_compiler.o $^

#include/%.o : include/%.cpp
	#$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -f src/*.tab.cpp
	rm -f src/*.tab.hpp
	rm -f src/*.yy.cpp
	rm -f src/*.output
	rm -f bin/*
	rm -f src/*.o
	rm -f include/*.o
