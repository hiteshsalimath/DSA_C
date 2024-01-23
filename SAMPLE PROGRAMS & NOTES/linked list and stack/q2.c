#include <stdio.h>
void display(int, int , int (*)[]);//2d array pointer
void read(int, int , int (*)[] );
main()
{
	system("color 0A");
	printf("\n****************************************************************************************************************");

	printf("\n\t\t\tC program of matrix using functions and pointers for the following");
	printf("\n****************************************************************************************************************");
	int a[100][100],n,m;
	printf("\nEnter the number of ROWS AND COLOUMNS:");
	scanf("%d%d",&n,&m);

	read(n,m,a);//fn call
	display(n,m,a);//fn call

}
void read(int n, int m, int (*arr)[m])//1 d array of pointers
{
	int i,j;
	printf("Enter %d elements:",n*m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
		printf("\n");
		scanf("%d",(*(arr+i)+j));//address//& is not required 
		}
	}
}
void display(int n, int m, int (*arr)[m])
{
	int i,j;
	printf("\n%d elements are:\n",n*m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
}

