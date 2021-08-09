#include <cstdio>
using namespace std;

struct student {
    char name[24];
    char sex[24];
    int age;
    int grade;
};

int main() {
    int n;
    scanf("%d", &n);
    student stu[1000];
    for (int i = 0; i < n; i++)
        scanf("%s %s %d %d", stu[i].name, stu[i].sex, &stu[i].age, &stu[i].grade);
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (stu[j-1].grade > stu[j].grade) {
                student t = stu[j-1];
                stu[j-1] = stu[j];
                stu[j] = t;
            }
    for (int i = 0; i < n; i++)
        printf("%s %s %d %d\n", stu[i].name, stu[i].sex, stu[i].age, stu[i].grade);
    return 0;
}
