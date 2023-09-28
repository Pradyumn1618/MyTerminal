terminal.exe: main.o myls.o ps.o cp.o mymv.o grep.o pse.o
	gcc main.o myls.o ps.o cp.o mymv.o grep.o pse.o -o terminal -lreadline
main.o: main.c
	gcc -c main.c -o main.o -lreadline
myls.o: myls.c 
	gcc  -c myls.c -o myls.o -lreadline
ps.o: ps.c 
	gcc -c ps.c -o ps.o -lreadline
cp.o: cp.c 
	gcc -c cp.c -o cp.o -lreadline
mymv.o: mymv.c 
	gcc -c mymv.c -o mymv.o -lreadline
grep.o: grep.c 
	gcc -c grep.c -o grep.o -lreadline
pse.o: pse.c 
	gcc -c pse.c -o pse.o -lreadline
