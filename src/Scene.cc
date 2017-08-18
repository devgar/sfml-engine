#include "Scene.hh"

void Scene::setWindow(RenderWindow & win)
{
  setWindow(&win);
}

void Scene::setWindow(RenderWindow * win)
{
  m_window = win;
}

Texture* Scene::createTexture(const string & id)
{
    textureMap.insert( pair<string,Texture>(id, Texture()));
    return getTexture(id);
}

Texture* Scene::getTexture(const string & id)
{
  map<string, Texture>::iterator it = textureMap.find(id);
  return it == textureMap.end() ? NULL : &(it->second);
}

Sound* Scene::createSound(const string & id)
{
  soundMap.insert(pair<string, Sound>(id, Sound()));
  return getSound(id);
}

Sound* Scene::getSound(const string & id)
{
  map<string, Sound>::iterator it = soundMap.find(id);
  return it == soundMap.end() ? NULL : &(it->second);
}

// TODO: Decide what to do with musicMap because sd::Music is non-copyable

void Scene::addDrawable(Drawable & drawable)
{
  addDrawable(&drawable);
}

void Scene::addDrawable(Drawable * drawable)
{
  drawables.push_back(drawable);
  auto * animated = dynamic_cast<AnimatedSprite*>(drawable);
  if(animated) updatables.push_back(animated);
}

void Scene::draw()
{
  for(auto* d : drawables) m_window -> draw ( *d );
}

void Scene::update(Time dt)
{
  for(auto* s : updatables) s -> update(dt);
}
