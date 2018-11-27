#include <iostream>
#include <python2.7/Python.h>
#include <stdlib.h>

using namespace std;

int main() {
	// Set PYTHONPATH TO working directory
   setenv("PYTHONPATH",".",1);

   PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *pArgs, *presult;


   // Initialize the Python Interpreter
   Py_Initialize();


   // Build the name object
   pName = PyString_FromString((char*)"script");

   // Load the module object
   pModule = PyImport_Import(pName);

   // pDict is a borrowed reference 
   pDict = PyModule_GetDict(pModule);


   // pFunc is also a borrowed reference 
   pFunc = PyDict_GetItemString(pDict, (char*)"printTest");
   
   // make python tuple
   pArgs = PyTuple_New(2);
   pValue = PyInt_FromLong(2);
   
   PyTuple_SetItem(pArgs, 0, pValue);
   PyTuple_SetItem(pArgs, 1, pValue);

   if (PyCallable_Check(pFunc))
   {
	   pValue=Py_BuildValue("ss","some1","some2");
       PyErr_Print();
       printf("Let's give this a shot!\n");
       presult=PyObject_CallObject(pFunc,pValue);
       PyErr_Print();
   } else 
   {
       PyErr_Print();
   }
   printf("Result is %d\n",PyInt_AsLong(presult));
   Py_DECREF(pValue);

   // Clean up
   Py_DECREF(pModule);
   Py_DECREF(pName);

   // Finish the Python Interpreter
   Py_Finalize();


   return 0;	
}