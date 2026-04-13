#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int countWords(char* str) {
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i]) && !inWord) {
            inWord = 1;
            count++;
        }
        else if (isspace(str[i])) {
            inWord = 0;
        }
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int cor = 1;
    while (cor == 1) {
        const int MAX = 1000;
        char text[MAX];
        char sentence[MAX];

        int i = 0, j = 0;

        int maxLen = 0;
        char longest[MAX] = "";
        int isEqual = 2;
        printf("Введiть текст:\n");

        gets_s(text, MAX);

        while (text[i] != '\0') {
            sentence[j++] = text[i];


            if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
                sentence[j] = '\0';

                int words = countWords(sentence);

                printf("Речення: %s\n", sentence);
                printf("Кiлькiсть слiв: %d\n\n", words);

                if (strlen(sentence) > maxLen) {
                    maxLen = strlen(sentence);
                    strcpy_s(longest, sentence);
                    isEqual = 0;
                }
                else if (strlen(sentence) == maxLen) {

                    isEqual = 1;
                }

                j = 0;
            }

            i++;
        }
        if (isEqual == 0) {
            printf("Найдовше речення:\n%s\n", longest);
        }
        else if (isEqual == 1) {
            printf("Речення мають однакову довжину.\n");
        }
        else if (isEqual == 2)
    	 {
            printf("Речень не знайдено, можливо ви забули роздiловi знаки.\n");
	}
		printf("Бажаєте продовжити? (1 - так, 0 - нi): ");
        scanf_s("%d", &cor);
		getchar(); 
    }


}
