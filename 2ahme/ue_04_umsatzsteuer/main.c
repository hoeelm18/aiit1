#include <stdio.h>

int main()
{
  char s[100];  // [] vervielfacht
  double gezahlt;

  printf("UE04 Rechner fuer Umsatzsteuer\n");
  printf("---------------------------\n\n");

  printf(" Gezahlt wurde: ");
  fgets(s, 100, stdin);
  sscanf(s, "%lf", &gezahlt);

  if (gezahlt > 0) {
    double steuer = gezahlt / 1.2 * 0.2; //20 % Steuer
    printf(" Steuer = %.2f\n", steuer);

  } else {
    printf(" Fehlerhafte Eingebe\n");

}

   return 0;

}
