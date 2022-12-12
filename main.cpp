#include <iostream>
using namespace std;
int main()
{
    int n, i, j, k, l, t;
    bool poprawnosc;
	int sudoku[9][9], bufor[9];
	cin >> n;
	while (n--)
	{
		poprawnosc = true;
		for (i = 0; i < 9; ++i)
			for (j = 0; j < 9; ++j)
			{
				cin >> sudoku[i][j]; // Sprawdzenie poprawnosci zakresu
				if (sudoku[i][j] > 9 || sudoku[i][j] < 0)
					poprawnosc = false;
			}
		if (poprawnosc) // Sprawdzenie powtarzania w wierszu
			for (i = 0; i < 9; ++i)
				for (j = 0; j < 9; ++j)
					for (k = j + 1; k < 9; ++k)
						if (sudoku[i][j] == sudoku[i][k])
							poprawnosc = false;
		if (poprawnosc)  // Sprawdzenie powtarzania w kolumnie
			for (j = 0; j < 9; ++j)
				for (i = 0; i < 9; ++i)
					for (k = i + 1; k < 9; ++k)
						if (sudoku[i][j] == sudoku[k][j])
							poprawnosc = false;
		if (poprawnosc) // Sprawdzenie powtarzania w bloku 3x3
			for (k = 0; k < 9; k += 3)
				for (l = 0; l < 9; l += 3) // Konwersja bloku do tablicy
				{
					t = 0;
					for (i = 0; i < 3; ++i)
						for (j = 0; j < 3; ++j)
							bufor[t++] = sudoku[k + i][l + j];
					for (i = 0; i < 9; ++i) // Sprawdzenie powtarzania w tablicy
						for (j = i + 1; j < 9; ++j)
							if (bufor[i] == bufor[j])
								poprawnosc = false;
				}
		if (poprawnosc)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
	return 0;
}
