//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Player.h"
#include "Map.h"
#include <iostream>


Player::Player() {
    victoryPoints = 0;
    lifePoints= 10;
    energyCubes = 0;

    Dice dice; // Player dice obj
    MonsterCards monsterCard; // Player monster card
    BoardFigures boardFigure; // Player board fig
    vector <Cards> cards; //List of all deck cards assigned to player (purchased)
    vector <GameTokens> gameTokens; // List of all game tokens assigned to player
    vector <BuildingUnitTiles> buildingUnitTiles; // List of all building tiles assigned to player

    attach(new PhaseObserver(this));
    attach(new GameStatisticsObserver());
}

Player::Player(string s) {
    this -> setPlayerName(s);
}

Player::~Player() {

}

Player::Player(Dice* d, int i): Player() {
    this ->dice = d ;
    this ->playerID = i;
    this ->dice->setPlayerNumber(i);
    this ->setPlayerName(std::string("Random ") += to_string(i));
    this ->setZone(10); // Nothing
}

int Player::getPlayerID() const {
    return playerID;
}

// Roll dice scenario for all rolls, called by player
void Player::rollDice() {
    phase = Roll;
    notify();
    // Implement keeping certain number of dice, erasing diceHistorical values past 3
    // Then sum the values for the resolveDice step, total 6 dice
    cout << "Rolling first dice for player, Press enter to confirm" << endl;
    cin.ignore();
    //Roll first dice
    this->dice->rollDiceSequence();
    cout << "Player turn is over" << endl;
}

void Player::rollAggressive() {
    phase = Roll;
    notify();
    this->dice->rollAggressiveComputer();
}

void Player::rollModerate() {
    phase = Roll;
    notify();
    this->dice->rollModerateComputer();
}

// roll dice to determine which player starts
int Player::rollDiceFirst() {
    phase = Roll;
    notify();

    int result;
    result = this-> dice->rollDiceDetermineStart();
    return result;
}

void Player::buyCards(Cards card) {
    phase = Buy;
    notify();

    if(getEnergyCubes() < card.getEnergyCost()){
        cout << "You do not have enough energy cubes to purchase this card" << endl;
        return;
    }
    else{
        this->removeEnergyCubes(card.getEnergyCost());
        Game::cardRules(this, card.getId());
        this->addCard(card);
    }

}

void Player::addCard(Cards card) {
        cards.push_back(card);
}

bool Player::disposeOfCards() {
    if(getEnergyCubes()>2)
    {
        removeEnergyCubes(3);
        return true;
    }
    else{
        cout << "You do not have enough energy cubes to dispose the top 3 cards" << endl;
        return false;
    }
}


void Player::attack() {

}

int Player::getNumberOfCards() {
    return int(cards.size());
}

int Player::getLifePoints() {
    return lifePoints;
}

int Player::getVictoryPoints() {
    return victoryPoints;
}

int Player::getEnergyCubes() {
    return energyCubes;
}

void Player::addLifePoints(unsigned int pts) {
    lifePoints += pts ;

}

void Player::addVictoryPoints(unsigned int pts) {
    victoryPoints += pts;
}

void Player::removeLifePoints(int pts) {
    lifePoints -= pts ;

}

void Player::removeVictoryPoints(int pts) {
    victoryPoints -= pts;
}

void Player::removeEnergyCubes(int pts) {
    energyCubes -= pts;
}

void Player::addEnergyCubes(int pts) {
    energyCubes += pts;
}

// Overload print operator for vector of Cards
ostream& operator<<(ostream& os, vector<Cards> v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

// Overload print operator for vector of gameTokens
ostream& operator<<(ostream& os, vector<GameTokens> v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

// Overload print operator for Player object
ostream & operator<<(ostream & os, Player* player){

    os << "----------------------------------------" << endl;
    os << "ID :" << player->getPlayerID() << endl;
    os << "Name :" << player->getPlayerName() << endl;
    os << "***************" << endl;
    os << "Monster Card: " << player->getMonsterCard().getName() << endl;
    os << "***************" << endl;
    os << "Owned Zone: "  << player->getZoneName() << endl;
    os << "***************" << endl;
    os << "Victory Points: " << player->getVictoryPoints() << endl;
    os << "Life Points: " << player->getLifePoints() << endl;
    os << "Energy Cubes: " << player->getEnergyCubes() << endl;
    os << "***************" << endl;
    os << "Game Tokens: \n"  << player->getGameTokens();
    os << "Game Cards: \n"  << player->getCards();
    os << "----------------------------------------" << endl;
    return os;

}

void Player::showStats(){
    cout << "***************" << endl;
    cout << "Owned Zone: "  << this->getZoneName() << endl;
    cout << "***************" << endl;
    cout << "Victory Points: " << this->getVictoryPoints() << endl;
    cout << "Life Points: " << this->getLifePoints() << endl;
    cout << "Energy Cubes: " << this->getEnergyCubes() << endl;
    cout << "***************" << endl;
}

void Player::addGameToken(GameTokens token) {
    gameTokens.push_back(token);
}

void Player::addBuildingUnitTiles(BuildingUnitTiles tile) {
    buildingUnitTiles.push_back(tile);
}

void Player::assignMonster(MonsterCards card) {
    this->monsterCard = card;
    this->monsterCard.assigned = true;
}

void Player::assignBoardFigure(BoardFigures figure) {
    this->boardFigure = std::move(figure);
}

void Player::assignDiceObject(Dice* dice) {
    this->dice = dice;
}

const MonsterCards &Player::getMonsterCard() const {
    return monsterCard;
}

const BoardFigures &Player::getBoardFigure() const {
    return this->boardFigure;
}

const vector<Cards> &Player::getCards() const {
    return this->cards;
}

const vector<GameTokens> &Player::getGameTokens() const {
    return this->gameTokens;
}

void Player::getGameTokensState() {
    for (auto &gameToken : gameTokens) {
        cout << gameToken << endl;
    }
}

void Player::setPlayerID(int playerId) {
    this->playerID = playerId;

}

int Player::getZone() {
    return ownedZone;
}

void Player::setZone(int zone) {
    this-> ownedZone = zone;
}

string Player::getZoneName() {
    return zoneNames[ownedZone];
}

const string &Player::getPlayerName() const {
    return playerName;
}

void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

Dice* Player::getDice() {
    return dice;
}

void Player::setPhase(Player::Phase p) {
    this->phase = p;
}

Player::Phase Player::getPhase() {
    return phase;
}

void Player::setStrategy(Strategy *strat) {
    this->strategy = strat;
}

void Player::executeStrategy(Game* game, Player* player) {
    return this->strategy->execute(game, player);
}
