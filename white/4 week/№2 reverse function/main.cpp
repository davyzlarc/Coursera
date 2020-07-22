//Реализуйте рассказанный на лекции класс Function, позволяющий создавать, вычислять и инвертировать функцию,
//состоящую из следующих элементарных операций:
//
//прибавить вещественное число x;
//вычесть вещественное число x.
//
//При этом необходимо объявить константными все методы, которые по сути такими являются.
//
//Замечание:
//Более детальное описание задачи с подробным разбором реализации вышеуказанного класса приводится в двух предшествующих 
//видеолекциях.
//
//Пример:
//Код
//struct Image {
//double quality;
//double freshness;
//double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};
//
//Function MakeWeightFunction(const Params& params,
//    const Image& image) {
//    Function function;
//    function.AddPart('-', image.freshness * params.a + params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//    const Image& image,
//    double weight) {
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}
//
//int main() {
//    Image image = { 10, 2, 6 };
//    Params params = { 4, 2, 6 };
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 46) << endl;
//    return 0;
//}
//
//Вывод
//36
//20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }
    double Apply(double source_value) const {
        if (operation == '+') {
            return source_value + value;
        }
        else {  // operation == '-'
            return source_value - value;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        }
        else {  // operation == '-'
            operation = '+';
        }
    }
private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.push_back({ operation, value });
    }
    double Apply(double value) const {
        for (const FunctionPart& part : parts) {
            value = part.Apply(value);
        }
        return value;
    }
    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

int main()
{
	return 0;
}