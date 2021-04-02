#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;
struct Song
{
    string name;
    string author;
    int year;
    string text;
};
void BigMenu()
{
    cout << "Меню пользователя:" << endl;
    cout << "Добавление текста песни -1 " << endl;
    cout << "Удаление текста песни - 2 " << endl;
    cout << "Изменение текста песни -3 " << endl;
    cout << "Отображение текста песни  на экран -4 " << endl;
    cout << "Сохранение текста песни в файл - 5 " << endl;
    cout << "Поиск и отображение всех песен одного автора - 6 " << endl;
    cout << "Поиск и отображение всех песен, содержащих слово, указанное пользователем - 7 " << endl;
    cout << "Сортировка по автору -8 " << endl;
    cout << endl;
}
void Input(Song* song)
{
    song[0].name = "\"Listen to your heart\"";
    song[0].author = "Roxette";
    song[0].year = 1989;
    song[0].text;
    song[1].name = "\"Beautiful things\"";
    song[1].author = "Roxette";
    song[1].year = 2003;
    song[1].text;
    song[2].name = "\"I just called to say I love you\"";
    song[2].author = "Stevie Wonder";
    song[2].year = 1984;
    song[2].text;
    song[3].name = "\"Do what you can\"";
    song[3].author = "Bon Jovi";
    song[3].year = 2020;
    song[3].text;
}
void Print(Song* song)
{
    for (int i = 0; i < 4; i++)
    {
        cout << (i + 1) << " Song " << ':' << endl;
        cout << "Name\t" << song[i].name << endl;
        cout << "Author\t" << song[i].author << endl;
        cout << "Year\t" << song[i].year << endl;
        cout << "Text\t" << song[i].text << endl;
        cout << endl;
    }
}
void AddText(Song* song)
{
    cout << "Добавление текста песен " << endl << endl;
    song[0].text = "Listen to your heart\n when he’s calling for you\n Listen to your heart there’s nothing\n else you can do";
    song[1].text = "Beautiful things are comin'\n my way beautiful things\n I want them to stay";
    song[2].text = "I just called\n to say I love you\n I just called to say how much\n I care I just called to say I love you\n And I mean it from the bottom of my heart";
    song[3].text = "When you can't do what you do\n You do what you can\n This ain't my prayer\n, it's just a thought I'm wanting to send";
    Print(song);
}
void Delete(Song* song)
{
    for (int i = 0; i < 4; i++)
        song[i].text = " ";
    Print(song);
}
void Change(Song* song)
{
    cout << "Введите текст ";
    int i = 0;
    while (i != 4)
    {
        cin.ignore();
        getline(cin, song[i].text);
        ++i;
    }
    Print(song);

}
void Displaytext(Song* song)
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Для песни " << song[i].name << " следующий текст песни\n " << song[i].text << endl;
        cout << endl << endl;
    }

}
void DisplayNameOneAuthor(Song* song)
{
    string c;
    cout << "Введите автора песен  ";
    cin.ignore(32765, '\n');
    cin.clear();
    getline(cin, c);
    int d = 0;
    for (int i = 0; i < 4; i++)
    {
        if (c == song[i].author)
        {
            cout << song[i].name << endl;
            cout << endl;
            d++;
        }
    }
    if (d == 0)
        cout << "Извините, но песен такого автора в нашей картотеке нет ";
    cout << endl;
}
void WordInText(Song* song)
{
    string word;
    cout << "Введите слово, которое вы хотите увидеть в песне...";
    cin >> word;
    int pos = 0;
    for (int i = 0; i < 4; i++)
    {

        if (song[i].text.find(word) <= song[i].text.length())
        {
            cout << "Эти слова есть в песне " << song[i].name << "\n" << song[i].text << endl;
            pos++;
        }
    }
    if (pos == 0)
        cout << "Извините, ни в одной нашей песне нет такого слова ";

}
void SortAuthor(Song* song)
{
    cout << "Сортировка по автору" << endl;
    for (int i = 0; i < 4; i++)
    {
        int j = i;
        for (int j = 0; j < 4; j++)
        {
            if (song[i].author < song[j].author)
            {
                swap(song[i].author, song[j].author);
                swap(song[i].name, song[j].name);
                swap(song[i].year, song[j].year);
                swap(song[i].text, song[j].text);

            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << song[i].author << endl;
    }

}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Song song[4];
    Input(song);
    Print(song);
    AddText(song);
    cout << endl;
    BigMenu();
    int key;
    cout << "Введите числа от 1 до 8 ";
    cout << "ваш выбор ";
    cin >> key;
    if (key >= 9)
        cout << "Вы ввели неправильное число. Попробуйте еще раз ввести цифры от 1 до 8 " << endl;
    switch (key)
    {
    case 1:
        AddText(song);
        break;
    case 2:
        Delete(song);
        break;
    case 3:
        Change(song);
        break;
    case 4:
        Displaytext(song);
        break;
    case 5:

        break;
    case 6:
        DisplayNameOneAuthor(song);
        break;
    case 7:
        WordInText(song);
        break;
    case 8:
        SortAuthor(song);
        break;

    }


}