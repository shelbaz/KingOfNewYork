//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

class Cards {

    enum CardEffects{Energy=0, Attack, Destruction, Heal, Celebrity, Ouch};
    //64 cards

public:
    enum CardType { Empty, Goal, Keep, Discard };

private:
    int id;
    std::string name;
    std::string description;
    CardType type;
    int energyCost;

    // Effect array values{E,A,D,H,C,O}
    vector <int> effect = {0,0,0,0,0,0};
    vector <int> ::iterator it;

public:

    Cards();

    void setCard(int id, std::string name, int energyCost, CardType type, std::string description);
    friend ostream& operator<<(ostream& os, const Cards& card);
    bool operator==(const Cards& other);

    void setName(const std::string &name);

    void setDescription(const std::string &description);

    void setType(CardType type);

    void setEnergyCost(int);

    void setEffect(const vector<int> &effect);

    int getEnergyCost() const;

    std::string getName() const;

    CardType getType() const;

    std::string getDescription() const;

    vector<int> getEffect();

    int getId() const;

    void setId(int);



};
