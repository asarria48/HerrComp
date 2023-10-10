all: pdf

pdf: SarriaAlejandra_RESULTADOS_S8CASA_EDO2.tex euler leapfrog rungekutta eulerorbita leapfrogorbita
	latex SarriaAlejandra_RESULTADOS_S8CASA_EDO2.tex

euler: euler_2.dat plots_sarriaalejandra_resortes8casa_edo2.py
	python plots_sarriaalejandra_resortes8casa_edo2.py

leapfrog: leapfrog_2.dat PLOTS_SarriaAlejandra_resorteS8CASA_EDO2.py
	python PLOTS_SarriaAlejandra_resorteS8CASA_EDO2.py

rungekutta: rungekutta_2.dat PLOTS_SarriaAlejandra_resorteS8CASA_EDO2.py
	python PLOTS_SarriaAlejandra_resorteS8CASA_EDO2.py

eulerorbita: EulerPlanetas.dat PLOTS_SarriaAlejandra_S8planetasCASA_EDO2.py
	python PLOTS_SarriaAlejandra_S8planetasCASA_EDO2.py

leapfrogorbita: LeapfrogPlanetas.dat PLOTS_SarriaAlejandra_S8planetasCASA_EDO2.py
	python PLOTS_SarriaAlejandra_S8planetasCASA_EDO2.py

EulerPlanetas.dat: SarriaAlejandra_S8planetasCASA_EDO2.cpp
	g++ SarriaAlejandra_S8planetasCASA_EDO2.cpp
	./SarriaAlejandra_S8planetasCASA_EDO2.cpp

LeapfrogPlanetas.dat: SarriaAlejandra_S8planetasCASA_EDO2.cpp
	g++ SarriaAlejandra_S8planetasCASA_EDO2.cpp
	./SarriaAlejandra_S8planetasCASA_EDO2.cpp

euler_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp

leapfrog_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp

rungekutta_2.dat: SarriaAlejandra_resorteS8CASA_EDO2.cpp
	g++ SarriaAlejandra_resorteS8CASA_EDO2.cpp
	./SarriaAlejandra_resorteS8CASA_EDO2.cpp
