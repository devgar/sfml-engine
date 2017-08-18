#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hh"

using namespace std;

class Scene {
  sf::RenderWindow* m_window;

  map<string, sf::Texture> textureMap;
  map<string, sf::Sound> soundMap;
  map<string, sf::Music> musicMap;

  list<sf::Drawable *> drawables;
  list<AnimatedSprite *> updatables;
public:

  void setWindow(sf::RenderWindow &);

  void addDrawable(sf::Drawable *);

  // void loadTexture(string);
  // void loadSound(string);
  // void loadMusic(string);

  sf::Texture* createTexture(const string &);
  sf::Texture* getTexture(const string &);

  sf::Sound* createSound(const string &);
  sf::Sound* getSound(const string &);

  sf::Music* createMusic(const string &);
  sf::Music* getMusic(const string &);

  void draw();
  void update(sf::Time);
};

#endif //end define SCENE_HH
