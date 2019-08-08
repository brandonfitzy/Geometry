/*circle calculator*/

#include <stdio.h>

struct cirlce{
    float x;
    float y;
    float r;
};

struct cirlce one;
double calcarea();
void changeradius(double n);
void translate(double x, double y);
void describecircle();

int main() {
    one.x=0;
    one.y=0;
    one.r=1;
    describecircle();
    double area=calcarea();
    changeradius(2.3);
    describecircle();
    area=calcarea();
    describecircle();
    translate(3,4);
    describecircle();
	return 0;
}

void describecircle(){
    printf("Circle centered at (%lf,%lf) with radius %lf \n", one.x, one.y, one.r);
}

double calcarea(){
    double area = 3.14*one.r*one.r;
    printf("The area is %lf \n", area);
    return area;
}

void changeradius(double n){
    one.r+=n;
}

void translate(double x, double y){
    one.x+=x;
    one.y+=y;
}
