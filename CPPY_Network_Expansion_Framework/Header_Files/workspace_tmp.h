#ifndef WS_TMP_H
#define WS_TMP_H

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

//ALIASES, TEMPLATES, STRUCTURES
using strSet = std::set<std::string>;
using pstrSet = std::set<std::string*>;
using strVec = std::vector<std::string>;
using pstrVec = std::vector<std::string*>;

std::string water = "WATER";            //String var for inclusion of water into the seed
std::string *w_ptr;

struct compound_scope
{
    strSet comps;
    strSet reacs;
};

struct reaction_t                       //structure for reaction
{
    std::string rname;                  //reaction name
    pstrVec left;    //reaction substrate vector
    pstrVec right;   //reaction product vector
};

std::vector<reaction_t> reactions;      //list of network reactions
std::map<std::string, std::string> compounds;
bool Rev;

//---PROTOTYPES---
std::map<std::string, strSet> _scope(pstrVec seed); //Network Expansion Algorithm
bool IsInSet(pstrVec *needles, pstrSet *haystack); 
pstrVec ToPointerVector(strSet *input);
strSet deRefSet(pstrSet *strings);
pstrSet convertToSet(pstrVec v);

//---FUNCTION CODES---
std::map<std::string, strSet> _scope(pstrVec seed)
{
    std::map<std::string, strSet> sc_map;
    strSet reas;

    pstrSet cmps = convertToSet(seed);
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
                pstrVec *right = &reaction.right;
                cmps.insert(right->begin(), right->end());
                reas.insert(reaction.rname);
            }

            if(Rev == true && IsInSet(&reaction.right, &cmps))
            {
                pstrVec *left = &reaction.left;
                cmps.insert(left->begin(), left->end());
                reas.insert(reaction.rname);
            }
        }
        a = cmps.size();
    }

    
    sc_map.insert({"reactions", reas});
    sc_map.insert({"compounds", deRefSet(&cmps)});
    return sc_map;
}

bool IsInSet(pstrVec *needles, pstrSet *haystack)
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

pstrVec ToPointerVector(strSet *input)
{
	pstrVec result(input->size());

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

strSet deRefSet(pstrSet *strings)
{
	strSet result;

	for (std::string *s : *strings)
	{
		result.insert(*s);
	}

	return result;
}

pstrSet convertToSet(pstrVec v) 
{ 
    // Declaring the  set 
    pstrSet s; 
  
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