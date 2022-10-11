#include <iostream>
#include <fstream>
#include <gsl/gsl_cblas.h>
#include <mesh.hpp>

using namespace std;

/* An example of how to declare a BLAS function in this project
 void cblas_sscal(const int N, const float alpha, float *x, const int incx);

 An example of how to declare a LAPACK function in this project
 extern "C" {
     extern int dgeev_(char*,char*,int*,double*,int*,double*, double*, double*, int*, double*, int*, double*, int*, int*);
     }
*/


int main(int argc, char *argv[])
{

  int nb_corners = 0;
  int* corners;
  int nb_border_edges;
  int* border_edges;
  int nb_nodes;
  int nb_elements;
  float* nodes;
  int* elements;

  char filename[100] = "/home/tcimic/Projects/Laplacien/mesh/square.msh";

  mesh Th(filename);
  
  // read_mesh_file(nb_corners, corners, nb_border_edges, border_edges, nb_nodes, nb_elements, nodes, elements, filename);

  /* 
   for (int i0 = 0; i0 < nb_elements; ++i0) {
    for (int i1 = 0; i1 < 3; ++i1) {
      cout << elements[i0*3+i1] << " ";
    }
    cout << endl; 
  } */



  // deallocate

  // delete corners;
  // delete border_edges;
  // delete nodes;
  // delete elements; 
  

  return 0;
}
