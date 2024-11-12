#include <stdio.h>

/*
	Hello World !
*/

void	dr_quine(char *str, char tab, char nl, char dq) {
	printf(str, str, tab, nl, dq);
}

int	main () {
	char	*str = "#include <stdio.h>%3$c%3$c/*%3$c%2$cHello World !%3$c*/%3$c%3$cvoid%2$cdr_quine(char *str, char tab, char nl, char dq) {%3$c%2$cprintf(str, str, tab, nl, dq);%3$c}%3$c%3$cint%2$cmain () {%3$c%2$cchar%2$c*str = %4$c%1$s%4$c;%3$c%2$c/*%3$c%2$c%2$ctab = 9, new_line = 10, double_quote = 34%3$c%2$c*/%3$c%2$cdr_quine(str, 9, 10, 34);%3$c%2$creturn (0);%3$c}%3$c";
	/*
		tab = 9, new_line = 10, double_quote = 34
	*/
	dr_quine(str, 9, 10, 34);
	return (0);
}
