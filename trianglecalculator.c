/*Triangle Calculator*/

#include <stdio.h>
#include <math.h>

struct triangle{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
};

struct triangle one;

double areacalc();



int main() {

    one.x1=0;
    one.y1=0;
    one.x2=3;
    one.y2=0;
    one.x3=3;
    one.y3=4;
    
    double area=areacalc();

    
	return 0;
}

double areacalc(){
    double base = sqrt(((one.x1-one.x2)*(one.x1-one.x2))+((one.y1-one.y2)*(one.y1-one.y2)));
    printf("%lf \n",base);
    double m1 = ((one.y1-one.y2)/(one.x1-one.x2));
    printf("%lf \n",m1);
    double b1 = one.y1-m1 * one.x1;
    printf("%lf \n",b1);
/* issue here for when the slope is 0 or the line is vertical  */
    double m2 = pow(m1,1);
    printf("%lf \n",m2);
    double b2 = one.y3-m2 * one.x3;
    double ix = (b1-b2)/(m1-m2);
    double iy = m1 * ix+b1;
    double height = sqrt(((one.x3-ix) * (one.x3-ix))+((one.y3-iy) * (one.y3-iy)));
    double area = 0.5 * base * height;
    printf("%lf",area);
    return area;
}
