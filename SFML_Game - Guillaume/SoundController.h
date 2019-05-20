#pragma once
#include <SFML/Audio.hpp>
#include <string>

using namespace std;

class SoundController
{

private:
	sf::Music m_music;
	string m_file;
	int m_volume = 50;
	bool m_loop;

public:
	SoundController(string file, bool loop);

	void SetVolume(int volume);
	void Play();
	void Stop();
};
