#define _CRT_SECURE_NO_WARNINGS
#define N 3
#include <iostream>
#include <conio.h>

class figure
{
protected:
    float area;
    float volume;
    figure();
    ~figure();
public:
    float get_area();
    float get_volume();
};
//Конструктор
figure::figure()
{
    area = 0;
    volume = 0;
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
float figure::get_volume()
{
    return volume;
}

//<---куб--->
class cube : public figure
{
    float a;
    float diagonal;
public:
    void set_a(float e);
    void work_cube();
    float get_diagonal();
};
//Ввод стороны
void cube::set_a(float e)
{
    a = e;
}
//Обработка данных
void cube::work_cube()
{
    diagonal = sqrtf(3) * a;
    area = powf(a, 2) * 6;
    volume = powf(a, 3);
}
//Вывод диагонали
float cube::get_diagonal()
{
    return diagonal;
}

//<---шар--->
class ball : public figure
{
    float r;
    float d;
public:
    void set_r(float e);
    void work_ball();
    float get_d();
};
//Ввод радиуса
void ball::set_r(float e)
{
    r = e;
}
//Обработка данных
void ball::work_ball()
{
    d = r * 2;
    area = 4 * 3.14 * pow(r, 2);
    volume = 4 / 3 * 3.14 * pow(r, 3);
}
//Вывод диаметра
float ball::get_d()
{
    return d;
}

//<---правильный тетраид--->
class tetrapyramid : public figure
{
    float b;
public:
    void set_b(float e);
    void work_tetrapyramid();
};
//Ввод стороны
void tetrapyramid::set_b(float e)
{
    b = e;
}
//Обработка данных
void tetrapyramid::work_tetrapyramid()
{
    area = (sqrtf(3) * pow(b, 2)) / 4;
    volume = (pow(b, 3) * sqrtf(2)) / 12;
}

int block_i(int min, int max);
float block_f();

int main()
{
    int type, min, max, i,j;
    float e,p,s;
    cube* one = NULL;
    ball* two = NULL;
    tetrapyramid* three = NULL;
    setlocale(LC_ALL, "Rus");
    one = (cube*)calloc(N, sizeof(cube));
    two = (ball*)calloc(N, sizeof(ball));
    three = (tetrapyramid*)calloc(N, sizeof(tetrapyramid));
    j = 0;
    //Полный цикл программы
    do {
        printf("\n1-Куб\n2-Шар\n3-Правильный тетраид\n--------------------\nВыберите фигуру:");
        min = 1; max = 3;
        type = block_i(min, max);
        //Ввод и обработка
        switch (type)
        {
        case 1:
            printf("Длина стороны куба:");
            e = block_f();
            (one + j)->set_a(e);
            (one + j)->work_cube();
            break;
        case 2:
            printf("Радиус шара:");
            e = block_f();
            two->set_r(e);
            two->work_ball();
            break;
        case 3:
            printf("Длина стороны правильного тетраида:");
            e = block_f();
            three->set_b(e);
            three->work_tetrapyramid();
            break;
        default:;
        }
        //Вывод
        printf("Фигура: ");

        switch (type)
        {
        case 1:
            printf("Куб");
            e = (one + j)->get_diagonal();
            printf("\nДиагональ: %f", e);
            s = (one + j)->get_area();
            p = (one + j)->get_volume();
            j++;
            break;
        case 2:
            printf("Шар");
            e = two->get_d();
            printf("\nДиаметр: %f", e);
            s = two->get_area();
            p = two->get_volume();
            break;
        case 3:
            printf("Правильный тетраид");
            s = three->get_area();
            p = three->get_volume();
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