PYTHON_INCLUDE=/usr/include/python2.7


all: PeptideFragmentSingleton.so

# build my C library
libpeptidefragmentsingleton.so: peptide_fragment.o compute_pI.o
	g++ -Wall -shared -o libpeptidefragmentsingleton.so peptide_fragment.o compute_pI.o

peptide_fragment.o: peptide_fragment.hpp peptide_fragment.cpp
	gcc -Wall -g -fPIC -c -o peptide_fragment.o peptide_fragment.cpp
compute_pI.o: compute_pI.c
	gcc -Wall -fPIC -c -o compute_pI.o compute_pI.c

# generate the binding code
peptide_fragment-binding.cpp: peptide_fragment.hpp peptide_fragment.py
	PYTHONPATH=$$PYTHONPATH python peptide_fragment.py > peptide_fragment-binding.cpp

# build the binding code
peptide_fragment-binding.o: peptide_fragment-binding.cpp
	gcc -Wall -fPIC -I$(PYTHON_INCLUDE) -c -o peptide_fragment-binding.o peptide_fragment-binding.cpp

# build the final python module
PeptideFragmentSingleton.so: libpeptidefragmentsingleton.so peptide_fragment-binding.o compute_pI.o  
	g++ peptide_fragment-binding.o compute_pI.o -L. -lpeptidefragmentsingleton -shared -o PeptideFragmentSingleton.so


clean:
	rm -f *.o *.so *.gch peptide_fragment-binding.cpp *~ 2>/dev/null
