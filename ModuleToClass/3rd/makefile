merge_line: merge_line.o get_line1.o get_line2.o
	cc -o merge_line merge_line.o get_line1.o get_line2.o

merge_line.o: merge_line.c get_line1.h get_line2.h
	cc -c merge_line.c

get_line1.o: get_line1.c get_line1.h
	cc -c get_line1.c

get_line2.o: get_line2.c get_line2.h
	cc -c get_line2.c
