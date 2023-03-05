merge_line: merge_line.o get_line.o
	c++ -o merge_line merge_line.o get_line.o

merge_line.o: merge_line.cpp get_line.h
	cc -c merge_line.cpp

get_line.o: get_line.cpp get_line.h
	cc -c get_line.cpp
