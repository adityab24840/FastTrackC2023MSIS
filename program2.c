//WAP to find area of circle

#include<stdio.h>
#include<math.h>

int main()
{
  float radius,area;
  printf("enter radius of the circle");
  scanf("%f",&radius);
  area=M_PI*radius*radius;
  printf("Area of the circle is: %0.3f\n",area);
  return 0;
}
