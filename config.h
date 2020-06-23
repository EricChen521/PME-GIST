# config.h for cpptraj
# configured using: ./configure -fftw3 gnu

CPPTRAJHOME="/mdcalc/eric/softwares/test/PME-GIST"
CPPTRAJBIN="/mdcalc/eric/softwares/test/PME-GIST/bin"
CPPTRAJLIB="/mdcalc/eric/softwares/test/PME-GIST/lib"

INSTALL_TARGETS= install_cpptraj

SHARED_SUFFIX=.so
DIRECTIVES= -D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64 -DLIBPME -DHAVE_FFTWD=1 -DBUILDTYPE='"GitHub"' -DGITHASH='"125ce7df35b6db74847fee83a13f48faa71132b3"' -DBINTRAJ -DHASBZ2 -DHAS_TNGFILE -DHASGZ -DFFTW_FFT -DUSE_SANDERLIB -DENABLE_DTR
INCLUDE= -Itng -Iarpack -Ireadline -Ixdrfile -I/mdcalc/eric/softwares/Amber19/amber-master/include

LIBCPPTRAJ_TARGET=nolibcpptraj

CUDA_TARGET=

READLINE_TARGET=readline/libreadline.a
READLINE_LIB=readline/libreadline.a

XDRFILE_TARGET=xdrfile/libxdrfile.a

TNGFILE_TARGET=tng/libtng_io.a

ARPACK_TARGET=arpack/libarpack.a

FFT_TARGET=

CPPTRAJ_LIB= arpack/libarpack.a -llapack -lblas -lfftw3 /mdcalc/eric/softwares/Amber19/amber-master/lib/libsander.so -lgfortran
LDFLAGS= -lnetcdf -lbz2 tng/libtng_io.a -lz xdrfile/libxdrfile.a    
SFX=
EXE=

CC=gcc
CFLAGS= -Wall  -O3    $(DBGFLAGS)

.c.o:
	@echo CC $<
	@$(CC) $(DIRECTIVES) $(INCLUDE) $(CFLAGS) -c -o $@ $<

CXX=g++
CXXFLAGS= -Wall  -O3     -std=gnu++11 $(DBGFLAGS)

.cpp.o:
	@echo CXX $<
	@$(CXX) $(DIRECTIVES) $(INCLUDE) $(CXXFLAGS) -c -o $@ $<

FC=gfortran
FFLAGS= -Wall  -O3  -ffree-form   $(DBGFLAGS)
