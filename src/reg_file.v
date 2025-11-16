module reg_file (
    input  wire [31:0] in_data,
    input  wire [4:0]  in_reg,
    input  wire        write,

    input  wire [4:0]  out_reg1,
    input  wire [4:0]  out_reg2,

    input  wire        reset,
    input  wire        clk,

    output wire [31:0] data_out1,
    output wire [31:0] data_out2
);

reg [31:0] registers [0:31];

assign data_out1 = registers[out_reg1];
assign data_out2 = registers[out_reg2];

integer i;

always @(posedge clk or posedge reset) begin
    if (reset)
        for (i = 0; i < 32; i++) begin
            registers[i] <= 0;
        end
    else if (write)
        if (in_reg != 5'b0)
            registers[in_reg] <= in_data;
end

endmodule