/*Point Translator*/

#include <stdio.h>

struct point{
    int x;
    int y;
};

void translate(int *j, int *k, int xn, int yn);

int main() {
    struct point a;
    a.x=2;
    a.y=2;
    translate(&a.x, &a.y, 3, 1);
    printf("(%d,%d)", a.x, a.y);
	return 0;
}

void translate(int *j, int *k, int xn, int yn){
    *j+=xn;
    *k+=yn;
}
