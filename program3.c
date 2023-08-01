//wap to convert C to F

#include<stdio.h>
#include<stdlib.h>

float function(float c);

int main()
{
  float temperature;
  printf("Enter temperature in C:");
  scanf("%f",&temperature);
  
  printf("%f",function(temperature));
  return 0;
}

float function(float c)
{
  float c2f=c*1.8+32;
  return c2f;
}


