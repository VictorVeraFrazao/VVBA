#ifndef WS_TMP_H
#define WS_TMP_H

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

std::string water = "WATER";            //String var for inclusion of water into the seed
std::string *w_ptr;

struct compound_scope
{
    std::set<std::string> comps;
    std::set<std::string> reacs;
};

struct reaction_t                       //structure for reaction
{
    std::string rname;                  //reaction name
    std::vector<std::string *> left;    //reaction substrate vector
    std::vector<std::string *> right;   //reaction product vector
};

std::vector<reaction_t> reactions;      //list of network reactions
std::map<std::string, std::string> compounds;
bool Rev;

//---PROTOTYPES---
std::map<std::string, std::set<std::string>> _scope(std::vector<std::string *> seed); //Network Expansion Algorithm
bool IsInSet(std::vector<std::string *> *needles, std::set<std::string *> *haystack); 
std::vector<std::string *> ToPointerVector(std::set<std::string> *input);
std::set<std::string> deRefSet(std::set<std::string *> *strings);
std::set<std::string *> convertToSet(std::vector<std::string *> v);

//---FUNCTION CODES---
std::map<std::string, std::set<std::string>> _scope(std::vector<std::string *> seed)
{
    std::map<std::string, std::set<std::string>> sc_map;
    std::set<std::string *> reas;

    std::set<std::string *> cmps = convertToSet(seed);
    unsigned int a = 0, b = 1;
    w_ptr = &water;
    cmps.insert(w_ptr);  //including water
    while (a != b)
    {
        b = a;
        for (auto reaction : reactions)
        {
            if (IsInSet(&reaction.left, &cmps))
            {
                std::vector<std::string *> *right = &reaction.right;
                cmps.insert(right->begin(), right->end());
                reas.insert(&reaction.rname);
            }

            if(Rev == true && IsInSet(&reaction.right, &cmps))
            {
                std::vector<std::string *> *left = &reaction.left;
                cmps.insert(left->begin(), left->end());
                reas.insert(&reaction.rname);
            }
        }
        a = cmps.size();
    }

    
    sc_map.insert({"reactions", deRefSet(&reas)});
    sc_map.insert({"compounds", deRefSet(&cmps)});
    return sc_map;
}

bool IsInSet(std::vector<std::string *> *needles, std::set<std::string *> *haystack)
{
/*
Searching the "needles" in the "haystack".
Out: TRUE if every needle element is in haystack, FALSE if otherwise
*/

    if (needles->size() > haystack->size())
    {
        return false;
    }

    for (std::string *s : *needles)
    {
        if (!haystack->count(s))
        {
            return false;
        }
    }

    return true;
}

std::vector<std::string *> ToPointerVector(std::set<std::string> *input)
{
	std::vector<std::string *> result(input->size());

	unsigned short i = 0;
	for (auto c : *input)
	{
		if (!compounds.count(c))
		{
			compounds[c] = c;
		}

		result[i++] = &compounds[c];
	}

	return result;
}

std::set<std::string> deRefSet(std::set<std::string *> *strings)
{
	std::set<std::string> result;

	for (std::string *s : *strings)
	{
		result.insert(*s);
	}

	return result;
}

std::set<std::string *> convertToSet(std::vector<std::string *> v) 
{ 
    // Declaring the  set 
    std::set<std::string *> s; 
  
    // Traverse the Vector 
    for (std::string * x : v) { 
  
        // Insert each element 
        // into the Set 
        s.insert(x); 
    } 
  
    // Return the resultant Set 
    return s; 
} 
#endif //WS_TMP_H