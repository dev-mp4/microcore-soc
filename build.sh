set -e

verilator -Wall --cc src/alu.v --exe testbench.cpp
make -C obj_dir -j4 -f Valu.mk Valu