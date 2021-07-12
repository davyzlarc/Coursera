// Условие
// В этой задаче вам надо разработать класс Matrix для представления целочисленной матрицы. Более подробно,
// класс Matrix должен иметь:
// - конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
// - конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов
//   матрицы соответственно
// - метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы
//   соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
// - константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; нумерация строк и
//   столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
// - неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
// - константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно

// Если количество строк или количество столбцов, переданное в конструктор класса Matrix или метод Reset, оказалось
// отрицательным, то должно быть выброшено стандартное исключение out_of_range.

// Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.

// Кроме того, для класса Matrix должны быть определены следующие операторы:
// - оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов (именно в этом
//   порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент первой строки
//   и второго столбца и так далее
// - оператор вывода в поток ostream; он должен выводить матрицу в том же формате, в каком её читает оператор ввода, — в
//   первой строке количество строк и столбцов, во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
// - оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер и
//   все их соответствующие элементы равны между собой, в противном случае он должен возвращать false.
// - оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой; если
//   переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.
//
// Важно! Пример не проверяет выполнение всех требований, приведённых в условии.
//
// Примечание:
// Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые матрицы равны. Сумма двух пустых матриц
// также является пустой матрицей.
//
// Пример ввода:
// 3 5
// 6 4 -1 9 8
// 12 1 2 9 -5
// -4 0 12 8 6

// 3 5
// 5 1 0 -8 23
// 14 5 -6 6 9
// 8 0 5 4 1
//
// Пример вывода:
// 3 5
// 11 5 -1 1 31
// 26 6 -4 15 4
// 4 0 17 12 7

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix()
    {
        rows = 0;
        columns = 0;
    }
    Matrix(const int &num_rows, const int &num_columns)
    {
        Check(num_rows, num_columns, false);
        SetMatrix(num_rows, num_columns);
    }
    void Reset(const int &num_rows, const int &num_columns)
    {
        Check(num_rows, num_columns, false);
        matrix.clear();
        SetMatrix(num_rows, num_columns);
    }
    int At(const int &num_rows, const int &num_columns) const
    {
        Check(num_rows, num_columns, true);
        return matrix.at(num_rows).at(num_columns);
    }
    int &At(const int &num_rows, const int &num_columns)
    {
        Check(num_rows, num_columns, true);
        return matrix.at(num_rows).at(num_columns);
    }
    int GetNumRows() const
    {
        return rows;
    }
    int GetNumColumns() const
    {
        return columns;
    }

private:
    int rows,
        columns;
    vector<vector<int>> matrix;

    void Check(const int &num_rows, const int &num_columns, const bool &compare_by_val) const
    {
        if (compare_by_val)
            if (num_rows > rows || num_columns > columns)
                throw out_of_range("");
        if (num_rows < 0 || num_columns < 0)
            throw out_of_range("");
    }

    void SetMatrix(const int &num_rows, const int &num_columns)
    {
        if (num_rows == 0 || num_columns == 0)
            rows = columns = 0;
        else
        {
            rows = num_rows;
            columns = num_columns;
        }

        for (auto i = 0; i < num_rows; i++)
        {
            matrix.push_back({});
            for (auto j = 0; j < num_columns; j++)
            {
                matrix[i].push_back(0);
            }
        }
    }
};

istream &operator>>(istream &stream, Matrix &matrix)
{
    int num_rows, num_columns;
    stream >> num_rows >> num_columns;
    Matrix result(num_rows, num_columns);

    for (auto i = 0; i < result.GetNumRows(); i++)
        for (auto j = 0; j < result.GetNumColumns(); j++)
        {
            stream >> result.At(i, j);
        }

    matrix = result;

    return stream;
}

ostream &operator<<(ostream &stream, const Matrix &matrix)
{
    stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

    for (auto i = 0; i < matrix.GetNumRows(); i++)
    {
        for (auto j = 0; j < matrix.GetNumColumns(); j++)
        {
            stream << matrix.At(i, j) << " ";
        }
        stream << endl;
    }

    return stream;
}

bool operator==(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns())
        return false;
    else
    {
        for (auto i = 0; i < lhs.GetNumRows(); i++)
            for (auto j = 0; j < lhs.GetNumColumns(); j++)
            {
                if (lhs.At(i, j) != rhs.At(i, j))
                    return false;
            }
    }
    
    return true;
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns())
        throw invalid_argument("");
    else
    {
        Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());
        for (auto i = 0; i < lhs.GetNumRows(); i++)
            for (auto j = 0; j < lhs.GetNumColumns(); j++)
            {
                result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
            }
        return result;
    }
}

int main()
{
    Matrix one;
    Matrix two;
    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}