function [q] = quarternion_conjugate(a)
    a(1)=a(1);
    a(2)=-a(2);
    a(3)=-a(3);
    a(4)=-a(4);
    q = a;