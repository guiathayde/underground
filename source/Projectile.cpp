#include "Projectile.h"
#include "Character.h"

Projectile::Projectile(GraphicManager *graphicManager, sf::Vector2f position, float speed) : DynamicEntity(graphicManager, false, true, false, false,false)
{

    size = PROJECTILE_SIZE;
    velocity = PROJECTILE_VELOCITY;
    imageCount = PROJECTILE_IMAGE_COUNT;
    switchTime = PROJECTILE_SWITCH_TIME;

    this->speed = speed;
    this->position = position;
    id = PROJECTILE_ID;

    texture = graphicManager->GetTexture("projectile");
    animation = new Animation(texture, imageCount, switchTime);

    row = 0;
    faceRight = true;

    time = 0;

    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(position.x, position.y);
    body.setTexture(texture);
}

Projectile::~Projectile()
{
    delete (animation);
}
void Projectile::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}
void Projectile::OnCollision(sf::Vector2f direction)
{
}
void Projectile::Update(float deltaTime, Character *p)
{

    Player *player;
    p = static_cast<Player *>(p);

    velocity.x += speed;

    if (velocity.x > 0.0f)
        faceRight = true;
    else
        faceRight = false;

    animation->Update(row, deltaTime, faceRight);
    body.setTextureRect(animation->uvRect);
    body.move(velocity * deltaTime);
}

float Projectile::Attack(Player *p)
{

    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = body.getPosition();
    pos_player = p->GetPosition();

    if (pos_player.x < pos_enemy.x)
    {
        velocity.x -= speed;
        return velocity.x;
    }
    else if (pos_player.x > pos_enemy.x)
    {
        velocity.x += speed;
        return velocity.x;
    }

    return 0.0f;
}