//WAP that converts upper case to lower case
//logic: convert itt based on ascii

#include<stdio.h>

int main()
{
  char string[26];
  printf("Enter the string to convert it to Lower case: \n \n");
  scanf("%s",&string);
  for(int i=0; i <= strlen(string);i++)
  {
  	if(string[i]>=65 && string[i]<=90)
  	{
  		string[i]=string[i]+32;
  	}
  }
  printf("The result is : \n \n%s",string);
  return 0;
  clrscr();
}
