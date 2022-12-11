#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
class Triangle
{
    const int ID = count;
    static int count;
    double _angel, _firtsSide, _secondSide;
    double bisector(double _side, double _side2, double _side3);
    double Corners(int number);
    double get_thirdSide();
public:
    int getID() const;
    ~Triangle();
    Triangle();
    static int get_count();
    void zoom_angel();
    double get_angel() const;
    double get_firstSide() const;
    double get_secondSide() const;
    void set_angel(double _angel);
    void set_firstSide(double _firstSide);
    void set_secondSide(double _secondSide);
    void type_of_triangle();
    void show_all_angels();
    void show_bisector();
};

int Triangle::count = 0;

int Triangle::getID() const
{
    return ID;
}

int Triangle::get_count()
{
    return count;
}

Triangle::~Triangle()
{
    cout << "Уничтожение " << count << " треугольника.....\n";
    count--;
}

Triangle::Triangle()
{

    count++;
    cout << "Создание " << count << " треугольника.....\n";
}

double Triangle::Corners(int number) {
    double corners[3];
    corners[0] = _angel;
    corners[1] = acos(((pow(_firtsSide, 2) + pow(get_thirdSide(), 2) - pow(_secondSide, 2)) / (2 * _firtsSide * get_thirdSide()))) * 180 / 3.14;
    corners[2] = acos(((pow(_secondSide, 2) + pow(get_thirdSide(), 2) - pow(_firtsSide, 2)) / (2 * _secondSide * get_thirdSide()))) * 180 / 3.14;
    return corners[number];
}

void Triangle::show_all_angels() {
    cout << "Первый угол: ";
    cout << Corners(0) << "\n";
    cout << "Второй угол: ";
    cout << Corners(1) << "\n";
    cout << "Третий угол: ";
    cout << Corners(2) << "\n";
}

void Triangle::set_angel(double _angel)
{
    if (_angel <= 0 || _angel == 180)
        throw exception("Угол не может быть меньше или равным нулю, и не может быть равен 180 градусам!\n");
    this->_angel = _angel;
}

void Triangle::set_firstSide(double _firstSide)
{
    if (_firstSide <= 0)
        throw exception("Сторона треугольника не может быть отрицательной!\n");
    this->_firtsSide = _firstSide;
}

void Triangle::set_secondSide(double _secondSide)
{
    if (_secondSide <= 0)
        throw exception("Сторона треугольника не может быть отрицательной!\n");
    this->_secondSide = _secondSide;
}

double Triangle::get_angel() const
{
    return _angel;
}

double Triangle::get_firstSide() const
{
    return _firtsSide;
}

double Triangle::get_secondSide() const
{
    return _secondSide;
}

double Triangle::get_thirdSide()
{
    return sqrt(pow(_firtsSide, 2) + pow(_secondSide, 2) - 2 * (_firtsSide * _secondSide * cos((3.14 * _angel) / 180)));
}

void Triangle::zoom_angel()
{
    bool T = true;
    double n;
    cout << "1.Увеличить\n2.Уменьшить\n";
    do
    {
        switch (_getch())
        {
        case '1':
            cout << "Введите количество процентов, на которое хотите увеличить угол треугольника\n";
            cin >> n;
            _angel *= 1 + n / 100;
            T = false;
            break;
        case '2':
            cout << "Введите количество процентов, на которое хотите уменьшить угол треугольника\n";
            cin >> n;
            _angel *= 1 - n / 100;
            T = false;
            break;
        default:
            break;
        }
    } while (T);
}

void Triangle::type_of_triangle()
{
    if (_firtsSide != _secondSide && _secondSide != get_thirdSide() && get_thirdSide() != _firtsSide)
        cout << "Треугольник разносторонний!\n";
    else if (round(_firtsSide) == round(_secondSide) && round(_secondSide) == round(get_thirdSide()) && round(get_thirdSide()) == round(_firtsSide))
        cout << "Треугольник равносторонний!\n";
    else if (_firtsSide == _secondSide || _firtsSide == get_thirdSide() || _secondSide == get_thirdSide())
        cout << "Треугольник равнобедренный!\n";
}


double Triangle::bisector(double _side, double _side2, double _side3)
{
    double sum = _firtsSide + _secondSide + get_thirdSide();
    return (sqrt(_side * _side2 * (sum) * (_side + _side2 - _side3)) / (_side + _side2));
}

void Triangle::show_bisector()
{
    cout << "Первая биссекриса: ";
    cout << bisector(_firtsSide, _secondSide, get_thirdSide()) << "\n";
    cout << "Вторая биссекриса: ";
    cout << bisector(_secondSide, get_thirdSide(), _firtsSide) << "\n";
    cout << "Третья биссекриса: ";
    cout << bisector(get_thirdSide(), _firtsSide, _secondSide) << "\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Triangle tr, tr2, tr3;
    cout << "ID первого треугольника: " << tr.getID()  << "\n" << "ID второго треугольника: " << tr2.getID() << "\n" << "ID третьего треугольника: " << tr3.getID() << endl;
    Triangle tr1;
    const Triangle tr4;
    tr1.set_angel(60);
    tr1.set_firstSide(5);
    tr1.set_secondSide(4);
    tr1.show_all_angels();
    //tr4.set_angel(60);
    //tr4.set_firstSide(5);
    //tr4.set_secondSide(4);
    //tr4.show_all_angels();
    //Для константных объектов можно вызывать только константные методы!
    cout << tr4.getID() << endl;
    cout << tr2.getID() << endl;

}