    #include<stdio.h>
    int main() {
        int decimalNumber,remainder,quotient;
        int i=1,j,temp;
        char hexadecimalNumber[100];
        printf("Enter any decimal number: ");
        scanf("%d",&decimalNumber);
        quotient = decimalNumber;
        while(quotient!=0) {
            temp = quotient % 4;
            //To convert integer into character
            if( temp < 10)
                       temp =temp + 48; 
            else
                     temp = temp + 55;
            hexadecimalNumber[i++]= temp;
            quotient = quotient / 4;
        }
        printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
        for (j = i -1 ;j> 0;j--)
              printf("%c",hexadecimalNumber[j]);
          printf("\n");
        return 0;
    }