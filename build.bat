@echo off

clang -o .\bin\test.exe .\src\file.cpp .\src\dir.cpp .\src\root.cpp .\src\printer.cpp .\src\sorter.cpp .\src\adder.cpp .\src\parser.cpp .\tests\test_print.cpp .\tests\test_sort.cpp .\tests\test_parse.cpp .\tests\test.cpp

.\bin\test.exe

clang -o .\bin\main.exe .\src\file.cpp .\src\dir.cpp .\src\root.cpp .\src\printer.cpp .\src\sorter.cpp .\src\adder.cpp .\src\parser.cpp .\src\main.cpp

.\bin\main.exe test.txt

pause