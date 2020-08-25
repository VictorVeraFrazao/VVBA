# VVBA
Network Expansion Algorithm application (Python3/C++11) and supplementary data (hierarchical clustering) for the Bachelor Thesis: "Analysis And Comparison Of Biochemical Potentials Of Metabolites In Global Metabolic Networks Using The Network Expansion Algorithm" by Victor Vera Frazao (2020).

## General information
CURRENTLY WORK IN PROGRESS. CHECK [MASTER](https://github.com/VictorVeraFrazao/VVBA/tree/master) BRANCH FOR LAST FUNCTIONAL CODE. CHECK THE [WORKSPACE](https://github.com/VictorVeraFrazao/VVBA/tree/workspace) BRANCH FOR PROGRESS. PLEASE NOTE THAT REFERENCES ARE NOT STATED YET, SO NO GUARANTEE FOR COMPLETENESS OR ACCURACY IS GIVEN.

## Network Expansion Framework project for Python and C++ (CPPY Network Expansion Framework)
## 1. Release notes
The CPPY Network Expansion Framework will be released alongside the MOPED (Metabolic Object-oriented Python Modelling Environment?). Current version: 0.1.0.
## 2. Description
This implementation of the Network Expansion Algorithm deals with the elapsed time issues on large-scale or global metabolic networks. Calculating every biosynthetical potential (scope) of every single compound or in combination with other ones (like cofactors) reveals largely increased runtimes over durations of hours, depending on the used hardware. Increased runtimes slow down analyzing and modelling processes and errors, i.e. due to erroneous presets of the analysis, are more devastating as repeating the analysis process is far more punishing and can be a heavy obstacle for the programmer's patience and motivation. As more performant hardware is not available at all times, a code that significantly reduces the elapsed time for large-scaled network analyses was successfully implemented. For this it was decided to transfer the main process to a C++ code instead of Python3, although the program is still accessible via Python3, so the resulting data is prepared for any subsequent analysis, as Python3, alongside with scientific data processing distributions like Anaconda, is far more feasible for easy data analysis than it is C++. However, the program is restricted in some functions and is not sufficiently handy for an alltime use without deeper instructions by the developer. Thus, we are currently working on modifying the code to hopefully include it in the [MOPED](https://pypi.org/project/moped/ "MOPED Homepage") module, developed by Nima Saadat and Marvin van Aalst. Furthermore we are aiming to extend the functionality and increase the performance.
## 3. Prerequisites
1. [Pybind11](https://github.com/pybind/pybind11 "Pybind11 Git")
2. C++ (11 or newer)
3. Python3 (3.6 or newer)
### Further recommended:
- Anaconda Python-Distribution

### Theoretically required:
- [MetaCyc](https://metacyc.org/ "MetaCyc Homepage") flatfiles
- Flatfile parser
The flatfile parser is part of the MOPED module and it is not planned to publish it separately. As we cannot provide any parser to work with the current version of the code the program execution file includes a manually implemented example network for testing, thus neither flatfiles nor parser have to be accuired.
## 4. Code documentation
### 4.1 Compiling
Compiling was successfully executed on UNIX systems (Ubuntu 16.04).
Compiler: GNU g++ 7.4.0
The compiling might be accompanied by some warnings. These warnings come due to C++ version interferences but should not impact the compiling process.
### 4.2 Program execution
Main program accessible via [Python3 Script](https://github.com/VictorVeraFrazao/VVBA/blob/workspace/CPPY_Network_Expansion_Framework/CPPY_NetworkExpansion_framework.py) execution. Execution on iPython shell console is recommended. The usage of Python IDEs (e.g. Spyder) might reduce the program's performance.
### 4.3 Output
Python Script output:
```{'met1': ['met1', 'met2', 'met3', 'met4'], 'met2': ['met2', 'met3', 'met4'], 'met3': ['met3', 'met4'], 'met4': ['met4']}```
## 5. License
CPPY is licensed under GPL 3.0. For further license information please look up the [license](https://github.com/VictorVeraFrazao/VVBA/blob/workspace/LICENSE "License") document in this repository.

