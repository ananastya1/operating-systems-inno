#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
  float x;
  float y;
} Point;

float distance(Point A, Point B){
	float result;
	result = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
	return result;
}

float area(Point A, Point B, Point C){
	float res;	
	res = 0.5 * fabsf(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
	return res;
}

int main(void){

	Point A = {2.5, 6};
  Point B = {1, 2.2};
  Point C = {10, 6};
		

	float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);

	return EXIT_SUCCESS;
}