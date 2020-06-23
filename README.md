# PME-GIST
Particle Mesh Ewald supported Grid Inhomogeneous Solvation Theory

The PME-GIST will give energy values (Electrostatic and VDW) that match with those calculated by Amber plus the calculation is significantly accelated.

This work is done by Eric Chen from Prof. Tom Kurtzman's lab at Lehman College, City University of New York. The code was built on the CPPTRAJ (https://github.com/Amber-MD/cpptraj) from Dan R. Roe and helpme (https://github.com/andysim/helpme) from Andrew Simmonett. 

The installation only has two steps:

1) ./configure -fftw3 gnu
2) make 
