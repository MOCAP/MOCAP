function [divisor] = quarternion_magnitude (a)
    divisor = sqrt( a(1)^2 + a(2)^2 + a(3)^2 + a(4)^2 );
    