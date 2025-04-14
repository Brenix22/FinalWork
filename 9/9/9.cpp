#include <stdio.h>
#include <locale.h>

// Структура для хранения информации о книгах
struct Books {
    char bookname[100];  // Название книги
    char author[100];     // Автор книги
    char availibility;    // Доступность книги (Y/N)
    int price;           // Цена книги
};

// Вложенная структура для заголовка таблицы
struct Headerf {
    char al4[50];       // Первая часть заголовка
    char al5[50];       // Вторая часть заголовка
};

// Основная структура для заголовка таблицы
struct Header {
    char al1[50];       // Колонка 1
    char al2[50];       // Колонка 2
    char al3[50];       // Колонка 3
    struct Headerf otherA;  // Вложенная структура с дополнительными полями
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Инициализация массива книг
    struct Books books_st[] = {
        {"Двенадцать", "Блок А.", 'Y', 320},
        {"Одиссея", "Гомер", 'Y', 300},
        {"Илиада", "Гомер", 'N', 400},
        {"Холмы", "Бродский", 'Y', 500},
        {"Саша", "Некрасов", 'N', 380}
    };

    // Указатель на массив книг
    struct Books* b;
    // Временная переменная для обмена
    struct Books temp;
    // Структура заголовка таблицы
    struct Header header;

    // Инициализация полей заголовка
    header.al1[0] = 'П';
    header.al1[1] = 'о';
    header.al1[2] = 'э';
    header.al1[3] = 'м';
    header.al1[4] = 'а';
    header.al1[5] = '\0';

    header.al2[0] = 'Н';
    header.al2[1] = 'а';
    header.al2[2] = 'л';
    header.al2[3] = 'и';
    header.al2[4] = 'ч';
    header.al2[5] = 'и';
    header.al2[6] = 'е';
    header.al2[7] = '\0';

    header.al3[0] = 'Ц';
    header.al3[1] = 'е';
    header.al3[2] = 'н';
    header.al3[3] = 'а';
    header.al3[4] = '\0';

    header.otherA.al4[0] = 'Н';
    header.otherA.al4[1] = 'а';
    header.otherA.al4[2] = 'з';
    header.otherA.al4[3] = 'в';
    header.otherA.al4[4] = 'а';
    header.otherA.al4[5] = 'н';
    header.otherA.al4[6] = 'и';
    header.otherA.al4[7] = 'е';
    header.otherA.al4[8] = '\0';

    header.otherA.al5[0] = 'А';
    header.otherA.al5[1] = 'в';
    header.otherA.al5[2] = 'т';
    header.otherA.al5[3] = 'о';
    header.otherA.al5[4] = 'р';
    header.otherA.al5[5] = '\0';

    b = books_st;

    printf("Изначальная таблица:\n");
    printf("---------------------------------------------------------\n");
    printf("%16s %13s %10s %15s\n", header.al1, "|", "|", "|");
    printf("-----------------------------| %10s %15s\n", "|", "|");
    printf("%s %9s %6s %4s %5s %2s %6s\n", header.otherA.al4, "|", header.otherA.al5, "|", header.al2, "|", header.al3, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %7s %4s %3s %5c %4s %8d %6s\n", b->bookname, "|", b->author, "|", b->availibility, "|", b->price, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %9s %4s %5s %5c %4s %8d %6s\n", (b + 1)->bookname, "|", (b + 1)->author, "|", (b + 1)->availibility, "|", (b + 1)->price, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %9s %4s %5s %5c %4s %8d %6s\n", (b + 2)->bookname, "|", (b + 2)->author, "|", (b + 2)->availibility, "|", (b + 2)->price, "|");
    printf("---------------------------------------------------------\n");
    printf("%-8s %9s %4s %2s %5c %4s %8d %6s\n", (b + 3)->bookname, "|", (b + 3)->author, "|", (b + 3)->availibility, "|", (b + 3)->price, "|");
    printf("---------------------------------------------------------\n");
    printf("%-8s %9s %4s %2s %5c %4s %8d %6s\n", (b + 4)->bookname, "|", (b + 4)->author, "|", (b + 4)->availibility, "|", (b + 4)->price, "|");
    printf("---------------------------------------------------------\n");

    // Обмен местами первой и третьей книг
    temp = books_st[0];
    books_st[0] = books_st[2];
    books_st[2] = temp;

    printf("\nИзмененная таблица:\n");
    printf("---------------------------------------------------------\n");
    printf("%16s %13s %10s %15s\n", "Поэма", "|", "|", "|");
    printf("-----------------------------| %10s %15s\n", "|", "|");
    printf("%s %9s %6s %4s %5s %2s %6s\n", header.otherA.al4, "|", header.otherA.al5, "|", header.al2, "|", header.al3, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %9s %4s %5s %5c %4s %8d %6s\n", b->bookname, "|", b->author, "|", b->availibility, "|", b->price, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %9s %4s %5s %5c %4s %8d %6s\n", (b + 1)->bookname, "|", (b + 1)->author, "|", (b + 1)->availibility, "|", (b + 1)->price, "|");
    printf("-----------------------------|----------|---------------|\n");
    printf("%-8s %7s %4s %3s %5c %4s %8d %6s\n", (b + 2)->bookname, "|", (b + 2)->author, "|", (b + 2)->availibility, "|", (b + 2)->price, "|");
    printf("---------------------------------------------------------\n");
    printf("%-8s %9s %4s %2s %5c %4s %8d %6s\n", (b + 3)->bookname, "|", (b + 3)->author, "|", (b + 3)->availibility, "|", (b + 3)->price, "|");
    printf("---------------------------------------------------------\n");
    printf("%-8s %9s %4s %2s %5c %4s %8d %6s\n", (b + 4)->bookname, "|", (b + 4)->author, "|", (b + 4)->availibility, "|", (b + 4)->price, "|");
    printf("---------------------------------------------------------\n");
}

void change(struct Books* source, int sourceSize) {
    int i1;  // Первый индекс для обмена
    int i2;  // Второй индекс для обмена
    // Функция для изменения порядка книг (пока не реализована)
};