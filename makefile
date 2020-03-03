CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CPPFLAGS += -I include
#CPPFLAGS = -W -Wall

# invoke by bin/c_compiler --translate [source-file.c] -o [dest-file.py]


bin/c_compiler : src/c_compiler.o src/compiler.tab.o src/lexer.yy.o src/compiler.tab.o  #format reference from Lab2
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler $^

src/c_compiler.o : src/c_compiler.cpp
	g++ $(CPPFLAGS) -o src/c_compiler.o $^



src/parser.tab.cpp src/parser.tab.hpp : src/parser.y
	bison -v -d src/parser.y -o src/parser.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/parser.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex




clean :
		rm src/*.o
		rm bin/*
		rm src/*.tab.cpp
		rm src/*.tab.hpp
		rm src/*.yy.cpp
