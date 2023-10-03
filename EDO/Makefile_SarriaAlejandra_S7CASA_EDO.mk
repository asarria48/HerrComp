SOURCE = SarriaAlejandra_S7C1_EDO.cpp

CXX = g++

FLAGS = -std=c++11 -Wall

EULER = euler.dat

LEAPFROG = leapfrog.dat

PLOTS = PLOTS_SarriaAlejandra_S7C2_EDO_py.ipynb

all: $(EULER) $(LEAPFROG) plot

$(EULER) $(LEAPFROG): $(SOURCE)
	CXX FLAGS -o $(EULER) $(SOURCE) -DEULER
	CXX FLAGS -o $(LEAPFROG) $(SOURCE) -DLEAPFROG

euler: $(EULER)
	./$(EULER)

leapfrog: $(LEAPFROG)
	./$(LEAPFROG)

plot: $(EULER) $(LEAPFROG)
	python $(PLOTS)

clean:
	rm -f $(EULER) $(LEAPFROG)

cleanall: clean
	rm -f $(EULER) $(LEAPFROG) $(SOURCE)




