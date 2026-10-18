#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Прототипы функций по заданию
float area_rectangle(float a, float b);
void draw_rectangle(int a, int b);
void print_definition();

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    float width, height;

    printf("=== Индивидуальное задание (Вариант 26: Прямоугольник) ===\n");
    printf("Введите ширину фигуры: ");
    if (scanf("%f", &width) != 1 || width <= 0) {
        printf("Ошибка ввода ширины.\n");
        return 1;
    }

    printf("Введите высоту фигуры: ");
    if (scanf("%f", &height) != 1 || height <= 0) {
        printf("Ошибка ввода высоты.\n");
        return 1;
    }

    // Главное меню программы
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
            float area = area_rectangle(width, height);
            printf("\nПлощадь прямоугольника: %.2f\n", area);
            break;
        }
        case 2:
            print_definition();
            break;
        case 3:
            printf("\nРисунок фигуры (округлено до целых чисел):\n");
            draw_rectangle((int)width, (int)height);
            break;
        default:
            printf("Неверный пункт меню. Попробуйте еще раз.\n");
        }
    }

    return 0;
}

// 1) Функция расчета площади
float area_rectangle(float a, float b) {
    return a * b;
}

// 2) Функция вывода определения фигуры
void print_definition() {
    printf("\nОпределение фигуры:\n");
    printf("Прямоугольник — это четырехугольник, у которого все углы прямые (равны 90 градусам).\n");
    printf("В Варианте 26 представлена составная фигура из пересекающихся прямоугольников.\n");
}

// 3) Функция рисования фигуры символом '*'
void draw_rectangle(int a, int b) {
    if (a <= 0 || b <= 0) {
        printf("Невозможно нарисовать фигуру с нулевыми или отрицательными размерами.\n");
        return;
    }
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            printf("* ");
        }
        printf("\n");
    }
}
