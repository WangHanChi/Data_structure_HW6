// 107303528_HW6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct rgb {
    string color;
    vector<int> rgb_value;
};

int main()
{
    string line;
    istringstream istr;
    
    ifstream infile("rgb.txt");
    vector<rgb> foo;
    
    rgb name;

    do {
        cout << "> ";
        getline(cin, line);
        istr.str(line);

    } while (1);
}

