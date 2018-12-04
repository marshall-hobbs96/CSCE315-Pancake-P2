#include <iostream>
#include <fstream>
#include <python2.7/Python.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "Game.h"

using namespace std;

int main() {
	// // Set PYTHONPATH TO working directory
    setenv("PYTHONPATH",".",1);

    PyObject *pName,*pModule, *pDict, *pFunc1, *pFunc2, *pFunc3, *pValue2;
	int ND, numOfPancakes, difficulty;
	string n, s;

    // Initialize the Python Interpreter
    Py_Initialize();


    // Build the name object
    pName = PyString_FromString((char*)"functions");

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);


    // pFunc is also a borrowed reference 
    pFunc1 = PyDict_GetItemString(pDict, (char*)"start");
	pFunc2 = PyDict_GetItemString(pDict, (char*)"drawDifficultyWindow");
	pFunc3 = PyDict_GetItemString(pDict, (char*)"drawOrderWindow");

	
    if (PyCallable_Check(pFunc1))
    {
		PyErr_Print();
        printf("Loading . . .\n");
		
		PyObject_CallObject(pFunc1,NULL);
		PyObject_CallObject(pFunc2,NULL);
		
		string line1;
		ifstream myfile ("param.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line1) )
		{
		ND = stoi(line1);
		}
		myfile.close();
	}
  
		difficulty = ND % 10;
		ND -= difficulty;
		numOfPancakes = ND / 10;
		n = to_string(numOfPancakes);
	
		pValue2=Py_BuildValue("(s)",n.c_str());
		PyObject_CallObject(pFunc3,pValue2);
		
        PyErr_Print();
    } else 
    {
       // PyErr_Print();
    }
	string line;
    ifstream myfile ("stack.txt");
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			s = line;
		}
		myfile.close();
	}

	
	
	string command = "python2.7 turn_example.py ";
	command = command + s;
	system(command.c_str());
  
    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

	

   return 0;	
}