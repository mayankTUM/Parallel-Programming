#include <stdio.h>
#include <math.h>
#define STEPS 1000000
int main(int argc, char** argv) {
    
    double step_size = 1.0/STEPS, t = 0.5 * step_size, sum = 0.0;
    while(t < 1.0)
    {
       sum+=sqrt(1-t*t) * step_size;
       t+=step_size;
    }
    sum*=4;
    printf("Computed PI = %.10lf\n", sum);
    printf("Difference to Reference is %.10lf\n", M_PI - sum); 
    return 0;
}

