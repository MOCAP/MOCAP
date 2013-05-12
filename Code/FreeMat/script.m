function [q] = script( s_a, s_w, s_s, s_qn1, d_t, s_qe)
    
    %constants
    s_e = [0 1 0 0]; %constant earth magentic field
    s_g = [0 0 0 1]; %gravity
    alpha = 1;

    %normalization of all inputs
    s_a = quarternion_normalization(s_a);
    s_w = quarternion_normalization(s_w);
    s_s = quarternion_normalization(s_s);
    s_qn1 = quarternion_normalization(s_qn1);
    s_qe = quarternion_normalization(s_qe);
    
    %initial values
    %s_Q_e = s_qn1
    s_Q_e = s_qe; 
    
    s_Q_e_prime = 0.5 * quarternion_math ( s_qn1, s_w );
    
    for (i=1:10)
    
    Fb = objective_function(s_Q_e,s_e,s_s);
    Jb = objective_jacobian(s_Q_e,s_e);
    
    Fg = objective_function(s_Q_e,s_g,s_a);
    Jg = objective_jacobian(s_Q_e,s_g);
    
    grad_Fg = transpose(Jg) * Fg;
    grad_Fg = transpose(grad_Fg);
    grad_Fg = quarternion_normalization(grad_Fg)
    
    u_t = alpha * quarternion_magnitude(s_Q_e_prime) * d_t;
    
    
    s_Q_e
    
    
    s_Q_e = s_Q_e - (u_t * grad_Fg);
    
    end
    
    q = s_Q_e;
    
    
    