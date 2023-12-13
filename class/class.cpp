#define _CRT_SECURE_NO_WARNINGS
#define N 3
#include <iostream>
#include <conio.h>

class figure
{
protected:
    float area;
    float perimeter;
    figure();
    ~figure();
public:
    float get_area();
    float get_perimeter();
};
//Конструктор
figure::figure()
{
    area = 0;
    perimeter = 0;
}
//Деструктор
figure::~figure()
{

}
//Вывод площади
float figure::get_area()
{
    return area;
}
//Вывод периметра
float figure::get_perimeter()
{
    return perimeter;
}

//<---квадрат--->
class square : public figure
{
    float a;
    float diagonal;
public:
    void set_a(float e);
    void work_square();
    float get_diagonal();
};
//Ввод стороны
void square::set_a(float e)
{
    a = e;
}
//Обработка данных
void square::work_square()
{
    diagonal = sqrtf(2) * a;
    area = powf(a, 2);
    perimeter = a * 4;
}
//Вывод диагонали
float square::get_diagonal()
{
    return diagonal;
}

//<---круг--->
class circle : public figure
{
    float r;
    float d;
public:
    void set_r(float e);
    void work_circle();
    float get_d();
};
//Ввод радиуса
void circle::set_r(float e)
{
    r = e;
}
//Обработка данных
void circle::work_circle()
{
    d = r * 2;
    area = 3.14 * pow(r, 2);
    perimeter = 3.14 * 2 * r;
}
//Вывод диаметра
float circle::get_d()
{
    return d;
}

//<---треугольник--->
class triangle : public figure
{
    float sides[N];
    int view;
public:
    void set_sides(float t[]);
    void work_triangle();
    int get_view();
};
//Ввод сторон
void triangle::set_sides(float t[])
{
    for (int i = 0; i < N; i++)
        sides[i] = t[i];
}
//Обработка данных
void triangle::work_triangle()
{
    float p2;
    perimeter = sides[0] + sides[1] + sides[2];
    p2 = perimeter / 2;
    area = sqrtf(p2 * (p2 - sides[0]) * (p2 - sides[1]) * (p2 - sides[2]));
    if (sides[0] == sides[1] && sides[1] == sides[2])
        view = 1;
    else if (sides[0] == sides[1] || sides[1] == sides[2])
        view = 2;
    else view = 3;
}
//Вывод вида треугольника
int triangle::get_view()
{
    return view;
}

int block_int(int min, int max);
float block_float();

int main()
{
    int type, min, max, i,j;
    float e, t[N],p,s;
    square* one = NULL;
    circle* two = NULL;
    triangle* three = NULL;
    setlocale(LC_ALL, "Rus");
    one = (square*)calloc(N, sizeof(square));
    two = (circle*)calloc(N, sizeof(circle));
    three = (triangle*)calloc(N, sizeof(triangle));
    j = 0;
    //Полный цикл программы
    do {
        printf("\n1-квадрат\n2-круг\n3-треугольник\nВыберите фигуру:");
        min = 1; max = 3;
        type = block_int(min, max);
        //Ввод и обработка
        switch (type)
        {
        case 1:
            printf("Длина стороны квадрата:");
            e = block_float();
            (one + j)->set_a(e);
            (one + j)->work_square();
            break;
        case 2:
            printf("Радиус круга:");
            e = block_float();
            two->set_r(e);
            two->work_circle();
            break;
        case 3:
            printf("Длина сторон треугольника:");
            for (i = 0; i < 3; i++)
            {
                t[i] = block_float();
            }
            three->set_sides(t);
            three->work_triangle();
            break;
        default:;
        }
        //Вывод
        printf("Фигура: ");

        switch (type)
        {
        case 1:
            printf("квадрат");
            e = (one + j)->get_diagonal();
            printf("\nДиагональ: %f", e);
            s = (one + j)->get_area();
            p = (one + j)->get_perimeter();
            j++;
            break;
        case 2:
            printf("круг");
            e = two->get_d();
            printf("\nДиаметр: %f", e);
            s = two->get_area();
            p = two->get_perimeter();
            break;
        case 3:
            i = three->get_view();
            switch (i)
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
            s = three->get_area();
            p = three->get_perimeter();
            break;
        default:;
        }
        printf("\nПлощадь: %f", s);
        printf("\nПериметр: %f\n", p);
        printf("\nНажмите ESC для выхода или любую клавишу для продолжения\n");
    } while (j < N && _getch() != 27);
    delete one;
    delete two;
    delete three;
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