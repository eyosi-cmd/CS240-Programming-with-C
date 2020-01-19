/* Eyosias Kibe */

#include <stdio.h>
#define MAXLINE 1024
#define MINLINE 5
//maximum input length
//minium imput length
//function declarations
int get_line(char line[], int maxline);
int main(void) {
int len;
char line[MAXLINE];
char copyMax[MAXLINE];
//print the longest input line
//current line length
//maximum length seen so far
//current input
//longest line
int j = 0;
while ((len = get_line(line, MAXLINE)) > 0)
if (len > MINLINE) {
	int i;
	i = 0;
	while (line[i] != '\0'){
		copyMax[j] = line[i];
		i++;
		j++;
	}
	
}
printf("%s", copyMax);

return 0;
}

//getline: read a line into s, return length
int get_line(char s[], int lim) {
int c, i;
for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
s[i] = c;
if (c == '\n') {
s[i] = c;
i++;
}
s[i] = '\0';
return i;
}
