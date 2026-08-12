
`timescale 1ns/1ps

module tb;
        reg a,b;
        wire y;
        wire o;
        wire n;
        wire r;
        wire t;
        wire xo;
		wire xn;

//instantitate the and gate
and_gate uut(
        .a(a),
        .b(b),
        .y(y),
		.o(o),
		.n(n),
		.r(r),
		.t(t),
		.xo(xo),
		.xn(xn)
);

initial begin

$dumpfile("wave.vcd");
$dumpvars(0,tb);

$display("Truth Table for logic gates");
$display("A B | AND | OR | NAND | NOR | NOT | XOR | XNOR |");
$display("---------------------------------------------------");

a=0;b=0; #10;
$display("%b %b |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  | ",a,b,y,o,n,r,t,xo,xn);

a=0;b=1; #10;
$display("%b %b |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  | ",a,b,y,o,n,r,t,xo,xn);

a=1;b=0; #10;
$display("%b %b |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  | ",a,b,y,o,n,r,t,xo,xn);

a=1;b=1; #10;
$display("%b %b |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  |  %b  | ",a,b,y,o,n,r,t,xo,xn);

$finish;

end

endmodule


