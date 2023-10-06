prog:
	g++ SarriaAlejandra_S8CASA_EDO2.cpp
	./SarriaAlejandra_S8CASA_EDO2

plot:
	python PLOTS_S8CASA_EDO2.py

clean:
	rm - f SarriaAlejandra_S8CASA_EDO2 *.log *.aux *.out

all: prog plot clean
