#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Counter
{
public:

    Counter(int izmenenie) { this->izmenenie = izmenenie; }

    void process_plus()
    {
        izmenenie++;
    }

    void process_minus()
    {
        izmenenie--;
    }

    int get_pokazanie()
    {
        return izmenenie;
    }

private:
    int izmenenie;
};

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int n = 0;
    string soglasie;
    do {
        cout << "Вы хотите указать начальное значение счётчика ? Введите да или нет: ";
        cin >> soglasie;
        if (soglasie == "yes") { cout << "Введите начальное значение счётчика: "; }
        else if (soglasie == "no") { soglasie = n; }
        else { cout << "Неправильный ввод" << endl; }
    } while (soglasie != "yes" && soglasie != "no");
    cin >> n;
    auto schet = Counter(n);
    while (1)
    {
        char g;
        cout << "Введите команду('+', '-', '=' или 'x') :";
        cin >> g;
        if (g != 'x')
        {
            if (g == '+')
            {
                schet.process_plus();
            }
            else if (g == '-')
            {
                schet.process_minus();
            }
            else if (g == '=')
            {
                cout << schet.get_pokazanie() << endl;
            }
            else
            {
                cout << "Неправильный символ!" << endl;
            }
        }
        else
        {
            cout << "До свидания!";
            break;
        }
    }
    return 0;
}