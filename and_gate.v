module and_gate(a, b, y, o,n,r,t,xo,xn);

input a;
input b;
output y;
output o;
output n;
output r;
output t;
output xo;
output xn;

assign y = a & b;
assign o=a|b;
assign n=~(a&b);
assign r=~(a|b);
assign t=~a;
assign xo=a^b;
assign xn=~(a^b);

endmodule
