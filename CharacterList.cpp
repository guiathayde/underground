#include "CharacterList.h"
#include "Enemy.h"
#include "Player.h"

CharacterList::CharacterList(){

}

CharacterList::~CharacterList(){
    ListCharacters.ClearAll();
}

void CharacterList::InsertCharacter(Character* pC){
    if(pC != NULL)
        ListCharacters.Insert(pC);
}

Character* CharacterList::GetPlayer(){
    
    //cria um character tmp
    Character *tmp;
    //posiciona o tmp como o primeiro elemento da lista
    tmp = ListCharacters.GetFirstList();
    while(tmp != NULL){
        //verifica se esse elemento é o player
        if(tmp->GetIsPlayer())
            //se sim retorna o player
            cout << tmp <<endl;
            return tmp;
        //se não pega o proximo elemento da lista
        tmp = ListCharacters.GetNextList();
    }
    //cout << "Player não encontrado" <<endl;
    return NULL;
}

void CharacterList::RemoveCharacter(Character *pR){
    ListCharacters.RemoveInfo(pR);
}

void CharacterList::InitializeCharacters(int enemiesNum){
    
    //carrega as imagens
    static sf::Texture enemyTexture;
    static sf::Texture playerTexture;
    
    if(enemyTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"));
        printf("Carregou inimigou\n");
    if(playerTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png"))
        printf("Carregou jogador\n");
    
    Player* p = NULL;
        p = new Player(&playerTexture, sf::Vector2u(4, 4), sf::Vector2f(-200.0f, 200.0f), 0.30f, 200.0f, 200.0f, 300, true, true,true);
        ListCharacters.Insert(p);
    
    
    for(int i = 0; i < enemiesNum ; i++){
        Enemy *aux = NULL;
        aux = new Enemy(&enemyTexture, sf::Vector2u(6, 2), sf::Vector2f(i*100.0f, 200.0f), 0.3f, 100.0f, 100.0f, 3, true,false);
        ListCharacters.Insert(aux);
    }

    
}

void CharacterList::UpdateCharacter(float deltaTime){
    
    Character* tmp;
    Character *p = GetPlayer();

    tmp = ListCharacters.GetFirstList();
    
    while(tmp != NULL){
        
        tmp->Update(deltaTime,p);
        tmp = ListCharacters.GetNextList();
    }

}

void CharacterList::DrawCharaceters(sf::RenderWindow &window){
    
    Character* tmp;
    Character *p = GetPlayer();
    //cout <<"Fuck" <<endl;
    tmp = ListCharacters.GetFirstList();
    while(tmp != NULL){
        tmp->Draw(window);
        tmp = ListCharacters.GetNextList();
    }
    

}

void CharacterList::CheckCharactersCollision(std::list<Platform *> platforms){

    sf::Vector2f direction;
    std::list<Platform *>::iterator itPlatform;
    int i;
    int j;
    int size = ListCharacters.GetSize();
    cout << ListCharacters.GetSize() <<endl;
    for (itPlatform = platforms.begin(); itPlatform != platforms.end(); itPlatform++)
    {
        
        for(i = 0 ; i < ListCharacters.GetSize(); i++){
            if ((*itPlatform)->GetCollider().CheckCollision(ListCharacters[i]->GetCollider(), direction, 1.0f)){
                ListCharacters[i]->OnCollision(direction);
                //cout <<"For da lista "<< i <<endl;       
            }
                
        }
    }
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(ListCharacters[i]->GetCollider().CheckCollision(ListCharacters[j]->GetCollider(),direction,1.0f))
                ListCharacters[j]->OnCollision(direction);

        }
    }



}