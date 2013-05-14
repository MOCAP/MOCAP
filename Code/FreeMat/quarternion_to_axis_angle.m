function [v, a] = quarternion_to_axis_angle(q)
    
    if (abs(q(1)) > 1) 
        q = quarternion_normalization (q);
    end
    
    %divisor = sqrt( q(2)^2 + q(3)^2 + q(4)^2 );
    %q = a/divisor;
    
    %a = 2 * acos(q(1));
    a = 2*q(1);
    
    s = sqrt(1 - q(1)^2);
    
    if (abs(s) < 0.001)
        x = q(2);
        y = q(3);
        z = q(4);
    else
        x = q(2) / s;
        y = q(3) / s;
        z = q(4) / s;
    end
    
    
    v = [x, y, z];
    