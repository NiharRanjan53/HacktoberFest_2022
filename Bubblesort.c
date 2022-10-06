#include <stdio.h>
int main()
{
  int a[100],i,n,j,k,temp,l;
  printf("Enter the size of array \n");
  scanf("%d",&n);
  printf("Enter the elements \n");
  for(i=0;i<n;i++)
     {
	scanf("%d",&a[i]);     
     }
  
  for (j=1;j<n;j++)
     {
       for(k=0;k<n-j;k++)
          { if (a[k]>a[k+1])
            {
	      temp=a[k];
	      a[k]=a[k+1];
	      a[k+1]=temp;
            }
          }
     }
  
  printf("Sorted array is:\n");
  for(l=0;l<n;l++)
     { printf("%d\n",a[l]);  
      }
  return 0;
}
