#include <stdio.h>
#include <array>
#include <algorithm>
#include <iterator>
#include <omp.h>
#include <fstream>
#include <iostream>

using namespace std;

float delta_x = 0.05;
double L = 4.0;
int N = (int)(L / delta_x) + 1;

void writeToFile(double *x, double *u, string filename)
{
  ofstream myfile;
  myfile.open(filename + ".dat");

  for (int i = 0; i < N; i++)
  {
    myfile << x[i] << " ";
  }
  myfile << endl;
  for (int i = 0; i < N; i++)
  {
    myfile << u[i] << " ";
  }
  myfile << endl;

  myfile.close();
}

double flux(double u)
{
  return 0.5 * u * u;
}

void initVals(double *x, double *u)
{
  for (int i = 0; i < N; i++)
  {
    double tempx = (L / (N - 1)) * i;
    x[i] = tempx;
    if (tempx < 2.0)
    {
      u[i] = 1.0;
    }
    else
    {
      u[i] = 0.0;
    }
  }
}

void Lax(double *u, double t_max, double deltat)
{
  double F[N];

  double u_copy[N];
  copy(u, u + N, u_copy);

  int N_T = (int)(t_max / deltat);
  cout << N_T << " " << t_max << " " << deltat << " " << endl;
  for (int phi = 0; phi < N_T; phi++)
  {

    for (int k = 0; k < N; k++)
    {
      F[k] = flux(u[k]);
    }

    for (int j = 1; j < N - 1; j++)
    {
      u_copy[j] = 0.5 * (u[j + 1] + u[j - 1]);
      u_copy[j] -= (0.5 * deltat / delta_x) * (F[j + 1] - F[j - 1]);
    }
    copy(u_copy, u_copy + N, u);
  }
}

main(int argc, char const *argv[])
{
  cout << N << endl;
  // init arrays
  double x[N];
  double u[N];

  double t_max_values = 2.0;

  initVals(x, u);
  Lax(u, t_max_values, 0.5 * delta_x);
  writeToFile(x, u, "advecSerial");

  return 0;
}
