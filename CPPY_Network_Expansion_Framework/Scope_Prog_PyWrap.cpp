#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

#include "Header_Files/NetMetScope.h"

using namespace std;
namespace py = pybind11;

/*
---Compiler command line:---
c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` Scope_Prog_PyWrap.cpp -o Scope_Prog_PyWrap`python3-config --extension-suffix`
---Compiling required before Python Script Execution---
*/

map<string, vector<string>> return_scope(set<string> *inputCompounds, map<string, map<string, set<string>>> *rea);
//map<string, vector<string>> return_scope_REV(set<string> *inputCompounds, map<string, map<string, set<string>>> *rea);

map<string, vector<string>> return_scope(set<string> *inputCompounds, map<string, map<string, set<string>>> *rea)
{
//    println("Reaction list will be optimized");
    reactions = vector<reaction_t>(rea->size());

    unsigned short i = 0;
    for (auto [_, reaction] : *rea)
    {
		//cout << _ << endl;
        reactions[i++] = {
            .left = translateToGloalCompounds(&reaction["left"]),
            .right = translateToGloalCompounds(&reaction["right"])};
    }

//    println("Reaction list was optimized successful");

    vector<string *> cmp = translateToGloalCompounds(inputCompounds);

//    println("There are " + std::to_string(compounds.size()) + " unique compunds in our reactions list");

    return all_scopes(&cmp);
}
/*
map<string, vector<string>> return_scope_REV(set<string> *inputCompounds, map<string, map<string, set<string>>> *rea)
{
    println("Reaction list will be optimized");
    reactions = vector<reaction_t>(rea->size());

    unsigned short i = 0;
    for (auto [_, reaction] : *rea)
    {
		//cout << _ << endl;
        reactions[i++] = {
            .left = translateToGloalCompounds(&reaction["left"]),
            .right = translateToGloalCompounds(&reaction["right"])};
    }

    println("Reaction list was optimized successful");

    vector<string *> cmp = translateToGloalCompounds(inputCompounds);

    println("There are " + std::to_string(compounds.size()) + " unique compunds in our reactions list");

    return all_scopes_REV(&cmp);
}*/

PYBIND11_MODULE(Scope_Prog_PyWrap, m)
{
    m.def("return_scope", &return_scope);
 //   m.def("return_scope_REV", &return_scope_REV);
}
