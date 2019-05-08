#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

class FileOptionController
{
private:

public:

	FileOptionController();
	~FileOptionController();




	static std::vector<int> RecupFileOption();
	static void SetFileOption(int VolumeMenu, int VolumeGame);
};

