module decoder24_behaviour(en,a,b,y);
   // input port
   input en,a,b;

   // use reg to store the output value
   output reg [3:0]y;
   // always is used in design block 
   // only in Behavioural modeling.
   
   always @(en,a,b)
     begin
       // using condition if statement 
       // implement the 2:4 truth table
       if(en==0)
         begin
           if(a==1'b0 & b==1'b0) y=4'b1110;
           else if(a==1'b0 & b==1'b1) y=4'b1101;
           else if(a==1'b1 & b==1'b0) y=4'b1011;
           else if(a==1 & b==1) y=4'b0111;
           else y=4'bxxxx;
         end
       else
        y=4'b1111;
     end
endmodule
