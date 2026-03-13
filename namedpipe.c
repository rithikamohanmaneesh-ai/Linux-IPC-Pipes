#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    mkfifo("mypipe", 0666);
    printf("Named pipe created\n");
    return 0;
}
