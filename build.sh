set -e

verilator --cc src/reg_file.v --exe testbench.cpp
make -C obj_dir -j4 -f Vreg_file.mk Vreg_file