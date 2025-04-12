#include <stdio.h>
#include <locale.h>

struct Books {
	char bookname[100];
	char author[100];
	char availibility;
	int price;
};
struct Headerf {
	char al4[50];
	char al5[50];

};


struct Header {
	char al1[50];
	char al2[50];
	char al3[50];
	struct Headerf otherA;
};

int main() {
	setlocale(LC_ALL, "Russian");

	struct Books books_st[] = { {"Двенадцать", "Блок А.", 'Y', 320}, { "Одиссея", "Гомер", 'Y', 300},
	{"Илиада", "Гомер", 'N', 400},
	{"Холмы","Бродский",'Y',500},
	{"Саша", "Некрасов", 'N', 380},
	};
	

	struct Books* b = books_st;
	struct Books temp;
	struct Header header = { "Поэма","Наличие","Цена", {"Название","Автор"}};

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

}void change(struct Books*source, int sourceSize) {
	int i1, i2;
	;

};