//
//  Noble.h
//  hw07
//
//  Created by Victoria Spann-Burton on 3/29/16.
//  Copyright © 2016 Victoria Spann-Burton. All rights reserved.
//

#ifndef Noble_h
#define Noble_h
#include <string>
#include <vector>

namespace WarriorCraft {   //Warrior namespace
    class Warrior;        //Warrior class declaration
    
    class Noble{            //Noble class method prototypes
    public:
        Noble(const std::string& nName);
        std::string getName()const;
        double getArmyStrength()const;
        std::string getArmyStats()const;
        size_t getArmySize()const;
        void setWarriorStrength(double newStrength);
        void fire(Warrior& theWarrior);
        void hire(Warrior& theWarrior);
        void battle(Noble& theNoble);
        void kill();
        bool dead();
        
    private:
        std::string name;
        std::vector<Warrior*> army;
        bool deadNoble;
    };
    
    std::ostream& operator<<(std::ostream& os, const Noble& n);  //operator overload ostream
}




#endif /* Noble_h */
