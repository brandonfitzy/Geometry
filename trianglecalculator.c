/*Triangle Calculator*/

#include <stdio.h>  //for printing
#include <stdlib.h>  //for acos function
#include <math.h>    //for pow function


//the structure of a triangle, three points
struct triangle{
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;
};

//declaring global struct
struct triangle one;

//functions this can do
double areacalc();
void translate(int x, int y);
void yreflect(int x);
void xreflect(int y);
void original();
double anglecalc(int k);

int main() {

	//defining the struct
    one.x1=0;
    one.y1=0;
    one.x2=0;
    one.y2=4;
    one.x3=3;
    one.y3=0;
    
	//preforming some of the functions
    areacalc();
	translate(2,2);
	yreflect(6);
	xreflect(-1);
	original();
	anglecalc(2);
    
	return 0;
}


//function to calculate angles using the points, law of cosines
double anglecalc(int k){
	int angle;
	int a = sqrt(((one.x1-one.x2)*(one.x1-one.x2))+((one.y1-one.y2)*(one.y1-one.y2)));
	int b = sqrt(((one.x2-one.x3)*(one.x2-one.x3))+((one.y2-one.y3)*(one.y2-one.y3)));
	int c = sqrt(((one.x1-one.x3)*(one.x1-one.x3))+((one.y1-one.y3)*(one.y1-one.y3)));
	if (a==1){
		angle=(180/3.14)*(acos((pow(c,2)+pow(a,2)-pow(b,2))/(2*c*a)));
	} else if (a==2) {
		angle=(180/3.14)*(acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b)));
	} else if (a==3){
		angle=(180/3.14)*(acos((pow(b,2)+pow(c,2)-pow(a,2))/(2*b*c)));
	} else {
		printf("Invalid selection pick point 1, 2 or 3.");
		angle=0;
	}
	return angle;
}

//return triangle to orginal one
void original(){
	one.x1=0;
    one.y1=0;
    one.x2=0;
    one.y2=4;
    one.x3=3;
    one.y3=0;
}

//reflects over a vertical line
void yreflect(int x){
	one.x1=abs(2*(one.x1-x));
	one.x2=abs(2*(one.x2-x));
	one.x3=abs(2*(one.x3-x));
}

//reflects over a horizontal line
void xreflect(int y){
	one.y1=abs(2*(one.y1-y));
	one.y2=abs(2*(one.y2-y));
	one.y3=abs(2*(one.y3-y));
}

//translats the triangle up and down and left and right
void translate(int x, int y){
	one.x1+=x;
    one.y1+=y;
    one.x2+=x;
    one.y2+=y;
    one.x3+=x;
    one.y3+=y;
	printf("The new triangle coordinates are:\n	p1=(%d,%d) p2=(%d,%d) p3=(%d,%d)",one.x1,one.y1,one.x2,one.y2,one.x3,one.y3);
}

//calculates area of triangle
double areacalc(){
    double base = abs(sqrt(((one.x1-one.x2)*(one.x1-one.x2))+((one.y1-one.y2)*(one.y1-one.y2))));
    double m1 = ((one.y1-one.y2)/(one.x1-one.x2));
    double b1 = one.y1-m1 * one.x1;
	double height;
	//this if else statement fixes the issue of making an equation of the line (y=mx+b) when m is zero or infinite
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
