#include <stdio.h>
#include <stdlib.h>

double* convertTemperature(double celsius, int* returnSize) {
    double* ans = (double*)malloc(2 * sizeof(double));
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.80 + 32.0;
    return ans;
}

int main() {
    double celsius = 122.11;
    int returnSize;
    double* temperature = convertTemperature(celsius, &returnSize);
    printf("Temperature is: %fK\n", temperature[0]);
    printf("Temperature is: %fF\n", temperature[1]);
    free(temperature);
    return 0;
}