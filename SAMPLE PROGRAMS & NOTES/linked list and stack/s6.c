// array of structures as function arguements
# include <stdio.h>
struct student
{
char name[20];  
int rno,marks[5], tot; 
 float average;  
};
void display(struct student[],int);//void display(int[],int)
main()
{
	int n,i;
	struct student st[5];//array of structures
	printf("enter number of students \n");
	scanf("%d", &n);//size
	for (i=0;i<n;i++)//read and calculate
	{
		printf("enter name\n");
		scanf("%s", &st[i].name);
		printf("enter roll number\n");
		scanf("%d", &st[i].rno);
		printf("enter subject 1 marks");
		scanf("%d", &st[i].marks[0]);
		printf("enter subject 2 marks");
		scanf("%d", &st[i].marks[1]);
		printf("enter subject 3 marks");
		scanf("%d", &st[i].marks[2]);
		st[i].tot=st[i].marks[0]+st[i].marks[1]+st[i].marks[2];
		st[i].average=st[i].tot/3.0;
}
	display(st,n);//function called
}

void display(struct student s[],int n)
{ int i;
	for(i=0;i<n;i++)
	{
		printf("\n\nENTERED DETAILS\n");
		printf("name %s \n", s[i].name);
		printf("roll number %d\n", s[i].rno);
		printf("subject 1 marks %d\n", s[i].marks[0]);
		printf("subject 2 marks %d\n", s[i].marks[1]);
		printf("subject 3 marks %d\n", s[i].marks[2]);
		printf("total   %d\n", s[i].tot);
		printf("average  %f\n", s[i].average);
	}
}
