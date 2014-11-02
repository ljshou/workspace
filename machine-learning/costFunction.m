function [jVal, gradient] = costFunction(theta)
printf("theta = %d\n", theta);
jVal = theta * 2;
gradient = 1;
endfunction
