all: ex5a ex5b

ex5a: ex5a.o points.o rectangles.o util.o
	g++ ex5a.o points.o rectangles.o util.o -o ex5a

ex5a.o: ex5a.cc points.h rectangles.h util.h 
	g++ -Wall -c ex5a.cc

points.o: points.cc 
	g++ -Wall -c points.cc 

rectangles.o: rectangles.cc points.h
	g++ -Wall -c rectangles.cc 

ex5b: ex5b.o pointsb.o circles.o rectanglesb.o bst.o gen_arr.o
	g++ ex5b.o pointsb.o circles.o rectanglesb.o bst.o gen_arr.o -o ex5b

ex5b.o: ex5b.cc pointsb.h circles.h rectanglesb.h bst.h gen_arr.h
	g++ -Wall -c ex5b.cc

pointsb.o: points.cc
	g++ -Wall -c pointsb.cc

circles.o: circles.cc pointsb.h gen_arr.h
	g++ -Wall -c circles.cc

rectanglesb: rectanglesb.cc pointsb.h gen_arr.h
	g++ -Wall -c rectanglesb.cc

bst.o: bst.cc 
	g++ -Wall -c bst.cc

gen_arr.o: gen_arr.cc bst.h
	g++ -Wall -c gen_arr.cc
