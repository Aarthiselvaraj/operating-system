#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char filename[100], buffer[100];
    int fd, sz, fd1;

    printf("Enter the name of the file to create: ");
    scanf("%s", filename);

    fd = open(filename, O_WRONLY | O_CREAT, 0644); // create file with write permission
    if(fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Enter data to write to the file: ");
    scanf(" %[^\n]", buffer);

    sz = write(fd, buffer, strlen(buffer));
    if(sz == -1)
    {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
    close(fd);

    fd1 = open(filename, O_RDONLY); // open file with read permission
    if(fd1 == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("\nData in the file: \n");
    while((sz = read(fd1, buffer, sizeof(buffer))) > 0)
    {
        write(STDOUT_FILENO, buffer, sz); // print to console
    }
    close(fd1);

    return 0;
}
