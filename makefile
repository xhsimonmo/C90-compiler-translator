CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include
#CPPFLAGS = -W -Wall

# invoke by bin/c_compiler --translate [source-file.c] -o [dest-file.py]
all : src/lexer.yy.cpp  bin/c_compiler

bin/c_compiler : src/c_compiler.o src/parser.tab.o src/lexer.yy.o src/parser.tab.o  #format reference from Lab2
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

src/c_compiler.o : src/c_compiler.cpp
	g++ $(CPPFLAGS) -o src/c_compiler.o $^


src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

clean :
		rm -f src/*.tab.cpp
		rm -f src/*.tab.hpp
		rm -f src/*.yy.cpp
		rm -f src/*.output
		rm -f bin/*
		rm -f src/*.o
