#include <iostream>
#include "operatorbuilds.hpp"

using namespace std;

double* MassAssem(const int* Triangles, const float* Nodes,const int NbTriangles, const int NbNodes){

  double *Mass = (double *) malloc(sizeof(double)*NbNodes*NbNodes);

  return Mass;
}
