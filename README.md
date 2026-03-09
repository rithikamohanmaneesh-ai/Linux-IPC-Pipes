# Linux-IPC--Pipes
Linux-IPC-Pipes


# Ex03-Linux IPC - Pipes

# AIM:
To write a C program that illustrate communication between two process using unnamed and named pipes

# DESIGN STEPS:

### Step 1:

Navigate to any Linux environment installed on the system or installed inside a virtual environment like virtual box/vmware or online linux JSLinux (https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192) or docker.

### Step 2:

Write the C Program using Linux Process API - pipe(), fifo()

### Step 3:

Testing the C Program for the desired output. 

# PROGRAM:

## C Program that illustrate communication between two process using unnamed pipes using Linux API system calls


#include <stdio.h> #include <stdlib.h> #include <sys/types.h> #include <sys/stat.h> #include <string.h> #include <fcntl.h> #include <unistd.h> #include <sys/wait.h>

void server(int rfd, int wfd); void client(int wfd, int rfd);

int main() { int p1[2], p2[2]; int pid, status;

pipe(p1);   // pipe1: client → server
pipe(p2);   // pipe2: server → client

pid = fork();

if (pid == 0)   // Child process → server
{
    close(p1[1]);
    close(p2[0]);
    server(p1[0], p2[1]);
    return 0;
}
else           // Parent process → client
{
    close(p1[0]);
    close(p2[1]);
    client(p1[1], p2[0]);
    wait(&status);
    return 0;
}
}


## OUTPUT

<img width="397" height="326" alt="image" src="https://github.com/user-attachments/assets/bb9db153-eeb4-4868-8b4b-14984c3afb31" />

## C Program that illustrate communication between two process using named pipes using Linux API system calls
void client(int wfd, int rfd) { int n; char fname[2000]; char buff[2000];

printf("ENTER THE FILE NAME : ");
scanf("%s", fname);

printf("CLIENT SENDING THE REQUEST ...\nPLEASE WAIT\n");
sleep(10);

write(wfd, fname, 2000);

n = read(rfd, buff, 2000);
buff[n] = '\0';

printf("THE RESULTS OF CLIENTS ARE .....\n");
write(1, buff, n);
}

void server(int rfd, int wfd) { int n, fd; char fname[2000]; char buff[2000];

n = read(rfd, fname, 2000);
fname[n] = '\0';

fd = open(fname, O_RDONLY);
sleep(10);

if (fd < 0)
{
    write(wfd, "can't open", 9);
}
else
{
    n = read(fd, buff, 2000);
    write(wfd, buff, n);
}
}





## OUTPUT
<img width="302" height="351" alt="image" src="https://github.com/user-attachments/assets/81c7a6ed-338d-4016-8306-8b6f69400e46" />

<img width="212" height="336" alt="image" src="https://github.com/user-attachments/assets/90fe41ca-fa39-4a5c-a709-7a330e7cd350" />


# RESULT:
The program is executed successfully.
