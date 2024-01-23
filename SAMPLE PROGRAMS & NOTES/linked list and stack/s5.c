// struct as return value
# include <stdio.h>
struct student
{
char name[20];  
int rno,marks[5], tot; 
 float average;  
};
struct student cal (struct student);///observe....//int sum(int,int)//new//
void display(struct student);
main()
{

	struct student st,s1;
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
	s1=cal(st);//function call
	display(s1);//function call
}

struct student cal ( struct student s)
{
	s.tot=s.marks[0]+s.marks[1]+s.marks[2];
	s.average=s.tot/3.0;
	return s;// return
}

void display(struct student s)
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


