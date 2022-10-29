#include <stdio.h>
#include <stdlib.h>
int Bubble(int *a, int n);
void quick_sort(int*a, int first, int last);

int main()
{
    int a,i = 0;
    FILE *f;
    int flag =1;
    char name[25];
//    system("chcp 1251");
    printf("Enter file name: ");
    scanf("%s",name);
    if((f=fopen(name,"r"))==NULL)
    {
        printf("File not found. ");
//        system("PAUSE");
        return 0;
    }
    int *x = NULL;

    while(!feof(f))
    {
        if (fscanf(f, "%d", &a)!=1) break;
        i++;
        x = (int*) realloc(x, sizeof(int)*i);
        x[i-1] = a;
    }
    fclose(f);
    int n = i;
    printf("get Array: ");
  //  for (i=0; i<n; i++)
  //      printf("%3d", x[i]);
    printf("\n");
//    system("PAUSE");

 //   Bubble(x,n);
   // int a1[10] = {6,7,2,6,5,9,2,1,0,-8};
    quick_sort(x,0,n);

    printf("Min element: %d\n", x[n]);
    printf("Max element: %d\n", x[0]);
    printf("Element a[0] %d\n", x[0]);
    printf("Element a[1] %d\n", x[1]);
    printf("Element a[2] %d\n", x[2]);
    printf("Element a[3] %d\n", x[3]);
    printf("Element a[4] %d\n", x[4]);
    free(x);
//    system("PAUSE");

    return 0;

}

int Bubble(int *a, int n)
{
    int i,j,x;
    for (i=0; i<n; i++)
    for (j=n-1; j>i; j--)
        if (a[j-1]>a[j])
    {
        x=a[j-1]; a[j-1] = a[j]; a[j]=x;
    }
}

void quick_sort(int* a, int first, int last)
{
    int tmp, i=first,j=last, x = a[first+(last-first)/2];
  //  x=0;

    do {
        while (a[i]>x) i++;
        while (a[j]<x) j--;

        if(i<=j) {
            if(a[i]<a[j])
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
            i++;
            j--;
        }
    } while(i<=j);
    if (i<last) quick_sort(a,i,last);
    if(first<j) quick_sort(a,first,j);
}
