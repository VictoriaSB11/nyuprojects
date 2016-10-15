//
//  Noble.cpp
//  hw07
//
//  Created by Victoria Spann-Burton on 3/29/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft {
    
    Noble::Noble(const string& nName) : name(nName), deadNoble(false) {}   //actual Noble class methods
    
    string Noble::getName()const{ return name; }
    
    string Noble::getArmyStats()const{
        for(size_t i = 0; i < army.size(); i++){
            cout << army[i]->getName() << " : " << army[i]->getStrength() << endl;
        }
        return "\n";
    }
    
    size_t Noble::getArmySize()const{ return army.size();}
    
    double Noble::getArmyStrength()const{
        double strength = 0;
        for(size_t i = 0; i < army.size(); ++i){
            strength = strength + (army[i] -> getStrength());
        }
        return strength;
    }
    
    void Noble::setWarriorStrength(double newStrength){
        for(size_t i = 0; i < army.size(); i++){
            army[i]->setStrength(newStrength);
        }
    }
    
    void Noble::fire(Warrior& theWarrior){
        for(size_t i = 0; i < army.size(); i++){
            if(army[i]->getName() == theWarrior.getName()){
                army[i]->setStatus(false);
                army[i]->setBoss(nullptr);
                army[i] = army[army.size()-1];
            }
            army.pop_back();
        }
    }
    
    void Noble::hire(Warrior& theWarrior){
        if(theWarrior.getStatus() == false){
            theWarrior.setStatus(true);
            theWarrior.setBoss(this);
            army.push_back(&theWarrior);
        }
    }
    
    void Noble::kill() { deadNoble = true; }
    
    bool Noble::dead() { return deadNoble; }
    
    void Noble::battle(Noble& theNoble){
        cout << name << " battles " << theNoble.getName() << endl;
        
        if(this->dead() == true && theNoble.dead() == true){
            cout << "Oh no! " << name << " and " << theNoble.getName() << " are both dead!" << endl;
        }
        
        else if(theNoble.dead() == true && getArmyStrength() > 0){
            
            cout << theNoble.getName() << " is dead." << endl;
        }
        
        else if(this->dead() == true && theNoble.getArmyStrength() > 0){
            
            cout << name << " is dead." << endl;
        }
        
        else if(getArmyStrength() == theNoble.getArmyStrength() && theNoble.getArmyStrength() > 0 && getArmyStrength() > 0){
            
            cout << "Mutual Annihilation: " << name << " and " << theNoble.getName() << " died at each other's hands." << endl;
            
            theNoble.setWarriorStrength(0);
            theNoble.kill();
            this->setWarriorStrength(0);
            this->kill();
        }
        
        else if(getArmyStrength() > theNoble.getArmyStrength() && getArmyStrength() > 0 && theNoble.getArmyStrength() > 0){
            
            cout << name << " defeats " << theNoble.getName() << endl;
            
            theNoble.setWarriorStrength(0);
            theNoble.kill();
            
            for(size_t i = 0; i < army.size(); ++i){
                army[i]->setStrength((army[i]->getStrength())*(1-(theNoble.getArmyStrength()/getArmyStrength())));
            }
        }
        
        else if(theNoble.getArmyStrength() > getArmyStrength() && getArmyStrength() > 0 && theNoble.getArmyStrength() > 0){
            
            cout << theNoble.getName() << " defeats " << name << endl;
            
            for(size_t i = 0; i < theNoble.army.size(); ++i){
                theNoble.army[i] -> setStrength((theNoble.army[i]->getStrength())*(getArmyStrength()/theNoble.getArmyStrength()));
            }
            
            this->setWarriorStrength(0);
            this->kill();
            
        }
        
        
    }
    
    ostream& operator<<(ostream& os, const Noble& n){                       //overload operator << to display army stats
        os << n.getName() << " has an army of " << n.getArmySize() << "\n";
        os << n.getArmyStats();
        return os;
    }
    
}