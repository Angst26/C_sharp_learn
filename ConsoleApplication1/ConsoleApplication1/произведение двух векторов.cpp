
// вывод по нажатию enter каждой строки 
#include <iostream> 
#include <Windows.h>
using namespace std;
/////////////////////////////////////////////////////////// 
class Distance  // класс английских мер длины 
{
private:
int feet;
float inches;
  public:
      // конструктор без параметров 
      Distance() : feet(0), inches(0.0)
      { }
      // конструктор с двумя параметрами 
      Distance(int ft, float in) : feet(ft), inches(in)
      { }
      // получение информации от пользователя 
      void getdist()
      {
          cout << "\nВведите футы: "; cin >> feet;
          cout << "Введите дюймы: ";  cin >> inches;
      }
      // показ информации 
      void showdist()
      {
          cout << feet << "\'-" << inches << '\"';
      }
      // сравнение двух длин 
      bool operator<(Distance) const;
      Distance operator- (Distance d2)
      {
          int f = feet;
          float in = inches;
          if (feet >= d2.feet)
          {
              f = feet - d2.feet;
              in = inches - d2.inches;
              if (in < 0)
              {
                  f--;
                  in += 12.0;
              }
          }
          else { exit(1); }
          return Distance(f, in);
      }
      
};
/////////////////////////////////////////////////////////// 
// сравнение двух длин 
bool Distance::operator<(Distance d2) const
{
    float bf1 = feet + inches / 12;
    float bf2 = d2.feet + d2.inches / 12;
    return (bf1 < bf2) ? true : false;
}
/////////////////////////////////////////////////////////// 
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Distance d1(11, 6);
    Distance d2(0, 7);
    Distance d3 = d1 - d2;
    d3.showdist();
    return 0;
}