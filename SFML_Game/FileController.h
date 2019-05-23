#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class FileController
{
private:

public:

	FileController();
	~FileController();




	static std::vector<int> RecupFileOption();
	static void SetFileOption(int VolumeMenu, int VolumeGame, int scaleX, int scaleY);
};

