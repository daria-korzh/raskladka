#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

int main()
{
    /*setlocale(LC_ALL, "Russian");*/
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char eng[] = "`qwertyuiop[]asdfghjkl;'zxcvbnm,./"
        "~QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?";

    char rus[] = "ёйцукенгшщзхъфывапролджэячсмитьбю."
        "ЁЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ,";

    char text[256];

    cout << "Введите текст: ";
    cin.getline(text, 256);

    bool english = false;
    bool russian = false;

    for (int i = 0; text[i] != '\0'; i++)
    {
        bool induk = true;

        for (int j = 0; eng[j] != '\0' && induk; j++)
        {
            if (text[i] == eng[j])
            {
                english = true;
                induk = false;
            }
        }

        induk = true;

        for (int j = 0; rus[j] != '\0' && induk; j++)
        {
            if (text[i] == rus[j])
            {
                russian = true;
                induk = false;
            }
        }
    }

    cout << "Результат: ";

    if (english)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            bool found = false;
            bool induk = true;

            for (int j = 0; eng[j] != '\0' && induk; j++)
            {
                if (text[i] == eng[j])
                {
                    cout << rus[j];
                    found = true;
                    induk = false;
                }
            }

            if (!found)
                cout << text[i];
        }
    }
    else if (russian)
    {
        for (int i = 0; text[i] != '\0'; i++)
        {
            bool found = false;
            bool induk = true;

            for (int j = 0; rus[j] != '\0' && induk; j++)
            {
                if (text[i] == rus[j])
                {
                    cout << eng[j];
                    found = true;
                    induk = false;
                }
            }

            if (!found)
                cout << text[i];
        }
    }
    else
    {
        cout << text;
    }

    cout << endl;

    return 0;
}