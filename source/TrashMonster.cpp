#include "TrashMonster.h"

TrashMonster::TrashMonster(GraphicManager* graphicManager,sf::Vector2f origin)
:Enemy(graphicManager,texture,size,origin,imageCount,switchTime,speed,jumpHeight,totalStunTime,hearts,isAlive,isPlayer)
{
    
    texture = graphicManager->GetTexture("trashMonster");

    coolDown = 0;    

    imageCount = TRASH_MONSTER_IMAGECOUNT;
    switchTime = TRASH_MONSTER_SWITCHTIME;
    jumpHeight = TRASH_MONSTER_JUMP_HEIGHT;
    totalStunTime = TRASH_MONSTER_TOTAL_STUN_TIME;
    hearts =    TRASH_MONSTER_HEARTS;
    speed = TRASH_MONSTER_SPEED;

    size = TRASH_MONSTER_SIZE;

    isAlive = true;
    isPlayer = false;
    isStunned = false;
    animation = new Animation(texture,imageCount,switchTime);
    
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(origin.x, origin.y);
    body.setTexture(texture);
}

TrashMonster::~TrashMonster(){
    
    cout <<"Entrou na destrutora do TrashMonster" <<endl;
    delete(texture);
}


void TrashMonster::Update(float deltaTime,Character* character)
{

    Player *p;
    p = static_cast<Player *>(character);

    if (isStunned && coolDown > totalStunTime)
    {
        isStunned = false;
    }
    coolDown += deltaTime;

    velocity.x *= 0.5f; // time to stop action walk (slow down)
    
    if (!isStunned && SeePlayer(p))
    {
        coolDown = 0;
        velocity.x = Attack(p);
    }
    velocity.y += 981.0f * deltaTime;

    if (velocity.x == 0.0f)
        row = 1;
    else
    {
        row = 0;

        if (velocity.x > 0.0f)
            faceRight = false;
        else
            faceRight = true;
    }
    if (hearts <= 0)
    {
        isAlive = false;
    }
    animation->Update(row, deltaTime, faceRight);
    body.setTextureRect(animation->uvRect);
    body.move(velocity * deltaTime);
}

bool TrashMonster::SeePlayer(Player *p){
    

    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p->GetPosition();
    float D = sqrt((pos_player.x-pos_enemy.x)*(pos_player.x-pos_enemy.x)+(pos_player.y-pos_enemy.y)*(pos_player.y-pos_enemy.y));

    if(D <= 500.0f)
        return true;
    
    else
        return false;
    
}
float TrashMonster::Attack(Player *p){
    
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p->GetPosition();
    if(pos_player.x < pos_enemy.x){
        velocity.x -= speed;
        return velocity.x;
    }
    else if(pos_player.x > pos_enemy.x){
        velocity.x += speed;
        return velocity.x;
    }
    
    return 0.0;
}