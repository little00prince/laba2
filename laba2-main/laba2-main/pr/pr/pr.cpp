#define _CRT_SECURE_NO_WARNINGS
#define N 3
#include <iostream>

struct object
{
    float area;
    float volume;
    int type;
    union {
        struct {
            float a;
            float diagonal;
        }cube;
        struct {
            float r;
            float d;
        }ball;
        struct {
            float b;
            int view;
        }tetrapyramid;
    }figure;
};

object first, * second = NULL;
extern int g = 0;

int block_i(int min, int max);
float block_f();
void input(int type, float sides[]);
void processing();
void output();

int main()
{
    int type, min, max, i;
    float sides[N];
    setlocale(LC_ALL, "Rus");
    second = (object*)malloc(sizeof(object));
    do {
        printf("\n1-Куб\n2-Шар\n3-Правильный тетраид\n--------------------\nВыберите фигуру:");
        min = 1; max = 3;
        type = block_i(min, max);
        i = 0;
        switch (type)
        {
        case 1:
            printf("Длина стороны куба:");
            sides[i] = block_f();
            break;
        case 2:
            printf("Радиус шара:");
            sides[i] = block_f();
            break;
        case 3:
            printf("Длина стороны правильного тетраида:");
            sides[i] = block_f();
            break;
        default:;
        }
        input(type, sides);
        processing();
        output();
        g++;
    } while (g < 2);
    free(second);
}
//Защита на целые числа
int block_i(int min, int max)
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
float block_f()
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
        first.type = type;
        switch (type)
        {
        case 1:
            first.figure.cube.a = sides[i];
            break;
        case 2:
            first.figure.ball.r = sides[i];
            break;
        case 3:
            first.figure.tetrapyramid.b = sides[i];
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
            (*second).figure.cube.a = sides[i];
            break;
        case 2:
            (*second).figure.ball.r = sides[i];
            break;
        case 3:
            (*second).figure.tetrapyramid.b = sides[i];
            break;
        default:;
        }
    }
}
//Обработка данных
void processing()
{
    float s, v, a[N];
    if (g == 0)
    {
        switch (first.type)
        {
        case 1:
            a[0] = first.figure.cube.a;
            first.figure.cube.diagonal = sqrtf(3) * a[0];
            s = powf(a[0], 2) * 6;
            v = powf(a[0], 3);
            break;
        case 2:
            a[0] = first.figure.ball.r;
            first.figure.ball.d = a[0] * 2;
            s = 4 * 3.14 * pow(a[0], 2);
            v = 4 / 3 * 3.14 * pow(a[0], 3);
            break;
        case 3:
            a[0] = first.figure.tetrapyramid.b;
            s = (sqrtf(3) * pow(a[0], 2)) / 4;
            v = (pow(a[0], 3) * sqrtf(2)) / 12;
            break;
        default:;
        }
        first.area = s;
        first.volume = v;
    }
    else
    {
        switch ((*second).type)
        {
        case 1:
            a[0] = (*second).figure.cube.a;
            (*second).figure.cube.diagonal = sqrtf(3) * a[0];
            s = powf(a[0], 2) * 6;
            v = powf(a[0], 3);
            break;
        case 2:
            a[0] = (*second).figure.ball.r;
            (*second).figure.ball.d = a[0] * 2;
            s = 4 * 3.14 * pow(a[0], 2);
            v = 4 / 3 * 3.14 * pow(a[0], 3);
            break;
        case 3:
            a[0] = (*second).figure.tetrapyramid.b;
            s = (sqrtf(3) * pow(a[0], 2)) / 4;
            v = (pow(a[0], 3) * sqrtf(2)) / 12;
            break;
        default:;
        }
        (*second).area = s;
        (*second).volume = v;
    }
}
//Вывод структуры
void output()
{
    printf("Фигура: ");
    if (g == 0)
    {
        switch (first.type)
        {
        case 1:
            printf("куб");
            printf("\nДиагональ: %f", first.figure.cube.diagonal);
            break;
        case 2:
            printf("шар");
            printf("\nДиаметр: %f", first.figure.ball.d);
            break;
        case 3:
            printf("правильный тетраид");
            break;
        default:;
        }
        printf("\nПлощадь: %f", first.area);
        printf("\nОбъем: %f\n", first.volume);
    }
    else
    {
        switch ((*second).type)
        {
        case 1:
            printf("куб");
            printf("\nДиагональ: %f", (*second).figure.cube.diagonal);
            break;
        case 2:
            printf("шар");
            printf("\nДиаметр: %f", (*second).figure.ball.d);
            break;
        case 3:
            printf("правильный тетраид");
            break;
        default:;
        }
        printf("\nПлощадь: %f", (*second).area);
        printf("\nОбъем: %f\n", (*second).volume);
    }
}