#include <iostream>
#include <cmath>

using namespace std;

int wholeBinToDecimal(string binary) // целая из двоичной в десятичную
{
    int decimal = 0;
    int len = binary.length();
    for (int i = 0; i < len; ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }
    return decimal;
}

string wholeDecimalToHex(int decimal) // целая из десятичной в шестнадцатиричную
{
    if (decimal == 0)
        return "0";

    string hex = "";
    char hexChars[] = "0123456789ABCDEF";

    while (decimal > 0) {
        hex = hexChars[decimal % 16] + hex; // остаток
        decimal /= 16;
    }
    return hex;
}

double fractionalBinToDecimal(string binaryString) // дробная из двоичной в десятичную
{
    double decimal = 0;
    int len = binaryString.length();
    for (int i = 0; i < len; ++i) {
        if (binaryString[i] == '1') {
            decimal += pow(2, -(i + 1));
        }
    }
    return decimal;
}

string fractionalDecimalToHex(double decimal) // дробная из десятичной в шестнадцатеричной
{
    string fractionalHex;
    while (decimal > 0) {
        decimal *= 16;
        int integerPart = (int)decimal;
        if (integerPart < 10) {
            fractionalHex += (integerPart + '0');
        } else {
            fractionalHex += (integerPart - 10 + 'A');
        }
        decimal -= integerPart;
    }
    return fractionalHex;
}

int main()
{
    string binaryString;
    cin >> binaryString;

    int dotPosition = binaryString.find('.'); // позиция точки

    string wholePart = binaryString.substr(0, dotPosition); // целая часть
    string fractionalPart = binaryString.substr(dotPosition + 1); // дробная часть

    int wholeDecimal = wholeBinToDecimal(wholePart); // целая часть в десятичной
    string wholeHex = wholeDecimalToHex(wholeDecimal); // целая часть в шестнадцатеричной

    double fractionalDecimal = fractionalBinToDecimal(fractionalPart); // дробная часть в десятичной
    string fractionalHex = fractionalDecimalToHex(fractionalDecimal); // дробная часть в шестнадцатеричной

    cout << wholeHex << '.' << fractionalHex;
    return 0;
}
