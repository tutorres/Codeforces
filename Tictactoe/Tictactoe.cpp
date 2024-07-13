#include <iostream>
using namespace std;
bool ganhou(char m[3][3], char caracter);

void lermatriz(char m[3][3]) {
  for (int l = 0; l < 3; l++) {
    for (int c = 0; c < 3; c++) {
      cin >> m[l][c];
    }
  }
}

bool Erro_limiteDeCaracter(char mat[3][3]) {
  int acc1 = 0, acc2 = 0;
  bool result = false;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (mat[i][j] == 'X') {
        acc1++;
      }
      if (mat[i][j] == '0') {
        acc2++;
      }
    }
  }
  if ((acc1 > 5 && acc2 > 4) || (acc1 - acc2 > 1) || acc2 > acc1 ||
      (ganhou(mat, '0')&& acc2 != acc1)||ganhou(mat, 'X')&& acc2 == acc1) {
    result = true;
  }
  return result;
}
bool verificarLinhas(char caracter, char m[3][3]) {
  if ((m[0][0] == caracter && m[0][1] == caracter && m[0][2] == caracter) ||
      (m[1][0] == caracter && m[1][1] == caracter && m[1][2] == caracter) ||
      (m[2][0] == caracter && m[2][1] == caracter && m[2][2] == caracter)) {
    return true;
  } else {
    return false;
  }
}
bool verificarColunas(char caracter, char m[3][3]) {
  if ((m[0][0] == caracter && m[1][0] == caracter && m[2][0] == caracter) ||
      (m[0][1] == caracter && m[1][1] == caracter && m[2][1] == caracter) ||
      (m[0][2] == caracter && m[1][2] == caracter && m[2][2] == caracter)) {
    return true;
  } else {
    return false;
  }
}
bool verficarDiagonal(char caracter, char m[3][3]) {
  if ((m[0][0] == caracter && m[1][1] == caracter && m[2][2] == caracter) ||
      (m[2][0] == caracter && m[1][1] == caracter && m[0][2] == caracter)) {
    return true;
  } else {
    return false;
  }
}

bool ganhou(char m[3][3], char caracter) {
  if (verificarLinhas(caracter, m) || verificarColunas(caracter, m) ||
      verficarDiagonal(caracter, m)) {
    return true;
  } else {
    return false;
  }
}
bool maisdeumganhou(char matriz[3][3]) {
  if (ganhou(matriz, 'X') && ganhou(matriz, '0')) {
    return true;
  } else {
    return false;
  }
}

bool legal(char matriz[3][3]) {
  bool result = true;
  if (Erro_limiteDeCaracter(matriz) || maisdeumganhou(matriz)) {
    result = false;
  }
  return result;
}
string proxjogador(char mat[3][3]) {
  int acc1 = 0, acc2 = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (mat[i][j] == 'X') {
        acc1++;
      }
      if (mat[i][j] == '0') {
        acc2++;
      }
    }
  }
  if (acc1 == acc2 || acc1 == 0 && acc2 == 0) {
    return "first";
  } else {
    return "second";
  }
}
bool acabou(char matriz[3][3]) {
  int acc1 = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      if (matriz[i][j] == '.') {
        acc1++;
      }
    }
  }
  if (acc1 > 0) {
    return false;
  } else {
    return true;
  }
}

int main() {
  char matriz[3][3];
  lermatriz(matriz);
  if (!legal(matriz)) {
    cout << "illegal" << endl;
  } else {
    if (ganhou(matriz, 'X')) {
      cout << "the first player won" << endl;
    } else if (ganhou(matriz, '0')) {
      cout << "the second player won" << endl;
    } else if (!acabou(matriz)) {
      string prox = proxjogador(matriz);
      cout << prox << endl;
    } else {
      cout << "draw" << endl;
    }
  }
}