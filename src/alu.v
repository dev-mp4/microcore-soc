module alu (
    input  [31:0] a,
    input  [31:0] b,
    input  [6:0]  funct7,
    input  [2:0]  funct3,
    output reg [31:0] result
);

always @(*) begin
    case (funct3)
        3'b000: begin
            // ADD / SUB
            if (funct7 == 7'b0000000)
                result = a + b; // ADD
            else if (funct7 == 7'b0100000)
                result = a - b; // SUB
            else
                result = 32'b0;
        end
        3'b001: result = a << b[4:0]; // SLL
        3'b010: result = (a < b) ? 32'b1 : 32'b0; // SLT
        3'b011: result = ($unsigned(a) < $unsigned(b)) ? 32'b1 : 32'b0; // SLTU
        3'b100: result = a ^ b; // XOR
        3'b101: begin
            // SRL / SRA
            if (funct7 == 7'b0000000)
                result = a >> b[4:0]; // SRL
            else if (funct7 == 7'b0100000)
                result = $signed(a) >> b[4:0]; // SRA
            else
                result = 32'b0;
        end
        3'b110: result = a | b; // OR
        3'b111: result = a & b; // AND
        default: result = 32'b0;
    endcase
end

endmodule
