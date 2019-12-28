#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "../Camera/Camera.h"
#include "../GameObject/GameObject.h"
#include "../Game.h"

namespace tjm {
  class Game;
  class GameObject;

  class Room {
    public:
      // structs
      Room(Game* game, sf::Vector2i maxSize);
      ~Room();

      // setters
      void setFollow(unsigned long id);

      // getters
      sf::Vector2i getFollow();
      Game* getGame();

      // methods
      void setup();
      void update(int64_t deltaTime);
      void tearDown();
      void setBackground(std::string fileName);
      void Instantiate(GameObject* gameObject);
      void Destroy(unsigned long id);

    private:
      // fields
      Game* game;
      b2World* world;
      Camera* camera;
      unsigned long followObject;
      unsigned long objectCount;
      bool isFollow;
      std::vector<GameObject*> addingObjects;
      std::vector<unsigned long> removingObjects;
      std::map<unsigned long, GameObject*> objects;
      sf::Sprite background;

      // methods
      void cameraFollow();

      // virtuals
      virtual void open();
      virtual void step(int64_t deltaTime);
      virtual void close();
  };
}

#include "RoomsHeader.h"

#endif