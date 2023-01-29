#include <stdio.h>
int main()
{
int startYear, endYear, i;
  printf("Print leap years between two given years \n");//print a string about the program
  printf("Enter Start year: ");//get the start year from user
  scanf("%d", &startYear);

  printf("Enter End year: ");//get the end year from user
  scanf("%d", &endYear);
  printf("Leap years:\n");//loop through between the start and end year

for(i=startYear; i <= endYear; i++){//check if the (i) year is a Leap year if yes print
   if( (0 == i % 4) && (0 != i % 100) || (0 == i % 400) ){
   printf("%d\n", i);
   }
  }
 return 0;
}
