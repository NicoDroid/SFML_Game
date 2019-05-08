#include "FileController.h"
#include <iostream>



FileOptionController::FileOptionController()
{

}











std::vector<int> FileOptionController::RecupFileOption()
{
	std::vector<int> tabvaleurs;
	int valeur;

	FILE *m_file;

	fopen_s(&m_file, "OptionsParam.ini", "r");

	for (int i = 0; i < 2; i++)
	{
		fscanf_s(m_file, "%*s %d", &valeur);
		tabvaleurs.push_back(valeur);
	}

	fclose(m_file);

	return tabvaleurs;
}

void FileOptionController::SetFileOption(int VolumeMenu,int VolumeGame)
{
	FILE *m_file;
	fopen_s(&m_file, "OptionsParam.ini", "a");

	std::string chemin[] = { "VolumeMenu " ,"VolumeGame "};
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