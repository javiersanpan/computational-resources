#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main(){
    int n;

    do {
    char c;
    read(STDIN_FILENO,&c,1);

    char may = toupper(c);
    write(STDOUT_FILENO,&may,1);

    } while(n =! 0);

    return 0;

}