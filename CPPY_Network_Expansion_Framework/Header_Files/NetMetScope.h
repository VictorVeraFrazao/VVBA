#ifndef NETMETSCOPE_H
#define NETMETSCOPE_H

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <chrono>
#include "SubsetMatching.h"
using namespace std;

//---PROTO---

struct reaction_t
{
	vector<string *> left;
	vector<string *> right;
};

vector<reaction_t> reactions;
map<string, string> compounds;

set<string *> compound_search(set<string *> seed);
set<string *> compound_search_REV(set<string *> *seed);
set<string *> seed_append(set<string *> cmp);
set<string *> seed_append_REV(set<string *> cmp);
map<string, vector<string>> all_scopes(string *cmp);
map<string, vector<string>> all_scopes_REV(string *cmp);
vector<string> deRefStrings(set<string *> *strings);
vector<string *> translateToGloalCompounds(set<string> *input);

set<string *> seed_append_comb(string *cmp);
map<string, vector<string>> comb_scopes(string *cmp);

void println(const string s);
void drawProgress(float progress);
void finishProgress();

//---FUNCTIONS---

//Function for finding reaction compounds
set<string *> compound_search(set<string *> *seed)
{
	set<string *> result;

	for (auto reaction : reactions)
	{
		if (IsInSet(&reaction.left, seed))
		{
			vector<string *> *right = &reaction.right;

			result.insert(right->begin(), right->end());
		}
	}

	return result;
}


//Function for appending compounds to seed
set<string *> seed_append(string *cmp)
{
	int k = 1;
	unsigned int a = 0;
	unsigned int b = 1;
	set<string *> new_cmp;

	// Water should always be part of the seed compound
	set<string *> seed({cmp});

	// Check if new compounds are added
	while (a != b)
	{
		b = a;

		new_cmp = compound_search(&seed);

		seed.insert(new_cmp.begin(), new_cmp.end());
		a = seed.size();
	}

	return seed;
}

//Function for all scope calculation
map<string, vector<string>> all_scopes(vector<string *> *cmp)
{
	map<string, vector<string>> scope_map;

	float index = 0;
	float cmpLength = cmp->size();

	for (string *c : (*cmp))
	{
		set<string *> scope = seed_append(c);

		scope_map[*c] = deRefStrings(&scope);
	}

//	println("All data collected");

	return scope_map;
}

//Dereference function
vector<string> deRefStrings(set<string *> *strings)
{
	vector<string> result(strings->size());

	unsigned short i = 0;
	for (string *s : *strings)
	{
		result[i++] = *s;
	}

	return result;
}

vector<string *> translateToGloalCompounds(set<string> *input)
{
	vector<string *> result(input->size());

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

auto start = std::chrono::high_resolution_clock::now();

void println(const string s)
{
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;

	cout << "[" << (diff.count()) << "s] " << s << endl;
}

void drawProgress(float progress)
{
	int progressSize = 100;

	cout << "\r[" << std::string(progressSize * progress, '=')
		 << std::string(progressSize * (1 - progress), '-') << ']'
		 // << " (" << progress << ")"
		 << std::flush;
}

void finishProgress()
{
	drawProgress((float)1);
	cout << endl;
}


#endif // NETMETSCOPE_H
