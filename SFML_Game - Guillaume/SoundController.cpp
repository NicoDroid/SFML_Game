#include <sstream>

#include "SoundController.h"
#include"SFML/Audio.hpp"




SoundController::SoundController(string file, bool loop)
{
	stringstream chemin;
	chemin << "Ressources/Audio/" << file;
	m_music.openFromFile(chemin.str());
	m_music.setVolume(m_volume);
}

void SoundController::Play()
{
	m_music.play();
	m_music.setLoop(m_loop);
}

void SoundController::Stop()
{
	m_music.stop();
}

void SoundController::SetVolume(int volume)
{
	m_volume = volume;
	m_music.setVolume(m_volume);
}