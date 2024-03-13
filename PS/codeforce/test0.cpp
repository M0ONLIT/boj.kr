#include <stdio.h>
typedef struct str{
    int x;
    int y;
}str;
int main() {
   str a;
   str b;
   str c;
   int res;
   scanf("%d %d", &a.x, &a.y);
   scanf("%d %d", &b.x, &b.y);
   scanf("%d %d", &c.x, &c.y);
   if((b.x - a.x) * (c.y - a.y) > (b.y - a.y) * (c.x - a.x))
   res = 1;
   else if((b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x))
   res = 0;
   else if((b.x - a.x) * (c.y - a.y) < (b.y - a.y) * (c.x - a.x))
   res = -1;
   printf("%d", res);
   return 0;
}
