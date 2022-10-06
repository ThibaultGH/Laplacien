#include <iostream>
#include <gsl/gsl_cblas.h>

using namespace std;

void cblas_sscal(const int N, const float alpha, float *x, const int incx);
   
int main(int argc, char *argv[])
{
  int N = 3;
  float SA = 2.1;
  float SX[N];
  int INCX = 1;

  for (int i1 = 0; i1 < N; ++i1) {
    SX[i1] = i1;
  }


  cout << "Before : " << endl;
  
  for (int i2 = 0; i2 < N; ++i2) {
    cout << SX[i2] << " ";
  }
  cout << endl;


  cblas_sscal(N,SA,SX,INCX);

  cout << "After : " << endl;
  
  for (int i3 = 0; i3 < N; ++i3) {
    cout << SX[i3] << " ";
  }
  cout << endl;
  
  cout << "Hello world !" << endl;
  
  return 0;
}
