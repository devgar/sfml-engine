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
using namespace sf;

class Scene {
  RenderWindow* m_window;

  map<string, Texture> textureMap;
  map<string, Sound> soundMap;
  map<string, Music> musicMap;

  list<Drawable *> drawables;
  list<AnimatedSprite *> updatables;
public:

  void setWindow(RenderWindow &);
  void setWindow(RenderWindow *);
  void addDrawable(Drawable &);
  void addDrawable(Drawable *);

  // void loadTexture(string);
  // void loadSound(string);
  // void loadMusic(string);

  Texture* createTexture(const string &);
  Texture* getTexture(const string &);

  Sound* createSound(const string &);
  Sound* getSound(const string &);

  Music* createMusic(const string &);
  Music* getMusic(const string &);

  void draw();
  void update(Time);
};

#endif //end define SCENE_HH
