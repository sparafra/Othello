#include "GestioneGioco.h"

using namespace std;



int main(int argc, char **argv)
{
	GestioneGioco* Gioco = new GestioneGioco(argv[0]);
	Gioco->Start();

	return 0;
}
