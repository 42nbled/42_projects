#include <stdio.h>
#include <stdlib.h>

#define STR "#include <stdio.h>%3$c#include <stdlib.h>%3$c%3$c#define STR %4$c%1$s%4$c%3$c%3$cint main() {%3$c%2$cint%2$ci = %5$d;%3$c%2$cchar%2$cfilename[12];%3$c%2$csprintf(filename, %4$cSully_%%1$d.cpp%4$c, i - 1);%3$c%2$cFILE%2$c*kid = fopen(filename, %4$cw%4$c);%3$c%2$cif (kid) {%3$c%2$c%2$cfprintf(kid, STR, STR, 9, 10, 34, i - 1);%3$c%2$c%2$cfclose(kid);%3$c%2$c%2$cif (i > 0) {%3$c%2$c%2$c%2$cchar%2$ccmd[62];%3$c%2$c%2$c%2$csprintf(cmd, %4$cclang -Wall -Wextra -Werror -o Sully_%%1$d Sully_%%1$d.cpp; ./Sully_%%1$d%4$c, i - 1);%3$c%2$c%2$c%2$csystem(cmd);%3$c%2$c%2$c}%3$c%2$c}%3$c%2$creturn (0);%3$c}%3$c"

int main() {
	int	i = 5;
	char	filename[12];
	sprintf(filename, "Sully_%1$d.cpp", i - 1);
	FILE	*kid = fopen(filename, "w");
	if (kid) {
		fprintf(kid, STR, STR, 9, 10, 34, i - 1);
		fclose(kid);
		if (i > 0) {
			char	cmd[62];
			sprintf(cmd, "clang -Wall -Wextra -Werror -o Sully_%1$d Sully_%1$d.cpp; ./Sully_%1$d", i - 1);
			system(cmd);
		}
	}
	return (0);
}
