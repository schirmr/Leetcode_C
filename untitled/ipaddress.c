#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * defangIPaddr(char * address) {
    int tam = strlen(address);
    int i, j;
    char *newAddress = (char *)malloc(sizeof(char) * (tam*2+1));
    for (i=0, j=0; i<tam; i++, j++) {
        if (address[i] == '.') {
            newAddress[j] = '[';
            newAddress[j+1] = '.';
            newAddress[j+2] = ']';
            j+=2;
        }
        else newAddress[j] = address[i];
    }
    newAddress[j] = '\0';
    return newAddress;
}

int main(void){
    char *result = defangIPaddr("1.1.1.1");
    printf("%s\n", result);
    free(result);
    return 0;
}