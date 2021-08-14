#include "HollowHatEnemy.h"

HollowHatEnemy::HollowHatEnemy(GraphicManager* graphicManager,sf::Vector2f origin)
:Enemy(graphicManager,texture,size,origin,imageCount,switchTime,speed,jumpHeight,totalStunTime,hearts,isAlive,isPlayer)
{
    
    texture = graphicManager->GetTexture("enemyMelee");

    coolDown = 0;    

    imageCount = HOLLOW_HAT_ENEMY_IMAGECOUNT;
    switchTime = HOLLOW_HAT_ENEMY_SWITCHTIME;
    jumpHeight = HOLLOW_HAT_ENEMY_JUMP_HEIGHT;
    totalStunTime = HOLLOW_HAT_ENEMY_TOTAL_STUN_TIME;
    hearts =    HOLLOW_HAT_ENEMY_HEARTS;
    speed = HOLLOW_HAT_ENEMY_SPEED;

    size = HOLLOW_HAT_ENEMY_SIZE;

    isAlive = true;
    isPlayer = false;
    isStunned = false;
    animation = new Animation(texture,imageCount,switchTime);
    
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(origin.x, origin.y);
    body.setTexture(texture);
}

HollowHatEnemy::~HollowHatEnemy(){
    
    cout <<"Entrou na destrutora do HollowEnemy" <<endl;
    delete(texture);
}


void HollowHatEnemy::Update(float deltaTime,Character* character)
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
        row = 0;
    else
    {
        row = 1;

        if (velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    if (hearts <= 0)
    {
        isAlive = false;
    }
    animation->Update(row, deltaTime, faceRight);
    body.setTextureRect(animation->uvRect);
    body.move(velocity * deltaTime);
}

bool HollowHatEnemy::SeePlayer(Player *p){
    

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
float HollowHatEnemy::Attack(Player *p){
    
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