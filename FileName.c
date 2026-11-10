#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define M_PI 3.14159265358979323846

float area_triangle(float a, float b, float c);
void draw_triangle(int width, int height, char sym);
void print_definition();

int main() {
    setlocale(LC_ALL, "rus");

    int choice;
    double alpha_g = 45;
    double b = 4;
    char sym = '*';



    // Перевод угла в радианы и расчет остальных сторон
    double alpha_rad = alpha_g * M_PI / 180.0;
    double a = b * tan(alpha_rad);         // Противолежащий катет
    double c_exact = b / cos(alpha_rad);         // Гипотенуза


    int height = (int)(a);
    int width = (int)(b);
    if (height < 1) height = 1;
    if (width < 1) width = 1;


    while (1) {
        printf("\nВыберите операцию:\n");
        printf("1) Рассчитать площадь\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Выход\n");
        printf("Ваш выбор: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Выход из программы.\n");
            break;
        }

        if (choice == 4) {
            printf("Программа завершена.\n");
            break;
        }

        switch (choice) {
        case 1: {
        
            float area = area_triangle((float)a, (float)b, (float)c_exact);
            printf("\nПлощадь прямоугольного треугольника: %.2f\n", area);
            break;
        }
        case 2:
            print_definition();
            break;
        case 3:
            printf("\nРисунок фигуры (Высота ~ %d, Ширина = %d):\n", height, width);
            draw_triangle(width, height, sym);
            break;
        default:
            printf("Неверный пункт меню. Попробуйте еще раз.\n");
        }
    }

    return 0;
}

float area_triangle(float a, float b, float c) {

    return 0.5f * a * b;
}

void print_definition() {
    printf("\nОпределение фигуры:\n");
    printf("Прямоугольный треугольник — это треугольник, у которого один из углов прямой (равен 90 градусам).\n");
}

void draw_triangle(int width, int height, char sym) {
    for (int y = 0; y < height; y++) {

        double precise_current_width = ((double)(y + 1) / height) * width;
        int current_width = (int)(precise_current_width + 0.5);

        for (int x = 0; x < current_width; x++) {
            printf("%c", sym);
        }
        printf("\n");
    }
}
