#include "AssetsManager.hpp"

namespace game {
bool AssetsManager::loadTexture(const std::string &sourceFileName, const std::string &targetName) {
  sf::Texture texture;
  if (texture.loadFromFile(sourceFileName)) {
	textures[targetName] = texture;
	return true;
  }

  return false;
}

const sf::Texture &AssetsManager::getTexture(const std::string &name) const {
  return textures.at(name);
}

bool AssetsManager::loadFont(const std::string &sourceFileName, const std::string &targetName) {
  sf::Font font;
  if (font.loadFromFile(sourceFileName)) {
	fonts[targetName] = font;
	return true;
  }

  return false;
}

const sf::Font &AssetsManager::getFont(const std::string &name) const {
  return fonts.at(name);
}

//bool AssetsManager::loadSound(const std::string &sourceFileName, const std::string &targetName) {
//  sf::SoundBuffer sound;
//  if (sound.loadFromFile(sourceFileName)) {
//	sounds[targetName] = sound;
//	return true;
//  }
//
//  return false;
//}
//
//const sf::SoundBuffer &AssetsManager::getSound(const std::string &name) const {
//  return sounds.at(name);
//}
} // namespace game

