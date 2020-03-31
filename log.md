Compiler project time management log

Group name: hair_loss_therapy
Members: Xuefei He(01509951), Shaoxin Mo(01507695)
Start date: 23rd February, after finishing three lab exercises.
Finish date: 31st March (24th originally)
Total time: 37 days.

Week 1: 24/02 - 01/03
We read through the specification on GitHub, decided to start from the structure and implement C-Python translator first. This week will be half in strike so should be able to do something.
Goals (in project):
1.	Finish C-Python translator and start the C-compiler in week 3. (Start: 24/02; Expect: 13/03; Finish: )
Goals (in week):
1.	Read through the C language Standard briefly (Start: 24/02; Expect: 25/02; Finish: 25/02)
2.	Finish Lexer and Parser (Start: 24/02; Expect: 01/03; Finish: 25/02)
3.	Build up and write majority parts of the classes required for C translator (Start: 25/02; Expect: 01/03; Finish: 29/02)
4.	Build base class .hpp file (ast.hpp) for the ast tree (Start: 25/02; Expect: 01/03; Finish: 04/03)
Goal 1: We read until Page 96, finished in time.
Goal 2: Goal 2 is expected to be finished in a week, but we found the Lex specification and Yacc grammar from https://www.lysator.liu.se/c/ANSI-C-grammar-l.html#check-type. We read through them and decided to use them for our compiler so it can be more methodical and save us some time (even though they could be more complex to implement). Because of that the goal was achieved early and a new goal was set(goal 3).
Goal 3: Xuefei is responsible for all of the expression functions and Shaoxin is responsible for all of the statement functions. Finished in time.¬
Goal 4: This part was done together. Main structure of the base class (ast.hpp) was built already till the end of week 1, but there are still some details required to be filled after finishing all translator functions. Because of this, the ast.hpp is finshed a bit late comparing to the expectation.

Week 2: 02/02 – 08/03
Most of this week is in strike, but we were doing the Math’s project at the same time. Instead of working together, we mainly split tasks and work in our own time.
Goals (in week):
1.	Finish writing the base class .hpp file, all the rest translator classes and required functions(e.g. indentation) (Start: 02/03; Expect: 05/03; Finish: 04/03)
2.	Write makefile and c_compiler.cpp (Start: 03/03; Expect: 04/03; Finish: 04/03)
3.	Make C-Python translator work (Start: 05/03; Expect: 08/03; Finish: 15/03 )

Goal 1: Xuefei took this part of work. Finish in time.
Goal 2: Shaoxin took this part of work and finish in time. We made the translator mostly worked but not passing some of the tests at end of the week. Goal 1 and 2 were processed together.
Goal 3: Main work in this part is debugging, which was done together by us. We expected the debugging to be done in 4 days so we left it till end of the week and planned to start the C compiler part on week 3. However, it took more time than expected (until 15/03) so the estimate was a bit too optimistic.


Week 3: 09/03 – 15/03
The debugging took a lot more time than we expected. What we learned is being more prepared and careful when writing code and because of that, we decided to leave at least a week for the debugging of C compiler.
Goals (in week):
1.	Make C-Python translator work (Start: 09/03; Expect: 13/03; Finish: 15/03)
2.	Build up C compiler (Start: 09/03; Expect: 15/03; Finish: 15/03)
Goal 1: Main work in this part is debugging again. Initially both of us were doing this part of work, then we decided to leave it to Shaoxin so that Xuefei can start doing C compiler structure at the same time. We were able to get the ast tree built and the translator pass all the test cases at the end of the week. It was finished later than expected.
Goal 2: Xuefei built up the structure of the compiler including frame change between functions and variable declaration and usage(mainly in mips.hpp). Some of the basic features got worked. The Wednesday’s lab session helped us a lot about.


Week 4: 16/03 – 22/03
The project deadline was pushed until 31st March, so we changed the plan and decided to leave week 5 for passing the test and advanced features.
Goals (in week):
1.	Finish all basic features and majority of the advanced features (Start: 16/03; Expect: 22/03; Finish: 22/03)
2.	Make C compiler compiled for existing features
Goal 1: We finish all basic features and most of the advanced features. Xuefei was working on selection statements, functions, iterations and arrays, while Shaoxin was working on the rest. We achieved the target on time so we leave some more time for debugging and further feature implementations.
Goal 2: We made C compiler compiled and being able to use flex and parser to build up the ast tree, then generate and output assembly code. (Start: 25/03; Expect: 13/03; Finish: 15/03)


Week 5: 23/03 – 30/03
Goals (in week):
We plan to split the tasks between two people, try to finish all the intermediate feature, and partially the advance functions. Xuefei mainly work on array and iteration statement, while Shaoxin worked on some basic functions first because Xuefei plan to go back to China, which will take some time as it involves her quarantine.
1:  After the compiler can now generate code, do debugging on the basic functions that have been written and overall structure. (Start: 25/03; Expect: 27/03; Finished: 26/03)
2:  After debugging the overall and basic bugs, work on arithmetic and other basic function, especially function called with parameter, plan to do the function parameters in one go (no parameter -> less than 4 -> more than 4). (Start: 27/03; Expect: 29/03; Finish: 28/03)
3, work on intermediate features, including global array and work on advance features if possible and time allowed. (Start: 27/03; Expect: 29/03; Finish: 31/03)
Generally this week is quite busy and Xuefei flew back to China,  both partners were quite distracted by flights and other issue due to covid-19 outbreak, overall objects are achieved.
Goal 1 : Achieved by Shaoxin when Xuefei was on the flight back to China.
Goal 2: Shaoxin decided to stick to the plan, however, some structural changes were required for functions with more than 4 parameters, after finishing basic parameter fucntion on 27th, he also worked on it on 28th due to the introduction of calculation of  calculation of SP moved down.

Goal 3, As planned,  Xuefei worked on array, which took a bit longer than expected, Shaoxin took over some debugging for her implementation on iteration. Some more variables and vectors are introduced to compiler as work progressed.



Week 6: 30/03 – 31/03
Planned to keep debugging the existing implementation, do more advance feature if time allows.
Outcome:
In the last two days, time was mainly spent on debugging and Shaoxin also worked on some advance features in these two days, including pointer arithmetic.
Almost all intermediate features have been implemented, also roughly more than half of advance functions for c_compiler are achieved.
The time planning and management overal works although there are some unexpected distractions happened during the development. It helps us to acheive what is expected at the very beginning
