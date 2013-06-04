function [j] = objective_jacobian (q, d)
    x=2;
    y=3;
    z=4;
    
    j_1_1 =  2*d(y)*q(4) + -2*d(z)*q(3);
    j_1_2 =  2*d(y)*q(3) + 2*d(z)*q(4);
    j_1_3 = -4*d(x)*q(3) + 2*d(y)*q(2) - 2*d(z)*q(1);
    j_1_4 = -4*d(x)*q(4) + 2*d(y)*q(1) + 2*d(z)*q(2);
    
    
    j_2_1 = -2*d(x)*q(4) + 2*d(z)*q(2);
    j_2_2 =  2*d(x)*q(3) + -4*d(y)*q(2) + 2*d(z)*q(1);
    j_2_3 =  2*d(x)*q(2) + 2*d(z)*q(4);
    j_2_4 = -2*d(x)*q(1) + -4*d(y)*q(4) + 2*d(z)*q(3);
    
    j_3_1 =  2*d(x)*q(3) + -2*d(y)*q(2);
    j_3_2 =  2*d(x)*q(4) + -2*d(y)*q(1) + -4*d(z)*q(2);
    j_3_3 =  2*d(x)*q(1) + 2*d(y)*q(4) - 4*d(z)*q(3);
    j_3_4 =  2*d(x)*q(2) + 2*d(y)*q(3);

    j = [j_1_1, j_1_2, j_1_3, j_1_4; j_2_1, j_2_2, j_2_3, j_2_4; j_3_1, j_3_2, j_3_3, j_3_4];
    