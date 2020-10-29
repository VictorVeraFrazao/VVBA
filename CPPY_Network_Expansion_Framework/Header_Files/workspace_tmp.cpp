#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <map>

#include "workspace_tmp.h"

namespace py = pybind11;

std::map<std::string, std::set<std::string>> calc_scope(std::set<std::string> *sc_seed, std::map<std::string, std::map<std::string, std::set<std::string>>> *rea, bool reversible);

std::map<std::string, std::set<std::string>> calc_scope(std::set<std::string> *sc_seed, std::map<std::string, std::map<std::string, std::set<std::string>>> *rea, bool reversible)
{
    reactions = std::vector<reaction_t>(rea->size());
    Rev = reversible;

    unsigned short i = 0;
    for (auto it: *rea)
    {
        reactions[i++] = {
            .rname = it.first,
            .left = ToPointerVector(&it.second["left"]),
            .right = ToPointerVector(&it.second["right"])};
    }

    std::vector<std::string *> cmp = ToPointerVector(sc_seed);
    return _scope(cmp);
}

PYBIND11_MODULE(NetworkExpansion, m)
{
    m.def("single_scope", &calc_scope);
}