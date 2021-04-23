#include <iostream>

using namespace std;

int **puntero_matriz,nFilas,nCol,Cont = 1;


void CrearDatos(int matriz[]){
  nFilas = 8;
  nCol = 2;
  int *ptr_matriz;
  ptr_matriz=matriz;

  puntero_matriz = new int*[nFilas];
  for(int i = 0;i<nFilas;i++){
    puntero_matriz[i] = new int[nCol];
  }


  for(int i = 0;i<nFilas;i++,Cont = Cont*2){

      *(*(puntero_matriz+i)+0) = *ptr_matriz++;
      *(*(puntero_matriz+i)+1) = Cont;

  }
}

void mostrarMatriz(int **puntero, int nFilas, int nCol){
 for(int i=0;i<nFilas;i++){
     cout << *(*(puntero_matriz+i)+0)<<" ";
     cout << *(*(puntero_matriz+i)+1)<<" ";

  }
  cout<<endl;

}
int main()
{
    int Numbers[8]={2,4,8,16,64,32,128,255};

    CrearDatos(Numbers);
    mostrarMatriz(puntero_matriz,nFilas,nCol);
    return 0;
}

