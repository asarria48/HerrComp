all: pdf

pdf: resultados.tex euler leapfrog rungekutta
	latex resultados.tex

euler: euler_2.dat plots_sarriaalejandra_resortes8casa_edo2.py
	python plots_sarriaalejandra_resortes8casa_edo2.py

leapfrog: leapfrog_2.dat plots_sarriaalejandra_resortes8casa_edo2.py
	python plots_sarriaalejandra_resortes8casa_edo2.py

rungekutta: rungekutta_2.dat plots_sarriaalejandra_resortes8casa_edo2.py
	python plots_sarriaalejandra_resortes8casa_edo2.py

euler_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp

leapfrog_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp

rungekutta_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp
