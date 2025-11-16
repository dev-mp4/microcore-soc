#include "Valu.h"          // сгенерированный Verilator заголовок для модуля alu
#include "verilated.h"
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);  // инициализация Verilator

    Valu* alu = new Valu;  // создаем экземпляр модуля

    // Пример входов
    uint32_t a = 15;
    uint32_t b = 3;

    // Пробуем разные комбинации funct3/funct7
    struct TestCase {
        uint8_t funct3;
        uint8_t funct7;
        const char* name;
    } tests[] = {
        {0b000, 0b0000000, "ADD"},
        {0b000, 0b0100000, "SUB"},
        {0b001, 0b0000000, "SLL"},
        {0b010, 0b0000000, "SLT"},
        {0b011, 0b0000000, "SLTU"},
        {0b100, 0b0000000, "XOR"},
        {0b101, 0b0000000, "SRL"},
        {0b101, 0b0100000, "SRA"},
        {0b110, 0b0000000, "OR"},
        {0b111, 0b0000000, "AND"},
    };

    for (auto& t : tests) {
        alu->a = a;
        alu->b = b;
        alu->funct3 = t.funct3;
        alu->funct7 = t.funct7;

        alu->eval();  // шаг симуляции

        std::cout << t.name << ": "
                  << a << " and " << b
                  << " -> " << alu->result << std::endl;
    }

    delete alu;
    return 0;
}
