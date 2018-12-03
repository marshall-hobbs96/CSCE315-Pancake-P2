#include <iostream>
#include <python2.7/Python.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
	// // Set PYTHONPATH TO working directory
    setenv("PYTHONPATH",".",1);

    PyObject *pName,*pModule, *pDict, *pFunc1, *pFunc2, *pFunc3, *pValue, *presult, *pValue2, *pValue3, *presult2, *presult3;
	int ND, numOfPancakes, difficulty;
	string n;

    // Initialize the Python Interpreter
    Py_Initialize();


    // Build the name object
    pName = PyString_FromString((char*)"functions");

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);


    // pFunc is also a borrowed reference 
    pFunc1 = PyDict_GetItemString(pDict, (char*)"splash");
	pFunc2 = PyDict_GetItemString(pDict, (char*)"drawDifficultyWindow");
	pFunc3 = PyDict_GetItemString(pDict, (char*)"drawOrderWindow");
	
    if (PyCallable_Check(pFunc1))
    {
	    int value = 123;
        //pValue=Py_BuildValue("i",value);
		PyErr_Print();
        printf("Loading . . .\n");
		
        presult = PyObject_CallObject(pFunc1,NULL);
		pValue=Py_BuildValue("(O)",presult);
		
		presult2 = PyObject_CallObject(pFunc2,pValue);
		
		
		ND = PyInt_AsLong(presult2);
		difficulty = ND % 10;
		ND -= difficulty;
		numOfPancakes = ND / 10;
		n = to_string(numOfPancakes);
	
		pValue2=Py_BuildValue("(Os)",presult,n.c_str());
		presult3 = PyObject_CallObject(pFunc3,pValue2);
		// pValue3=Py_BuildValue("(O)",presult3);
		
        PyErr_Print();
    } else 
    {
       // PyErr_Print();
    }
    
	
	cout << "numOfPancakes: " << numOfPancakes << endl;
	cout << "difficulty: " << difficulty << endl;
	
	
	// printf("Result is %lu\n",PyInt_AsLong(presult2));
    // Py_DECREF(pValue);

    // Clean up
    Py_DECREF(pModule);
    Py_DECREF(pName);

    // Finish the Python Interpreter
    Py_Finalize();

	

   return 0;	
}