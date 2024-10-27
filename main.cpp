#include <iostream>
#include <cstring>

using namespace std;

//#define DEBUG

// массив для теста
double mas[] = {0, -0, 1, -1, 123, -123, 9876543, -9876543, 4500123456, -4500123456, 4500123456.123, -4500123456.123, 100.12345,
                -100.12345, 2.2, -2.2, 3.303, -3.303, 4.00001, -4.00001, 5.9000000001, -5.9000000001, 6.800000001, -6.800000001,
                1010.310321, -1010.310321, 1234567.12, -1234567.12, 7654321.12000000, -7654321.12000000};

string strSpecificator; // строковый объект, в которой будет формироваться спецификатор
                        // и указатель на который будет возвращать функция makeSpecificator

const char* makeSpecificator(double a) // где a вещественное число, для которого необходимо сформировать спецификатор формата для printf
{
    char strNumDouble[40] = {};
    sprintf(strNumDouble, "%.9f", a); // преобразование вещественного числа в строку с точностью "%.9f"
                                      // - где 9 это количество знаков после запятой
    #ifdef DEBUG
        printf("strNumDouble %s\n", strNumDouble);
    #endif // DEBUG
    int numPoint = 0;
    for (int i = 0; i < 30; i++)
    {
        if(strNumDouble[i] == '.')
        {
            numPoint = i;
            break;
        }
    }

    string strAfterProcessing = &strNumDouble[numPoint];
    #ifdef DEBUG
        cout << strAfterProcessing << endl;
    #endif // DEBUG
    int razr = 0;
    for (int i = strAfterProcessing.size() - 1; i >=0 ; i--)
    {
        if (strAfterProcessing[i] > '0' && strAfterProcessing[i] <= '9')
        {
            razr = i;
            break;
        }
    }

    strSpecificator = "%." + to_string(razr) + "f";
    #ifdef DEBUG
        cout << strSpecificator << endl;
    #endif // DEBUG
    
    return strSpecificator.c_str();
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