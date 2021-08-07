// Часть 2
// Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл output.txt .
// Точно так же гарантируется, что содержимое файла input.txt заканчивается переводом строки. 
//
// Пример
//
// input.txt:
// Keep calm
// and
// learn C++
//
// output.txt:
// Keep calm
// and
// learn C++

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main_()
{
    ifstream input("input.txt");
    ofstream output("output.txt"); 
    if (input.is_open()&&output.is_open())
    {
        string line;
        while (getline(input, line))
            output << line << endl;
    }
    return 0;
}