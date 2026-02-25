#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparaCuvinte(const void* a, const void* b) {
    const char* cuvantA = *(const char**)a;
    const char* cuvantB = *(const char**)b;

    int lungimeA = (int)strlen(cuvantA);
    int lungimeB = (int)strlen(cuvantB);

    if (lungimeA != lungimeB) {
        return lungimeB - lungimeA;
    }

    return strcmp(cuvantA, cuvantB);
}

int main() {
    char propozitie[1000];
    char* cuvinte[100];
    int nrCuvinte = 0;

    if (scanf_s("%[^\n]s", propozitie, (unsigned int)sizeof(propozitie)) != 1) {
        return 0;
    }

    char* context = NULL;
    char* token = strtok_s(propozitie, " ", &context);

    while (token != NULL && nrCuvinte < 100) {
        cuvinte[nrCuvinte++] = token;
        token = strtok_s(NULL, " ", &context);
    }

    qsort(cuvinte, nrCuvinte, sizeof(char*), comparaCuvinte);

    for (int i = 0; i < nrCuvinte; i++) {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}