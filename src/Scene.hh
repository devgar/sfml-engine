#ifndef SCENE_HH
#define SCENE_HH

#include <string>
#include <map>
#include <list>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "AnimatedSprite.hh"

using namespace std;

class Scene {
  sf::RenderWindow* m_window;

  map<string, sf::Texture> textureMap;
  map<string, sf::Sound> soundMap;
  map<string, sf::Music> musicMap;

  list<sf::Drawable *> drawables;
public:

  void setWindow(sf::RenderWindow &);

  void addDrawable(sf::Drawable *);

  void insertTexture(const string &, sf::Texture);
  void insertSound(string, sf::Texture);
  void insertMusic(string, sf::Music);

  void loadTexture(string);
  void loadSound(string);
  void loadMusic(string);

  sf::Texture* createTexture(const string &);
  sf::Texture* getTexture(const string &);

  void draw();
  void update(sf::Time);
};

#endif //end define SCENE_HH
