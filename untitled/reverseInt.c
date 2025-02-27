#include <stdio.h>
#include <limits.h>

int reverse(int x) {
  int invertido = 0;
  while (x != 0) {
    int digito = x % 10;
    if (invertido > INT_MAX / 10 || (invertido == INT_MAX / 10 && digito > 7)) return 0;
    if (invertido < INT_MIN / 10 || (invertido == INT_MIN / 10 && digito < -8)) return 0;
    invertido = invertido * 10 + digito;
    x /= 10;
  }
  return invertido;
}

int main(){
  printf("%d\n", reverse(-321));
  return 0;
}