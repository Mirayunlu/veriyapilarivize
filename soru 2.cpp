#include <stdio.h>

void diziler(int dizi1[], int sayi1, int dizi2[], int sayi2, int birlestiren[]) {
    int i = 0, j = 0, k = 0;
    while (i < sayi1 && j < sayi2) {
        if (dizi1[i] < dizi2[j]) {
            birlestiren[k++] = dizi1[i++];
        } else {
            birlestiren[k++] = dizi2[j++];
        }
    }
    while (i < sayi1) {
        birlestiren[k++] = dizi1[i++];
    }
    while (j < sayi2) {
       birlestiren[k++] = dizi2[j++];
    }
}

int main() {
    int dizi1[] = {1, 3, 5, 7, 9};
    int sayi1 = sizeof(dizi1) / sizeof(int);
    int dizi2[] = {2, 4, 6, 8, 10};
    int sayi2 = sizeof(dizi2) / sizeof(int);
    int birlestiren[sayi1 + sayi2];
    diziler(dizi1, sayi1, dizi2, sayi2, birlestiren);
    for (int i = 0; i < sayi1 + sayi2; i++) {
        printf("%d ", birlestiren[i]);
    }
    printf("\n");
    return 0;
}

