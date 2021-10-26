#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char *fmtname(char *path);
void find(char *path);

static char tarfile[10];
int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(2, "usage: find dir file\n");
        exit(1);
    }

    strcpy(tarfile, argv[2]);

    find(argv[1]);
    exit(0);
}

char *fmtname(char *path)
{
    static char buf[DIRSIZ + 1];
    char *p;

    for (p = path + strlen(path); p >= path && *p != '/'; p--)
    ;
    p++;

    if (strlen(p) >= DIRSIZ)
        return p;
    memmove(buf, p, strlen(p));
    // debug 1h: don't add null-terminal char
    *(buf + strlen(p)) = 0;
    return buf;

}

void find(char *path)
{
    char buf[100], *p;
    int fd;
    struct dirent de;
    struct stat st;

    if ((fd = open(path, 0)) < 0) {
        fprintf(2, "cannot open %s\n", path);
        return;
    }

    if (fstat(fd, &st) < 0) {
        fprintf(2, "cannot stat %s\n", path);
        close(fd);
        return;
    }

    switch (st.type) {
        case T_FILE:
            char *filename = fmtname(path);
            if (strcmp(filename, tarfile) == 0)
                printf("%s\n", path);
            break;

        case T_DIR:
            // precheck: buf size >= len(path) + 1('/') + DIRSIZ + 1('\0')
            if (strlen(path) + 1 + DIRSIZ + 1 > sizeof buf) {
                fprintf(2, "path too long\n");
                // break not return: close(fd)
                break;
            }

            strcpy(buf, path);
            p = buf + strlen(buf);
            *p++ = '/';
            while (read(fd, &de, sizeof(de)) > 0) {
                if (de.inum == 0)
                    continue;
                if (strcmp(de.name, ".") == 0 ||
                    strcmp(de.name, "..") == 0)
                    continue;

                memmove(p, de.name, DIRSIZ);
                p[DIRSIZ] = 0;
                if (stat(buf, &st) < 0) {
                    fprintf(2, "cannot stat %s\n", buf);
                    continue;
                }
                find(buf);
            }
            break;
    }
    // debug 2h: forget close fd source, causing cannot open file more
    close(fd);
}
