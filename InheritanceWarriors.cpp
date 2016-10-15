//
//  main.cpp
//  hw06
//
//  Created by Victoria Spann-Burton on 3/25/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

/*Program by Victoria Spann-Burton to show Inheritance of classes.
 There is a Noble class and a Protector class.  There are two types of Nobles, a strong Noble which has it's own strength and a Lord Noble which has an army of Protectors.
 There are Wizard and Warrior protectors, then there are Archer and Swordmen Warriors.  The strength of the Lord Noble comes from the sum of it's Protectors' strength. When the Nobles battle, if their strengths are equal, both Nobles die.  If one Noble has more strength than another, the winning Noble will lose some strength, but the losing Noble will die.*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Noble {    //Noble abstract class
public:
    Noble(const string& nobleName) : name(nobleName), deadNoble(false) {}
    
    virtual double getStrength() = 0;
    
    virtual void setStrength(double newStrength) = 0;
    
    virtual void display() = 0;
    
    virtual void battle(Noble& theNoble) = 0;
    
    string getName(){
        return name;
    }
    
    bool doaNoble() const {
        return deadNoble;
    }
    
    void kill() {
        deadNoble = true;
    }
    
private:
    string name;
    bool deadNoble;
};


class Protector {   //Protector abstract class
public:
    Protector(const string& pName, double pStrength) : name(pName), strength(pStrength), hired(false), deadProtector(false), nobleBoss(nullptr) {}
    
    virtual void display() = 0;
    
    string getName() const {
        return name;
    }
    
    bool getEmpStatus() const {
        return hired;
    }
    
    bool doaProtector() const {
        return deadProtector;
    }
    
    void setStatus(const bool& status){
        hired = status;
    }
    
    void setBoss(Noble* nptr){  //sets nullptr to a Lord ptr to set as a boss
        nobleBoss = nptr;
    }
    
    double getStrength(){
        return strength;
    }
    
    void setStrength(double newStrength){   //sets new strength after battle
        strength = newStrength;
    }
    
    void kill() {
        deadProtector = true;
        strength = 0;
    }
    
    string getLordName() const {
        return nobleBoss -> getName();
    }
    
private:
    string name;
    double strength;
    bool hired;
    bool deadProtector;
    Noble* nobleBoss;
};

class Wizard : public Protector {   //Wizard is a type of Protector
public:
    Wizard(const string& wizName, double wizStrength) : Protector(wizName, wizStrength) {}
    
    void display() {
        cout << "POOF! " << getName() << " says: Take that in the name of my lord, " << getLordName() <<  endl;
    }
    
private:
};

class Warrior : public Protector {   //Warrior is a type of Protector
public:
    Warrior(const string& wName, double wStrength) : Protector(wName, wStrength) {}
    
    virtual void display() = 0;  //Warrior is an abstract class because different warriors will have different display methods
    
private:
};

class Archer : public Warrior {   //An Archer is a type of Warrior
public:
    Archer(const string& archName, double archStrength) : Warrior(archName, archStrength) {}
    
    void display(){
        cout << "TWANG! " << getName() << " says: Take that in the name of my lord, " << getLordName() << endl;
    }
    
private:
};

class Swordsman : public Warrior {   //A Swordsman is a type of Warrior
public:
    Swordsman(const string& swName, double swStrength) : Warrior(swName, swStrength) {}
    
    void display() {
        cout << "CLANG! " << getName() << " says: Take that in the name of my lord, " << getLordName() << endl;
    }
    
private:
};

class StrongNoble : public Noble {   //A Strong Noble is a type of Noble with it's own strength
public:
    StrongNoble(const string& nobleName, double nobleStrength) : Noble(nobleName), strength(nobleStrength){}
    
    void display() {}
    
    double getStrength(){       //returns the strength the Noble is born with
        return strength;
    }
    
    void setStrength(double newStrength){   //sets the strength to a new strength after battle
        strength = newStrength;
    }
    
    void battle(Noble& theNoble){
        cout << this->getName() << " battles " << theNoble.getName() << endl;
        
        theNoble.display();
        
        if(this->getStrength() == theNoble.getStrength()){
            cout << this->getName() << " and " << theNoble.getName() << " die at each other's hands." << endl;
            theNoble.setStrength(0);
            this -> setStrength(0);
            theNoble.kill();
            this->kill();
        }
        
        else if(this->getStrength() > theNoble.getStrength() && this->doaNoble() == false && theNoble.doaNoble() == false){
            cout << this -> getName() << " defeats " << theNoble.getName() << endl;
            
            double newStrength = (this->getStrength() - theNoble.getStrength());
            this -> setStrength(newStrength);
            
            theNoble.setStrength(0);
            theNoble.kill();
        }
        
        else if(theNoble.getStrength() > this->getStrength() && this->doaNoble() == false && theNoble.doaNoble() == false){
            cout << theNoble.getName() << " defeats " << this->getName() << endl;
            
            double newStrength = ((theNoble.getStrength())*(1-(this->getStrength()/theNoble.getStrength())));
            theNoble.setStrength(newStrength);
            
            this -> setStrength(0);
            this->kill();
        }
        
        else if(theNoble.doaNoble() == true && this -> doaNoble() == true){
            cout << "OH NO! They're both dead." << endl;
        }
        
        else if(this->doaNoble() == true){
            cout << "They're dead, " << theNoble.getName() << endl;
        }
        
        else if(theNoble.doaNoble() == true){
            cout << "They're dead, " << this -> getName() << endl;
        }
    }
    
private:
    double strength;
};

class LordNoble : public Noble {                //A lord Noble is a type of Noble with an army/vector of Protectors
public:
    LordNoble(const string& nobleName) : Noble(nobleName){}
    
    void display() {                                //displays each protectors different battle noise
        for(size_t i = 0; i < protectors.size(); i++){
            protectors[i] -> display();
        }
    }
    
    double getStrength(){           //returns the sum of the army's strength
        int sum = 0;
        for(size_t i = 0; i < protectors.size(); i++){
            sum = sum + protectors[i]->getStrength();
        }
        return sum;
    }
    
    void setStrength(double newStrength){           //loops through vector to set each protectors new strength after battle
        for(size_t i = 0; i < protectors.size(); i++){
            protectors[i] -> setStrength(newStrength);
            if(newStrength == 0){
                protectors[i]->kill();
            }
        }
    }
    
    void hireProtector(Protector& protector){
        if(protector.getEmpStatus() == false && this->doaNoble() == false && protector.doaProtector() == false){
            protector.setStatus(true);
            protector.setBoss(this);
            protectors.push_back(&protector);
        }
    }
    
    void battle(Noble& theNoble){
        cout << this->getName() << " battles " << theNoble.getName() << endl;
        
        this -> display();
        
        if(this->getStrength() == theNoble.getStrength() && this->doaNoble() == false && theNoble.doaNoble() == false){
            cout << this->getName() << " and " << theNoble.getName() << " die at each other's hands." << endl;
            theNoble.setStrength(0);
            this -> setStrength(0);
            theNoble.kill();
            this->kill();
        }
        
        else if(this->getStrength() > theNoble.getStrength() && this->doaNoble() == false && theNoble.doaNoble() == false){
            cout << this -> getName() << " defeats " << theNoble.getName() << endl;
        
                double newStrength = ((this->getStrength())*(1-(theNoble.getStrength()/this->getStrength())));
                this -> setStrength(newStrength);
            
            theNoble.setStrength(0);
            theNoble.kill();
        }
        
        else if(theNoble.getStrength() > this->getStrength() && this->doaNoble() == false && theNoble.doaNoble() == false){
            cout << theNoble.getName() << " defeats " << this->getName() << endl;
            
                double newStrength = (theNoble.getStrength() - this->getStrength());
                theNoble.setStrength(newStrength);
            
            this -> setStrength(0);
            this->kill();
        }
        
        else if(theNoble.doaNoble() == true && this -> doaNoble() == true){
            cout << "OH NO! They're both dead." << endl;
        }
        
        else if(theNoble.doaNoble() == true){
            cout << "They're dead, " << this->getName() << endl;
        }
        
        else if(this->doaNoble() == true){
            cout << "They're dead, " << theNoble.getName() << endl;
        }
    }
    
private:
    vector<Protector*> protectors;
};

int main(){
    LordNoble sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hireProtector(samantha);
    LordNoble joe("Joe");
    StrongNoble randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    LordNoble janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hireProtector(hardy);
    janet.hireProtector(stout);
    StrongNoble barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hireProtector(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hireProtector(pethora);
    janet.hireProtector(thora);
    sam.hireProtector(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
    
}