#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int countLabel(char *txt)
{
    FILE *fp = fopen(txt, "r");
    int count = 0;
    char ch;
    bool b = false;
    while (fscanf(fp, "%c", &ch) == 1) {
        if (ch == '<')
            b = true;
        else if (b && ch == '>') {
            b = false;
            count++;
        }
    }
    fclose(fp);
    return count;
}
