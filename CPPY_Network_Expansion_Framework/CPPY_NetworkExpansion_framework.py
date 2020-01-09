#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  9 14:41:36 2020

@author: student
"""
import Scope_Prog_PyWrap
import copy
# %%
# Exemplary set:
comp = {'met1', 'met2', 'met3', 'met4'}
rea = {'rea1':{'met1':-1,'met2':1},
       'rea2':{'met2':-1,'met3':1},
       'rea3':{'met3':-1,'met4':1}
       }
# %%
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
        sub_dict.update({'right': copy.deepcopy(right)})
        rea_dict.update({key: copy.deepcopy(sub_dict)})
        left.clear()
        right.clear()
    return rea_dict
     
red_rea = reaction_conversion(rea)

# %%
print(Scope_Prog_PyWrap.return_scope(comp, red_rea))