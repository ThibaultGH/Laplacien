// Include from the standard C++ library
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// My own includes
#include <gsl/gsl_cblas.h>
#include <mesh.hpp>
#include "OperatorBuilds/operatorbuilds.hpp"


using namespace std;

/* An example of how to declare a BLAS function in this project
 void cblas_sscal(const int N, const float alpha, float *x, const int incx);

 An example of how to declare a LAPACK function in this project
 extern "C" {
     extern int dgeev_(char*,char*,int*,double*,int*,double*, double*, double*, int*, double*, int*, double*, int*, int*);
     }
*/

double FormElem(const double *coord, const int ref){
  switch (ref) {
  case 0: {
    return 1 - coord[0] - coord[1];
  }
  case 1: {
    return coord[0];
  }
  case 2: {
    return coord[1];
  }
  }
}

int main(int argc, char *argv[])
{

  char filename[100] = "/home/tcimic/Projects/Laplacien/GMSHmesh/mesh/square.msh";

  mesh Th(filename);

  // cout << Th.NbTriangle() << endl;

  double coord[2];
  coord[0] = 0;
  coord[1] = 0.25;

  // printf("%f\n", FormElem(coord,1));

  double *Mass;

  Mass = MassAssem(Th.Triangle(), Th.Nodes(), Th.NbTriangle(), Th.NbNodes());



  // deallocate

  return 0;
}
