function [q] = quart_multiplication (a, b)
   q_1 = a(1)*b(1) - a(2)*b(2) - a(3)*b(3) - a(4)*b(4);
   q_2 = a(1)*b(2) + a(2)*b(1) + a(3)*b(4) - a(4)*b(3);
   q_3 = a(1)*b(3) - a(2)*b(4) + a(3)*b(1) + a(4)*b(2);
   q_4 = a(1)*b(4) + a(2)*b(3) - a(3)*b(2) + a(4)*b(1);
   q = [q_1,q_2,q_3,q_4];

    
   
    
    