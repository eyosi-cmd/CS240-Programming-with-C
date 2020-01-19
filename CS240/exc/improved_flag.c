/* Eyosias Kibe*/
#include <stdio.h>

unsigned char bitPos[8];
int main(void)
{
int i; 
char state = '\x1F'; /* 0010 1100 */
bitPos[0] = '\xA5';
for (i = 1; i < 8; i++)
bitPos[i] = bitPos[i - 1] << 1;
for (i = 0; i < 8; i++)
if (state & bitPos[i])
printf("Flag %d is set\n", i + 1);
return 0;
}