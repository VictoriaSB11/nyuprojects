//
//  Warrior.cpp
//  hw07
//
//  Created by Victoria Spann-Burton on 3/29/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

#include "Warrior.h"
#include "Noble.h"
#include <iostream>
#include <string>
using namespace std;

namespace WarriorCraft {
    
    Warrior::Warrior(const string& wName, double wStrength) : name(wName), strength(wStrength), boss(nullptr) {}
    
    double Warrior::getStrength()const{ return strength; }
    
    void Warrior::setStrength(double theStrength) { strength = theStrength; }
    
    string Warrior::getName() const { return name; }
    
    bool Warrior::getStatus() const { return hired; }
    
    void Warrior::setStatus(const bool& status) { hired = status; }
    
    void Warrior::setBoss(Noble* theBoss) { boss = theBoss; }
    
    string Warrior::getBoss(){ return boss->getName(); }
    
    void Warrior::runaway() {           //new runaway method removes warrior from army using other 'fire' method
        if(this->getStatus() == true){
            cout << this->getName() << " flees from his lord, " << this->getBoss() << endl;
            boss->fire(*this);
        }
    }
    
}

