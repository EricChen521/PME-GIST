#!/bin/bash

. ../MasterTest.sh

# Clean
CleanFiles filter.in filter.crd filter.dat datafilter.dat

INPUT='filter.in'
TOP='../tz2.truncoct.parm7'

# Test 1
TESTNAME="Filter tests"
Requires notparallel

UNITNAME='Basic filter test'
CheckFor netcdf
if [ $? -eq 0 ] ; then
  cat > filter.in <<EOF
trajin ../tz2.truncoct.nc
rms R1 first :2-11
filter R1 min 0.7 max 0.8 out filter.dat
outtraj filter.crd 
EOF
  RunCpptraj "$UNITNAME"
  DoTest ../Test_Outtraj/maxmin.crd.save filter.crd
  DoTest filter.dat.save filter.dat
fi

# Data filter test
cat > filter.in <<EOF
readdata ../Test_Diffusion/diff_a.xmgr.save index 1 name A as dat
datafilter A:2 A:3 min 0.0 max 1.2 out datafilter.dat multi name FA
EOF
RunCpptraj "Data filter test."
DoTest datafilter.dat.save datafilter.dat

EndTest

exit 0
