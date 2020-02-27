#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[80];
    double einkommen;
    double steuer;

    printf("UE05 Einkommensteuer\n");
    printf("-----------------------\n");


    printf("Verfuegbares Einkommen:\n");
    fgets(s, 80, stdin);
    sscanf(s, "%lf", &einkommen);


    if (einkommen < 0) {
        printf("Eingabefehler\n");
        return 1;
    }

    if (einkommen >= 1E6) {
        steuer = (einkommen - 1E6) * 0.55;
        steuer = steuer + 10000 * 0.5;
        steuer = steuer + 30000 * 0.48;
        steuer = steuer + 29000 * 0.42;

        printf("Steuer = %.2lf", steuer);

    } else if (einkommen >= 90000) {
        steuer = steuer + 30000 * 0.48;
        steuer = steuer + 29000 * 0.42;

        printf("Steuer = %.2lf", steuer);

    } else if (einkommen >= 60000) {
        steuer = steuer + 29000 * 0.42;

        printf("Steuer = %.2lf", steuer);

    } else if (einkommen >= 31000) {
        steuer = steuer + 31000 * 0.42;

        printf("Steuer = %.2lf", steuer);

    } else {
        steuer = 0;
        printf("Steuer = %.2lf", steuer);
    }

    return 0;
}








