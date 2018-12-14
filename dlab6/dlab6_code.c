#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool permutation(int array[], int length) 
{
  if (length == 0)
  {
    return false;
  }
  //while increasing
  int i = length - 1;
  while (i > 0 && array[i - 1] >= array[i])
  {
    i--;
  }
  
  if (i == 0)
  {
    return false;
  }
  
  //find higher
  int j = length - 1;

  while (array[j] <= array[i - 1])
  {
    j--;
  }
  //swap
  int temp = array[i - 1];
  array[i - 1] = array[j];
  array[j] = temp;
  
  //reverse
  j = length - 1;
  while (i < j) {
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    i++;
    j--;
  }
  return true;
}

int factorial(int a )
{
  int res;
  if (a == 0) 
  {
      return 1; 
  }
  return a*factorial(a-1); 
}

void newton(int x, int y, int n) 
{      
    //n! 
    int nFact = factorial(n); 
  
   
    for (int i = 0; i < n + 1; i++) { 
          
        
        int niFact = factorial(n - i); 
        int iFact = factorial(i); 
        
        int aPow = pow(x, n - i); 
        int xPow = pow(y, i); 
  

       printf("%d ", (nFact * aPow * xPow) /(niFact * iFact)); 
    } 
} 

int main(void)
{
  int array[55], length;

  printf("Enter the length of the array: ");
  scanf("%d", &length);

  printf("Enter elements:\n");

  for(int i = 0; i < length; i++)
  {
    scanf("%d", &array[i]);
  }
  //1
  do
  {
    printf("[ ");
    for (int i = 0; i < length; i++)
    {
      printf("%d ", array[i]);
    }
    printf("]\n");

  } while(permutation(array, length) == true);
  //2
  int n = 5;
  int x ,y;

  printf("Enter values:\n");
  printf("x:");
  scanf("%d", &x);
  printf("y: ");
  scanf("%d", &y);
 
  printf("Binominal: ");
  newton(x, y, n);
}