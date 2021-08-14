#pragma once

#include "Player.h"

#define CHILD_PLAYER_SIZE {60.0f,70.0f}
#define CHILD_PLAYER_IMAGE_COUNT {4,4}
#define CHILD_PLAYER_SWITCH_TIME 0.3f
#define CHILD_PLAYER_SPEED 200.0f
#define CHILD_PLAYER_JUMP_HEIGHT 200.f
#define CHILD_PLAYER_HEARTS 300

class ChildPlayer:public Player
{
private:

public:
    ChildPlayer(GraphicManager *graphicManager, sf::Vector2f position);
    ~ChildPlayer();

    void Update(float deltaTime, Character *ini);
    void SetPosition(sf::Vector2f position) { body.setPosition(position); }
};

