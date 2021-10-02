//1.10 外變數與有效範圍 External Variables and Scope
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */
int getline(void);
void copy(void);

/* print longest input line; specialized version */
int main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getline()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline: specialized version */
int getline(void)
{
    int c, i;
    extern char line[]; // 這裡使用到外在變數, 必須用 extern "宣告"

    for (i = 0; i < MAXLINE - 1 && (c=getchar)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */
void copy(void)
{
    int i;
    extern char line[], longest[]; // // 這裡使用到外在變數, 必須用 extern "宣告"
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
    }
}
