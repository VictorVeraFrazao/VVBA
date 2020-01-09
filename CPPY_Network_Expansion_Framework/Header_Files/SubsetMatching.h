#ifndef SUBSETMATCHING_H
#define SUBSETMATCHING_H

#include <algorithm>
#include <vector>

using namespace std;

bool IsInSet(vector<string *> *needles, set<string *> *haystack);

bool IsInSet(vector<string *> *needles, set<string *> *haystack)
{
    if (needles->size() > haystack->size())
    {
        return false;
    }

    for (string *s : *needles)
    {
        if (!haystack->count(s))
        {
            return false;
        }
    }

    return true;
}

#endif // SUBSETMATCHING_H
