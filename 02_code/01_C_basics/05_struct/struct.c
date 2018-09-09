#include <stdio.h>
#include <stdlib.h>


struct student {
	char name[20];
	int age;
	int score;
};
typedef struct student STD;


struct HUMAN {
    char name[20];
    int money;
    struct HUMAN* lover;
};

int main() {

	struct student s1 = {"Hong", 23, 99};
	struct student s2 = {"Park", 22, 39};
	struct student s3 = {"Kim", 21, 69};
	STD 	       s4 = {"Lee", 24, 79};

	printf("Student Name: %s\n", s1.name);
	printf(" --> age  : %d\n", s1.age);
	printf(" --> score: %d\n", s1.score);

	STD* std_p;
	std_p = &s4;
 
	printf("Student Name: %s\n", std_p->name);
	printf(" --> age  : %d\n", std_p->age);
	printf(" --> score: %d\n", std_p->score);


    struct HUMAN man1 = {"Daejin", 100, NULL};
    struct HUMAN girl1 = {"Jain", 10000, NULL};

    man1.lover = &girl1;

    printf("%s has money %d\n", man1.name, man1.money);
    printf("%s's girlfriend is %s\n", man1.name, (*(man1.lover)).name);
    printf("%s's girlfriend is %s\n", man1.name,    man1.lover->name);

    printf("She has money %d\n", man1.lover->money);






}
