/*Triangle Calculator*/

#include <stdio.h>
#include <stdlib.h>
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
    one.x2=0;
    one.y2=4;
    one.x3=3;
    one.y3=0;
    
    areacalc();

    
	return 0;
}

double areacalc(){
    double base = abs(sqrt(((one.x1-one.x2)*(one.x1-one.x2))+((one.y1-one.y2)*(one.y1-one.y2))));
    double m1 = ((one.y1-one.y2)/(one.x1-one.x2));
    double b1 = one.y1-m1 * one.x1;
	double height;
/* issue here for when the slope is 0 or the line is vertical  */
	if (m1==0){
		height= abs(one.y3-one.y1);
	} else if (one.x1==one.x2){
		height= abs(one.x3-one.x1);
	} else {
		double m2 = pow(m1,-1);
		double b2 = one.y3-m2 * one.x3;
		double ix = (b1-b2)/(m1-m2);
		double iy = m1 * ix+b1;
		height = abs(sqrt(((one.x3-ix) * (one.x3-ix))+((one.y3-iy) * (one.y3-iy))));
	}
	double area = 0.5 * base * height;
	printf("%lf",area);
	
    return area;
}
