GUR=/opt/gurobi901/linux64
GURINC=-I $(GUR)/include 
GURLIB=-L $(GUR)/lib -lgurobi_c++ -lgurobi90 -lm 
# GURLIB= $(GUR)/lib/libgurobi_c++.a $(GUR)/lib/libgurobi81.so -lm  
# # GURLIB=-L $(GUR)/lib -lgurobi_c++ -lgurobi81 -lm 
GUROPT=
#$(GURINC) $(GURLIB)


CC=g++
OPTS=-std=c++14 $(GUROPT)
ARGS=

format:
	clang-format-9 *.cpp -i

01: 01_Factorial
	./01_Factorial $(ARGS)

01_Factorial: 01_Factorial.cpp
	$(CC) 01_Factorial.cpp $(OPTS) -o 01_Factorial

02: 02_max
	./02_max $(ARGS)

02_max: 02_max.cpp
	$(CC) 02_max.cpp $(OPTS) -o 02_max

03: 03_classes
	./03_classes $(ARGS)

03_classes: 03_classes.cpp
	$(CC) 03_classes.cpp $(OPTS) -o 03_classes

04: 04_classes
	./04_classes $(ARGS)

04_classes: 04_classes.cpp
	$(CC) 04_classes.cpp $(OPTS) -o 04_classes

05: 05_pointers
	./05_pointers $(ARGS)

05_pointers: 05_pointers.cpp
	$(CC) 05_pointers.cpp $(OPTS) -o 05_pointers

06: 06_new
	./06_new $(ARGS)

06_new: 06_new.cpp
	$(CC) 06_new.cpp $(OPTS) -o 06_new
