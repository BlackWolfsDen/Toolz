#include <iostream>
#include <fstream>

using namespace std;

int lvls,class,hp0,hp1,hp2,mana,armor; // attackpower,rangeattackpower,damagebase;

int main()
{
    cout<<"Hello noob!\n";
    cout<<"Welcome to my stupid little tool.\n\n";
    cout<<"This will belch out a Creature level stat values from 80 up to 255 in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";

    cout<<"(1=Warrior ::2=Paladin ::4=Rogue ::8=Mage)";
    cout<<"Enter Class Id: ";
    cin>>class;
    cin.ignore();

    cout<<"Start level: ";
    cin>>lvls;
    cin.ignore();

    cout<<"Base HP 0 start value: ";
    cin>>hp0;
    cin.ignore();

    cout<<"Base HP 1 start value: ";
    cin>>hp1;
    cin.ignore();

    cout<<"Base HP 2 start value: ";
    cin>>hp2;
    cin.ignore();

    cout<<"Base Mana start value: ";
    cin>>mana;
    cin.ignore();

    cout<<"Base Armor start value: ";
    cin>>armor;
    cin.ignore();

    ofstream SQLfile;
    SQLfile.open ("Creature_Class_Stats.sql");
    SQLfile << "REPLACE INTO `creature_classlevelstats` (`level`, `class`, `basehp0`, `basehp1`, `basehp2`, `basemana`, `basearmor`) VALUES\n\n";
    SQLfile <<"\n--Class "<< class <<" levels: "<< lvls <<"-255";

        for(l=lvls;l<=255;l=l+1)
           {
                SQLfile << ",\n("<< l <<", "<< class <<", "<< hp0 <<", "<< hp1 <<", "<< hp2 <<", "<< mana <<"', "<< armor <<")";
                hp0=(hp0+(hp0*.20))
                hp1=(hp1+(hp1*.20))
                hp2=(hp2+(hp2*.20))
                mana=(mana+(mana*.20))
                armor=(armor+(armor*.20))
           }
    SQLfile << ";\n";
    SQLfile.close();

return 0;

}
