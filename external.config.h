# CPPTRAJ config for external libraries.
# configured using: ./configure -fftw3 gnu
NVCC=
NVCCFLAGS=

%.o : %.cu
	@echo NVCC $<
	@$(NVCC) $(DBGFLAGS) $(NVCCFLAGS) -c -o $@ $<

CC=gcc
CFLAGS= -Wall  -O3    $(DBGFLAGS)

.c.o:
	@echo CC $<
	@$(CC) $(DIRECTIVES) $(INCLUDE) $(CFLAGS) -c -o $@ $<

FC=gfortran
F77FLAGS= -Wall  -O3    $(DBGFLAGS)

.f.o:
	@echo FC $<
	@$(FC) $(DIRECTIVES) $(INCLUDE) $(F77FLAGS) -c -o $@ $<

ZLIB_FLAG=-lz
