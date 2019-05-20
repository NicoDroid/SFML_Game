#include "FileController.h"

FileController::FileController()
{
}


FileController::~FileController()
{
}


std::vector<int> FileController::RecupFileOption()
{
	std::vector<int> tabvaleurs;
	int valeur;

	FILE *m_file;

	fopen_s(&m_file, "OptionsParam.ini", "r");

	//Récupère toute les valeurs dans l'ordre (Actuellement: VolumeMenu et VolumeGame)
	for (int i = 0; i < 2; i++)
	{
		fscanf_s(m_file, "%*s %d", &valeur);
		tabvaleurs.push_back(valeur);
	}

	fclose(m_file);

	return tabvaleurs;
}

void FileController::SetFileOption(int VolumeMenu, int VolumeGame)
{
	FILE *m_file;
	fopen_s(&m_file, "OptionsParam.ini", "w");

	std::string chemin[] = { "VolumeMenu " ,"VolumeGame " };
	int param[] = { VolumeMenu,VolumeGame };

	for (int i = 0; i < 2; i++)
	{
		chemin[i] += std::to_string(param[i]);

		//Conversion du String en pointeur de Char
		char *char_chemin;
		char_chemin = (char*)chemin[i].c_str();

		//Insertion dans le fichier
		fputs(char_chemin, m_file);
		fputs("\n", m_file);
	}

	fclose(m_file);
}