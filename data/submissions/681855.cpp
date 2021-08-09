#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
    char filename[32];
    int filetype;
    char fileinfo[32];
} node[1024];
int top = -1;

int main()
{
    char buffer[256];
    while (1) {
        gets(buffer);
        if (*buffer == 'e')
            break;
        else if (*buffer == 'c') {
            top++;
            int i = 0;
            while (buffer[i] != ' ')
                i++;
            while (buffer[i] == ' ')
                i++;
            int j = 0;
            while (buffer[i] != ' ')
                node[top].filename[j++] = buffer[i++];
            node[top].filename[j++] = 0;
            while (buffer[i] == ' ')
                i++;
            node[top].filetype = buffer[i++] - '0';
            while (buffer[i] == ' ')
                i++;
            j = 0;
            while (buffer[i] != ' ' && buffer[i] != '\0')
                node[top].fileinfo[j++] = buffer[i++];
        } else if (*buffer == 'o') {
            int i = 0;
            while (buffer[i] != ' ')
                i++;
            while (buffer[i] == ' ')
                i++;
            char name[32];
            int j = 0;
            while (buffer[i] != ' ' && buffer[i] != '\0')
                name[j++] = buffer[i++];
            name[j++] = '\0';
            int type = 1;
            while (type == 1) {
                for (int i = top; i >= 0; i--) {
                    if (strcmp(name, node[i].filename) == 0) {
                        type = node[i].filetype;
                        strcpy(name, node[i].fileinfo);
                        break;
                    }
                }
            }
            printf("%s\n", name);
        }
    }
    return 0;
}
