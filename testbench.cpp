#include "Vreg_file.h"          // сгенерированный Verilator заголовок для модуля alu
#include "verilated.h"
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);  // инициализация Verilator

    Vreg_file* top = new Vreg_file;  // создаем экземпляр модуля

    top->reset = 1;
    top->clk = 0;
    top->in_data = 0;
    top->in_reg = 0;
    top->write = 0;
    top->out_reg1 = 0;
    top->out_reg2 = 0;
    
    top->eval();

    top->reset = 0;
    top->clk = 1;
    top->in_data = 32;
    top->in_reg = 5;
    top->write = 1;

    top->eval();

    top->clk = 0;

    top->eval();

    top->out_reg1 = 5;

    top->eval();

    std::cout << top->data_out1 << std::endl;

    delete top;
    return 0;
}
