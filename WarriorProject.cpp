//
//  main.cpp
//  hw04
//
//  Created by Victoria Spann-Burton on 2/29/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

/*This program is a game, where there are Nobles and there are Warriors.  Each Noble has an army of Warriors.
Each Warrior has a certain amount of strength they are born with.  
 The strength of the Noble is determined by the sum of the Warrior's strength.
 The Noble's can hire and fire Warriors in their army.  
 A Noble can only hire a Warrior that has not been hired, they can not hire a Noble that is already hired.  
 With battle, if the strength of the armies are equal both of the Nobles and their Warriors die
 If one army has more strength than the other, the winning army loses some strength, but the losing army dies.*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Warrior {    //class of Warriors
public:
    Warrior(const string& warriorName, const double& warriorStrength) : name(warriorName), strength(warriorStrength),hired(false) {}   //constructor to initialize name and strength
    
    double getStrength() const {   //method to return the strength   //accessor method
        return strength;
    }
    
    void setStrength(const int& theStrength){   //method to set strength  //setter method
        strength = theStrength;
    }
    
    string getName() const {    //method to return the warrior name
        return name;
    }
    bool getStatus() const{     //method to get employment status
        return hired;
    }
    void setStatus(const bool& status){     //method to set employment status
        hired = true;
    }
    
private:
    string name;
    double strength;
    bool hired;
    
};

class Noble {   //class of Nobles
public:
    Noble(const string& nobleName) : name(nobleName) {}  //constructor to initialize name of warriors
    
    void display() const {
        
        cout << name << " has an army of " << getArmySize() << endl;       //display method
        
        for(size_t i = 0; i < army.size(); ++i){
            cout << army[i] -> getName() << ": " << army[i] -> getStrength() << endl;
        }
    }
    
    int getArmySize() const {                   //loops through the vector to return the number of warriors
        int count = 0;
        for(size_t i = 0; i < army.size(); ++i){
            ++count;
        }
        return count;
    }
    
    string getNobleName() const {               //method to return Noble name
        return name;
    }
    
    double getArmyStrength() const {       //method to return army strength
        double strength = 0;
        for(size_t i = 0; i < army.size(); ++i){
            strength = strength + (army[i] -> getStrength());
        }
        return strength;
    }

    
    void fire(const Warrior& theWarrior){                     //method to fire a warrior and delete the pointer from the vector
        cout << theWarrior.getName() << ", you're fired! -- " << name << endl;
        for(size_t i = 0; i < army.size(); ++i){
            if(army[i] -> getName() == theWarrior.getName()){
                army[i] -> setStatus(false);
                army[i] = army[i+1];
            }
            army.pop_back();
        }
    }
    
    void hire(Warrior& theWarrior){   //method to add pointer to warrior to the army vector, method to hire a warrior
        if(theWarrior.getStatus() == false){
        Warrior* ptr = &theWarrior;     //make sure two Nobles can not hire the same warrior
        army.push_back(ptr);
            ptr -> setStatus(true);
        }
    }
    
    void battle(Noble& theNoble){               //battle method
        
        cout << name << " battles " << theNoble.getNobleName() << endl;
        
        if(getArmyStrength() == 0 && theNoble.getArmyStrength() == 0){
            cout << "Oh no! " << name << " and " << theNoble.getNobleName() << " are both dead!" << endl;
        }

        else if(theNoble.getArmyStrength() == 0 && getArmyStrength() > 0){
            
            cout << theNoble.getNobleName() << " is dead." << endl;
        }
        
        else if(getArmyStrength() == 0 && theNoble.getArmyStrength() > 0){
            
            cout << name << " is dead." << endl;
        }
        
        else if(getArmyStrength() == theNoble.getArmyStrength() && theNoble.getArmyStrength() > 0 && getArmyStrength() > 0){
            
            cout << "Mutual Annihilation: " << name << " and " << theNoble.getNobleName() << " died at each other's hands." << endl;
            
            for(size_t i = 0; i < theNoble.army.size(); ++i){
                theNoble.army[i] -> setStrength((theNoble.army[i] -> getStrength())*(0));
            }
            
            for(size_t i = 0; i < army.size(); ++i){
                army[i] -> setStrength((army[i] -> getStrength())*(0));
            }
        }
        
        else if(getArmyStrength() > theNoble.getArmyStrength() && getArmyStrength() > 0 && theNoble.getArmyStrength() > 0){
            
            cout << name << " defeats " << theNoble.getNobleName() << endl;
            
            for(size_t i = 0; i < theNoble.army.size(); ++i){
                theNoble.army[i] -> setStrength((theNoble.army[i] -> getStrength())*(0));
            }
            
            for(size_t i = 0; i < army.size(); ++i){
                army[i] -> setStrength((army[i] -> getStrength())*(1-(theNoble.getArmyStrength()/getArmyStrength())));
            }
            
        }
        else if(theNoble.getArmyStrength() > getArmyStrength() && getArmyStrength() > 0 && theNoble.getArmyStrength() > 0){
            
            cout << theNoble.getNobleName() << " defeats " << name << endl;
            
            for(size_t i = 0; i < theNoble.army.size(); ++i){
                theNoble.army[i] -> setStrength((theNoble.army[i] -> getStrength())*(getArmyStrength()/theNoble.getArmyStrength()));
            }
            
            for(size_t i = 0; i < army.size(); ++i){
                army[i] -> setStrength((army[i] -> getStrength())*(0));
            }
            
        }
        
    }
    
private:
    string name;
    vector<Warrior*> army;
    
};

int main(){
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");
    
    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);
    
    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();
    
    art.fire(cheetah);
    art.display();
    
    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);
    
    jim.display();
    lance.display();
    art.display();
    linus.display();
    billie.display();

}
