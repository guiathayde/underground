#include "WelderEnemy.h"


WelderEnemy::WelderEnemy(GraphicManager* graphicManager,sf::Vector2f origin,DynamicEntityList* entities)
:Enemy(graphicManager,texture,origin,size,imageCount,switchTime,speed,jumpHeight,totalStunTime,WELDER_ENEMY_ID,hearts,isAlive,isPlayer)
{
    
    //cout <<"Entrou na construtora do WeldeEnemy"<<endl;
    texture = graphicManager->GetTexture("enemyShooter");

    this->entities = entities;

    coolDown = 0;
    shootCoolDown = 0;

    speed = WELDER_ENEMY_SPEED;
    imageCount = WELDER_ENEMY_IMAGECOUNT;
    switchTime = WELDER_ENEMY_SWITCHTIME;
    jumpHeight = WELDER_ENEMY_JUMP_HEIGHT;
    totalStunTime = WELDER_ENEMY_TOTAL_STUN_TIME;
    hearts =    WELDER_ENEMY_HEARTS;
    ammunition = 1;
    size = WELDER_ENEMY_SIZE;

    canShoot = true;
    isAlive = true;
    isPlayer = false;
    isStunned = false;
    animation = new Animation(texture,imageCount,switchTime);
    
    body.setSize(size);
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(origin.x, origin.y);
    body.setTexture(texture);
}

WelderEnemy::~WelderEnemy(){
    delete(animation);
}

void WelderEnemy::Update(float deltaTime,Character* character)
{
        
    Player *p;
    p = static_cast<Player *>(character);

    if (isStunned && coolDown > totalStunTime)
    {
        coolDown = 0;   
        isStunned = false;
    }
    coolDown += deltaTime;

    velocity.x *= 0.5f; 
    
    if (!isStunned && SeePlayer(p))
    {
        coolDown = 0;
        faceRight = Attack(p);
        if(ammunition > 0){
            cout << "atirou" <<endl;
            Shoot();
            ammunition--;
        }
        //cout << shootCoolDown <<endl;
        
        if(shootCoolDown > 5){
            
            shootCoolDown = 0;
            ammunition++;
            entities->RemoveDynamicEntity(projectile);
            cout << "Removeu" <<endl;
            cout << projectile << endl;        
        }
        else
            shootCoolDown+=deltaTime;

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

bool WelderEnemy::SeePlayer(Player *p){

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

bool WelderEnemy::Attack(Player *p){
    
    sf::Vector2f pos_enemy;
    sf::Vector2f pos_player;

    pos_enemy = GetPosition();
    pos_player = p->GetPosition();
    if(pos_player.x < pos_enemy.x){
        velocity.x -= speed;
        return false;
    }
    else if(pos_player.x > pos_enemy.x){
        velocity.x += speed;
        return true;
    }
    
    return 0.0;
}

void WelderEnemy::Shoot(){

    float projectile_speed;
    float tmp;

    if(faceRight){
        projectile_speed = 5.0f;
        tmp  = 10+body.getSize().x/2.0f;
    }
    else{
        projectile_speed = -5.0f;
        tmp = -10-body.getSize().x/2.0f;
    }

    sf::Vector2f position = GetPosition();
    position.x += tmp;
    projectile = new Projectile(graphicManager,position,projectile_speed);
    entities->InsertDynamicEntity(projectile);

}