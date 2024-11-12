#include <stdio.h>
#include <stdlib.h>

#define Grace int main() {FILE *kid = fopen("Grace_kid.c", "w"); if (kid) {fprintf(kid, STR, STR, 10, 34);fclose(kid);}return (0);}
#define STR "#include <stdio.h>%2$c#include <stdlib.h>%2$c%2$c#define Grace int main() {FILE *kid = fopen(%3$cGrace_kid.c%3$c, %3$cw%3$c); if (kid) {fprintf(kid, STR, STR, 10, 34);fclose(kid);}return (0);}%2$c#define STR %3$c%1$s%3$c%2$c%2$c/*%2$c    Hello World !%2$c*/%2$c%2$cGrace%2$c"

/*
    Hello World !
*/

Grace
