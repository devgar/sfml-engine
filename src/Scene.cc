#include "Scene.hh"

#include <iostream>

// void Scene::update(sf::Time dt)
// {
//   for(std::list<sf::Drawable>::iterator it = drawables.begin();
//       it != drawables.end(); it++)
//
//     if(dynamic_cast<AnimatedSprite*>(*it) != NULL)
//       (AnimatedSprite*) *it -> update(dt);
//
// }

void Scene::setWindow(sf::RenderWindow & win)
{
  m_window = &win;
}

sf::Texture* Scene::createTexture(const string & id)
{
    textureMap.insert( std::pair<string,sf::Texture>(id, sf::Texture()));
    return getTexture(id);
}

sf::Texture* Scene::getTexture(const string & id)
{
  return &(textureMap.find(id)->second);
}

void Scene::addDrawable(sf::Drawable * drawable)
{
  drawables.push_back(drawable);
}

void Scene::draw()
{
  this -> m_window -> clear();
  for(std::list<sf::Drawable*>::iterator it = drawables.begin();
      it != drawables.end(); it++)
  {
    this -> m_window -> draw ( **it );
  }

  this -> m_window -> display();
}
