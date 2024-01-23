// structure as function arguements
# include <stdio.h>
struct student
{
char name[20];  
int rno,marks[5], tot; 
 float average;  
};
void display(struct student);//fn prototype or function declaration//void display(int)
	//struct student st;

main()
{

	struct student st;
	printf("enter name\n");
	scanf("%s", &st.name);
	printf("enter roll number\n");
	scanf("%d", &st.rno);
	printf("enter subject 1 marks");
	scanf("%d", &st.marks[0]);
	printf("enter subject 2 marks");
	scanf("%d", &st.marks[1]);
	printf("enter subject 3 marks");
	scanf("%d", &st.marks[2]);
	st.tot=st.marks[0]+st.marks[1]+st.marks[2];
	st.average=st.tot/3.0;
	display(st);//function call
}
void display(struct student s)//function definition
{
	printf("\n\nENTERED DETAILS\n");
	printf("name %s \n", s.name);
	printf("roll number %d\n", s.rno);
	printf("subject 1 marks %d\n", s.marks[0]);
	printf("subject 2 marks %d\n", s.marks[1]);
	printf("subject 3 marks %d\n", s.marks[2]);
	printf("total   %d\n", s.tot);
	printf("average  %f\n", s.average);
}
