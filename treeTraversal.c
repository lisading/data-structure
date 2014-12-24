#include <stdio.h>
#include <string.h>

void post(char *pre, char *in, float n)
{
    int i;
    
    if (n < 1)
        return;
    
    if (n == 1) {
        putchar(pre[0]);
        return;
    }
    
    for (i = 0; i < n; i++)
        if (in[i] == pre[0]) break;
    
    post(pre + 1, in, i);
    post(pre + 1 + i, in + i + 1, n - i - 1);
    
    putchar(pre[0]);
}

int main()
{
    static char pre[256], in[256];
    
    while (scanf(" %s %s", pre, in) == 2) {
        post(pre, in, strlen(pre));
        putchar('\n');
    }
    
    return 0;
}
