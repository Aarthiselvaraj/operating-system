#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

typedef struct {
    char name[50];
    char files[MAX_FILES][50];
    int num_files;
} UserDirectory;

UserDirectory users[MAX_USERS];

int main() {
	int i,j;
    
    for (i = 0; i < MAX_USERS; i++) {
        sprintf(users[i].name, "user%d", i + 1);
        users[i].num_files = 0;
    }

    
    strcpy(users[0].files[0], "file1.txt");
    strcpy(users[0].files[1], "file2.txt");
    strcpy(users[0].files[2], "file3.txt");
    users[0].num_files = 3;

    strcpy(users[1].files[0], "file4.txt");
    strcpy(users[1].files[1], "file5.txt");
    users[1].num_files = 2;

    strcpy(users[2].files[0], "file6.txt");
    strcpy(users[2].files[1], "file7.txt");
    users[2].num_files = 2;
    for (i = 0; i < MAX_USERS; i++) {
        printf("%s:\n", users[i].name);
        for (j = 0; j < users[i].num_files; j++) {
            printf("\t%s\n", users[i].files[j]);
        }
    }

    return 0;
}
