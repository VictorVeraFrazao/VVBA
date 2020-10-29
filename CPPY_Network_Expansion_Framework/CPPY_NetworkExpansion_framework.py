#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  9 14:41:36 2020

@author: student
"""


import copy
import sys
import os


# Compiler Function (ALPHA)
def CBuild():
    system = sys.platform
	
	# Linux compiler
    if system == 'linux':
        os.chdir('/home/student/Documents/VVBA/CPPY_Network_Expansion_Framework/Header_Files')
        os.system('c++ -O3 -w -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` workspace_tmp.cpp -o NetworkExpansion`python3-config --extension-suffix`')
        print("Compiling successful")

### FUTURE IMPLEMENTATION FOR OTHER SYSTEMS THAN LINUX; COMPILERS UNKNOWN OR NOT TESTED YET
## WINDOWS:
#	elif system == 'win32':
#		os.system('(???)')
## MacOS:
#   elif system == 'darwin':
#		os.system('c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup `python3 -m pybind11 --includes` Scope_Prog_PyWrap.cpp -o Scope_Prog_PyWrap`python3-config --extension-suffix`
    else:
        print("Compiling failed")
        sys.exit()

# Exemplary network data:
comp = ['met1', 'met2', 'met3', 'met4'] #single compound seeds
rea = {'rea1':{'met1':-1,'met2':1},
       'rea2':{'met2':-1,'met3':1},
       'rea3':{'met3':-1,'met4':1}
       } # stoichiometry

# Modulation of network data; currently required to modulate input data for C++ bind
def reaction_conversion(reactions):
    left = set()
    right = set()
    rea_dict = {}
    sub_dict = {}
    for key in reactions:
        stoich = reactions[key]
        for key2 in stoich:
            if stoich[key2] < 0:
                left.add(key2)
            if stoich[key2] > 0:
                right.add(key2)
        sub_dict.update({'left': copy.deepcopy(left)})
        sub_dict.update({'right':copy.deepcopy(right)})
        rea_dict.update({key: copy.deepcopy(sub_dict)})
        left.clear()
        right.clear()
    return rea_dict

red_rea = reaction_conversion(rea)

# Program execution
CBuild()

# %%
import NetworkExpansion as NE

for i in comp:
    print(NE.single_scope({i}, red_rea, False))
#import Scope_Prog_PyWrap
#print(Scope_Prog_PyWrap.translate_reactions(red_rea))
#print(Scope_Prog_PyWrap.return_scope(comp, red_rea)) #Output: single scopes for every input seed