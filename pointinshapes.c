/*Point in a Shape*/

/*Determines if a given point lies in a given polygon*/

/*1=true and 0=false*/

#include <stdio.h>

//struct for polygon
struct polygon{
	int points[3][2];
};

//struct for the point
struct point{
	int coord[2];
};

//global structs
struct polygon shape;
struct point p;

//function to determine if horizontal line at point p interesects with any sides of the polygon
int dointersect(int py, int sy1, int sy2);

int main() {
	//creating the specific point
	p.coord[1]=0;
	p.coord[2]=1;
	//creating the specific polygon
	shape.points[1][1]=0;
	shape.points[1][2]=0;
	shape.points[2][1]=3;
	shape.points[2][2]=0;
	shape.points[3][1]=3;
	shape.points[3][2]=4;
	
	//counting the intersectings
	int i;
	int intersects=0;
	for (i=1;i<=3;i++){
		if (i==3){
			intersects+=dointersect(p.coord[2], shape.points[i][2], shape.points[1][2]);
			
		} else {
			intersects+=dointersect(p.coord[2], shape.points[i][2], shape.points[i+1][2]);
		}
	}
	//if there is an even amount of intersects the point is outside
	if (intersects%2==0){
		printf("The point p lies outside of the polygon");
	//else the number is odd and the point in inside the polygon
	} else {
		printf("The point p lies inside of the polygon");
	}
	
	return 0;
}


//function to check intersection (not including points on the line)
int dointersect(int py, int sy1, int sy2){
	int b;
	if (sy1<sy2){
		int y1=sy1;
		int y2=sy2;
	} else {
		int y1=sy2;
		int y2=sy1;
	}
	if (py>y1 && py<y2){
		b=1;
	} else {
		b=0;
	}
	return b;
}
