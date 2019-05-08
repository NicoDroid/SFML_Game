#include "FileController.h"
#include <iostream>

int FileOptionController::RecupOptions()
{
	int valeur[2];

	FILE *m_file;
	fopen_s(&m_file, "Test.txt", "r");

	for (int i = 0; i < 2; i++)
	{
		fscanf_s(m_file, "%d %d", &valeur[0], &valeur[1]);
		std::cout << valeur[1] << std::endl;
	}
		fclose(m_file);
		return 0;
}

void FileOptionController::SetVolumeMenu()
{
	FILE *m_file;
	fopen_s(&m_file,"Test.txt", "a");
	fputs("0 10", m_file);
	fputs("\n", m_file);
	fclose(m_file);
}

void FileOptionController::SetVolumeGame()
{
	FILE *m_file;
	fopen_s(&m_file, "Test.txt", "a");
	fputs("1 20", m_file);
	fputs("\n", m_file);
	fclose(m_file);
}