//
// Created by pchmelo on 08-03-2024.
//

#include "functions.h"
#include "sstream"
#include "fstream"

using  namespace std;

void functions::file_ouput(std::vector<std::pair<std::string, int>> vec_lines) {
    string dir_file = "../src/Project1DataSetSmall/output.txt";
    ofstream fout(dir_file,ios::out | ios::trunc);

    fout << "City_code,value\n";

    auto it = vec_lines.begin();

    for(int i = 0; i < vec_lines.size(); i++){
        fout << it->first << "," << it->second << "\n";
    }

    fout.close();
}