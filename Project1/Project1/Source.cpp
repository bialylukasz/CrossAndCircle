#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Point
{
public:
	int x, y;
};
void czyszczenie_planszy(char plansza[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			plansza[i][j] = ' ';
		}
	}
}
void wyswietlanie(char plansza[3][3])
{
	cout << "  1|2|3\n\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 3; j++)
		{
			cout << plansza[i][j];
			if (j < 2)cout << "|";
		}
		cout << endl;
	}
}
void Postaw_znak(int gracz, char plansza[3][3])
{
	Point wspolrzedne;
	cout << "Podaj wspolrzedne XY" << endl;
	cin >> wspolrzedne.x >> wspolrzedne.y;
	if (plansza[wspolrzedne.x - 1][wspolrzedne.y - 1] == ' ')
	{
		switch (gracz)
		{
		case 1:
			plansza[wspolrzedne.x - 1][wspolrzedne.y - 1] = 'O';
			break;
		case 2:
			plansza[wspolrzedne.x - 1][wspolrzedne.y - 1] = 'X';
			break;
		}
	}
	else Postaw_znak(gracz, plansza);
}
void Ruch_komputera(char plansza[3][3], int numer_ruchu)
{
	int x, y;
	do
	{
		x = rand() % 3;
		y = rand() % 3;
	} while (plansza[x][y] != ' ' && numer_ruchu != 9);
	plansza[x][y] = 'X';
}
bool Sprawdz_wygrana(char plansza[3][3], char gracz)
{
	bool flag = false;
	for (int i = 0; i < 3; i++)
	{
		if (plansza[i][0] == gracz && plansza[i][1] == gracz && plansza[i][2] == gracz) flag = true;
		if (plansza[0][i] == gracz && plansza[1][i] == gracz && plansza[2][i] == gracz) flag = true;
	}
	if (plansza[0][0] == gracz && plansza[1][1] == gracz && plansza[2][2] == gracz) flag = true;
	else if (plansza[2][0] == gracz && plansza[1][1] == gracz && plansza[0][2] == gracz) flag = true;
	if (flag == true && gracz == 'O')
	{
		cout << "Wygral gracz\n";
	}
	else if (flag == true && gracz == 'X')
	{
		cout << "Wygral komputer\n";
	}
	return flag;
}
int main() {
	srand(time(NULL));
	char flag;
	int licznik_ruchow = 0;
	char plansza[3][3];
	czyszczenie_planszy(plansza);
	wyswietlanie(plansza);
	while (licznik_ruchow != 9)
	{
		Postaw_znak(1, plansza);
		licznik_ruchow++;

		if (licznik_ruchow < 9 && !Sprawdz_wygrana(plansza, 'O'))
		{
			Ruch_komputera(plansza, licznik_ruchow);
			licznik_ruchow++;
		}
		system("cls");
		wyswietlanie(plansza);
		if (Sprawdz_wygrana(plansza, 'O'))break;
		if (Sprawdz_wygrana(plansza, 'X'))break;
	}
	return 0;
}