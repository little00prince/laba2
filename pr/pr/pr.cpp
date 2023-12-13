#define _CRT_SECURE_NO_WARNINGS
#define N 3
#include <iostream>

struct object
{
    float area;
    float perimeter;
    int type;
    union {
        struct {
            float a;
            float diagonal;
        }square;
        struct {
            float r;
            float d;
        }circle;
        struct {
            float sides[N];
            int view;
        }triangle;
    }figure;
};

object example, * second = NULL;
extern int g = 0;

int block_int(int min, int max);
float block_float();
void input(int type, float sides[]);
void work();
void output();

int main()
{
    int type, min, max, i;
    float sides[N];
    setlocale(LC_ALL, "Rus");
    second = (object*)malloc(sizeof(object));
    do {
        printf("\n1-квадрат\n2-круг\n3-треугольник\nВыберите фигуру:");
        min = 1; max = 3;
        type = block_int(min, max);
        i = 0;
        switch (type)
        {
        case 1:
            printf("Длина стороны квадрата:");
            sides[i] = block_float();
            break;
        case 2:
            printf("Радиус круга:");
            sides[i] = block_float();
            break;
        case 3:
            printf("Длина сторон треугольника:");
            for (; i < 3; i++)
            {
                sides[i] = block_float();
            }
            break;
        default:;
        }
        input(type, sides);
        work();
        output();
        g++;
    } while (g < 2);
    free(second);
}
//Защита на целые числа
int block_int(int min, int max)
{
    int type, f = 1;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%d", &type) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (type<min || type>max);
    printf("\n");
    return type;
}
//Защита на дробные числа
float block_float()
{
    int f = 1;
    float e;
    do {
        if (f != 1)
        {
            printf("Такого варианта нет. Попробуйте ещё раз: ");
        }
        while (scanf("%f", &e) != 1)
        {
            while (getchar() != '\n');
            printf("Ошибка. Попробуйте ещё раз: ");
        }
        f = 0;
        while (getchar() != '\n');
    } while (e <= 0);
    printf("\n");
    return e;
}
//Ввод в структуру
void input(int type, float sides[])
{
    int i = 0;
    if (g == 0)
    {
        example.type = type;
        switch (type)
        {
        case 1:
            example.figure.square.a = sides[i];
            break;
        case 2:
            example.figure.circle.r = sides[i];
            break;
        case 3:
            for (; i < 3; i++)
            {
                example.figure.triangle.sides[i] = sides[i];
            }
            break;
        default:;
        }
    }
    else
    {
        (*second).type = type;
        switch (type)
        {
        case 1:
            (*second).figure.square.a = sides[i];
            break;
        case 2:
            (*second).figure.circle.r = sides[i];
            break;
        case 3:
            for (; i < 3; i++)
            {
                (*second).figure.triangle.sides[i] = sides[i];
            }
            break;
        default:;
        }
    }
}
//Обработка данных
void work()
{
    float s, p, a[N], p2;
    if (g == 0)
    {
        switch (example.type)
        {
        case 1:
            a[0] = example.figure.square.a;
            example.figure.square.diagonal = sqrtf(2) * a[0];
            s = powf(a[0], 2);
            p = a[0] * 4;
            break;
        case 2:
            a[0] = example.figure.circle.r;
            example.figure.circle.d = a[0] * 2;
            s = 3.14 * pow(a[0], 2);
            p = 3.14 * 2 * a[0];
            break;
        case 3:
            for (int i = 0; i < 3; i++)
            {
                a[i] = example.figure.triangle.sides[i];
            }
            p = a[0] + a[1] + a[2];
            p2 = p / 2;
            s = sqrtf(p2 * (p2 - a[0]) * (p2 - a[1]) * (p2 - a[2]));
            if (a[0] == a[1] && a[1] == a[2])
                example.figure.triangle.view = 1;
            else if (a[0] == a[1] || a[1] == a[2])
                example.figure.triangle.view = 2;
            else example.figure.triangle.view = 3;
            break;
        default:;
        }
        example.area = s;
        example.perimeter = p;
    }
    else
    {
        switch ((*second).type)
        {
        case 1:
            a[0] = (*second).figure.square.a;
            (*second).figure.square.diagonal = sqrtf(2) * a[0];
            s = powf(a[0], 2);
            p = a[0] * 4;
            break;
        case 2:
            a[0] = (*second).figure.circle.r;
            (*second).figure.circle.d = a[0] * 2;
            s = 3.14 * pow(a[0], 2);
            p = 3.14 * 2 * a[0];
            break;
        case 3:
            for (int i = 0; i < 3; i++)
            {
                a[i] = (*second).figure.triangle.sides[i];
            }
            p = a[0] + a[1] + a[2];
            p2 = p / 2;
            s = sqrtf(p2 * (p2 - a[0]) * (p2 - a[1]) * (p2 - a[2]));
            if (a[0] == a[1] && a[1] == a[2])
                (*second).figure.triangle.view = 1;
            else if (a[0] == a[1] || a[1] == a[2])
                (*second).figure.triangle.view = 2;
            else (*second).figure.triangle.view = 3;
            break;
        default:;
        }
        (*second).area = s;
        (*second).perimeter = p;
    }
}
//Вывод структуры
void output()
{
    printf("Фигура: ");
    if (g == 0)
    {
        switch (example.type)
        {
        case 1:
            printf("квадрат");
            printf("\nДиагональ: %f", example.figure.square.diagonal);
            break;
        case 2:
            printf("круг");
            printf("\nДиаметр: %f", example.figure.circle.d);
            break;
        case 3:
            switch (example.figure.triangle.view)
            {
            case 1:
                printf("равносторонний ");
                break;
            case 2:
                printf("равнобедренный ");
                break;
            case 3:
                printf("разносторонний ");
                break;
            default:;
            }
            printf("треугольник");
            break;
        default:;
        }
        printf("\nПлощадь: %f", example.area);
        printf("\nПериметр: %f\n", example.perimeter);
    }
    else
    {
        switch ((*second).type)
        {
        case 1:
            printf("квадрат");
            printf("\nДиагональ: %f", (*second).figure.square.diagonal);
            break;
        case 2:
            printf("круг");
            printf("\nДиаметр: %f", (*second).figure.circle.d);
            break;
        case 3:
            switch ((*second).figure.triangle.view)
            {
            case 1:
                printf("равносторонний ");
                break;
            case 2:
                printf("равнобедренный ");
                break;
            case 3:
                printf("разносторонний ");
                break;
            default:;
            }
            printf("треугольник");
            break;
        default:;
        }
        printf("\nПлощадь: %f", (*second).area);
        printf("\nПериметр: %f\n", (*second).perimeter);
    }
}