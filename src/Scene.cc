#include "Scene.hh"

void Scene::setWindow(sf::RenderWindow & win)
{
  m_window = &win;
}

sf::Texture* Scene::createTexture(const string & id)
{
    textureMap.insert( pair<string,sf::Texture>(id, sf::Texture()));
    return getTexture(id);
}

sf::Texture* Scene::getTexture(const string & id)
{
  map<string, sf::Texture>::iterator it = textureMap.find(id);
  return it == textureMap.end() ? NULL : &(it->second);
}

sf::Sound* Scene::createSound(const string & id)
{
  soundMap.insert(pair<string, sf::Sound>(id, sf::Sound()));
  return getSound(id);
}

sf::Sound* Scene::getSound(const string & id)
{
  map<string, sf::Sound>::iterator it = soundMap.find(id);
  return it == soundMap.end() ? NULL : &(it->second);
}

// TODO: Decide what to do with musicMap because sd::Music is non-copyable

void Scene::addDrawable(sf::Drawable * drawable)
{
  drawables.push_back(drawable);
  auto * animated = dynamic_cast<AnimatedSprite*>(drawable);
  if(animated) updatables.push_back(animated);
}

void Scene::draw()
{
  for(auto* d : drawables) m_window -> draw ( *d );
}

void Scene::update(sf::Time dt)
{
  for(auto* s : updatables) s -> update(dt);
}
