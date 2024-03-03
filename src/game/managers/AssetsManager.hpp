#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

namespace game {
class AssetsManager {
 private:
  std::map<std::string, sf::Texture> textures;
  std::map<std::string, sf::Font> fonts;
//  std::map<std::string, sf::SoundBuffer> sounds;

 public:
  AssetsManager() = default;

  bool loadTexture(const std::string &sourceFileName, const std::string &targetName);
  const sf::Texture &getTexture(const std::string &name) const;

  bool loadFont(const std::string &sourceFileName, const std::string &targetName);
  const sf::Font &getFont(const std::string &name) const;

//  bool loadSound(const std::string &sourceFileName, const std::string &targetName);
//  const sf::SoundBuffer &getSound(const std::string &name) const;
};
} // namespace game
