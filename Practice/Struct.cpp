#include <stdio.h>

struct student_s {
	int sid;
	char sname[20];
	float score;
};

typedef struct student_t {
	int sid;
	char sname[20];
	float score;
}student_t;

void main() {
	struct student_s stu1 = { 01, "Koishi", 51.4 };
	printf("stu1.sid   = %d \nstu1.sname = %s \nstu1.score = %.1f\n", 
		stu1.sid, stu1.sname, stu1.score);

	student_t stu2 = { 02, "Satori", 55.5 };
	printf("\nstu2.sid   = %d \nstu2.sname = %s \nstu2.score = %.1f\n",
		stu2.sid, stu2.sname, stu2.score);

	student_t* pstu = (student_t*) &stu1;
	printf("\npstu->sid   = %d \npstu->sname = %s \npstu->score = %.1f\n",
		pstu->sid, pstu->sname, pstu->score);
}