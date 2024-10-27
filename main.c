/*
*  Точность ограничена определенным количеством знаком после запятой
*  на практиче около 9 знаков после запятой нормальная точность с минимальным количеством цифр в хвосте дробной части
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#define DEBUG

// массив для теста
double mas[] = {0, -0, 1, -1, 123, -123, 9876543, -9876543, 4500123456, -4500123456, 4500123456.123, -4500123456.123, 100.12345,
                -100.12345, 2.2, -2.2, 3.303, -3.303, 4.00001, -4.00001, 5.9000000001, -5.9000000001, 6.800000001, -6.800000001,
                1010.310321, -1010.310321, 1234567.12, -1234567.12, 7654321.12000000, -7654321.12000000};

char strSpecificator[10] = {}; // массив символов, в который будет формироваться спецификатор
                               // и указатель на который будет возвращать функция makeSpecificator

char* makeSpecificator(double a) // где a вещественное число, для которого необходимо сформировать спецификатор формата для printf
{
    char strNumDouble[30] = {};
    sprintf(strNumDouble, "%.9f", a); // преобразование вещественного числа в строку с точностью "%.9f"
                                      // где 9 это количество знаков после запятой
    #ifdef DEBUG
        printf("strNumDouble %s\n", strNumDouble);
    #endif // DEBUG
    int numPoint = 0;
    char strAfterProcessing[30] = {};
    for (int i = 0; i < 30; i++)
    {
        if(strNumDouble[i] == '.')
        {
            numPoint = i;
            break;
        }
    }

    sprintf(strAfterProcessing, "%s", &strNumDouble[numPoint]);
    #ifdef DEBUG
        printf("strAfterProcessing %s\n", strAfterProcessing);
    #endif // DEBUG
    int razr = 0;
    for (int i = 29; i >=0 ; i--)
    {
        if (strAfterProcessing[i] > '0' && strAfterProcessing[i] <= '9')
        {
            razr = i;
            break;
        }
    }

    char strNumSpecif[3] = {};
    sprintf(strNumSpecif, "%d", razr);
    sprintf(strSpecificator, "%s" , "%.");
    strcat(strSpecificator, strNumSpecif);
    strcat(strSpecificator, "f");

    return strSpecificator;
}

int main()
{
    for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
    {
        printf(makeSpecificator(mas[i]), mas[i]); // использование функции makeSpecificator
        printf("\n");
    }

    return 0;
}
