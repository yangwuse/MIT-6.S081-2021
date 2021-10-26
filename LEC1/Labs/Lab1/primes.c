#include "kernel/types.h"
#include "user/user.h"

void f(int *arr, int len);

int main() 
{
    int p[2];
    int pid;

    pipe(p);
    pid = fork();
    if (pid == 0) {
        close(p[1]);

        int n, m, i;
        int arr[30];

        if (read(p[0], &n, sizeof(n)) > 0)
            printf("prime %d\n", n);
        else 
            exit(0);

        i = 0;
        while (read(p[0], &m, sizeof(m)) > 0) {
            if (m % n != 0)
               arr[i++] = m; 
        }
        close(p[0]);

        f(arr, i);
        exit(0);
    } else {
        close(p[0]);
        for (int i = 2; i < 36; i++)
          write(p[1], &i, sizeof(i));
        close(p[1]);
        wait((int *) 0);
    }
    exit(0);
}

void f(int *arr, int len) 
{
    if (len == 0)
        exit(0);

    int p[2];
    int pid;

    pipe(p);
    pid = fork();
    if (pid == 0) {
        close(p[1]);

        int n, m, i;
        int arr[30];

        read(p[0], &n, sizeof(n));
        printf("prime %d\n", n);

        i = 0;
        while (read(p[0], &m, sizeof(m)) > 0) {
            if (m % n != 0)
                arr[i++] = m;
        }
        close(p[0]);

        f(arr, i);

        exit(0);
    } else {
        close(p[0]);
        for (int i = 0; i < len; i++)
            write(p[1], arr+i, sizeof(*(arr+i)));
        close(p[1]);
        wait((int *) 0);
    }
    exit(0);
}

