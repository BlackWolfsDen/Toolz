-- another stupid lil tool from the mad scientist @ emudevs.com slp13at420
-- this will create an sql of creatur class level stats. 1 class at a time 
-- just enter data and poof an sqll file in you working /dir/.
-- you may need to change some column unassigned or Datatype for higher values.

#include <iostream>
#include <fstream>

using namespace std;

int l,lvls,cclass;
int hpa[3]={0,0,0};
int hpb[3]={0,0,0};
int hpc[3]={0,0,0};
int mana[3]={0,0,0};
int armor[3]={0,0,0};
int main()
{
    cout<<"Hello noob!\n";
    cout<<"Welcome to my stupid little tool.\n\n";
    cout<<"This will belch out a Creature level stat values from 80 up to 255 in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";

    cout<<"(1=Warrior ::2=Paladin ::4=Rogue ::8=Mage)";
    cout<<"Enter Class Id: ";
    cin>>cclass;
    cin.ignore();

    cout<<"Start level: ";
    cin>>lvls;
    cin.ignore();

    cout<<"Base HP 0 start value: ";
    cin>>hpa[0];
    cin.ignore();
    cout<<"Base HP 0 max value: ";
    cin>>hpa[1];
    cin.ignore();
    hpa[2]=((hpa[1]-hpa[0])/(255-lvls));

    cout<<"Base HP 1 start value: ";
    cin>>hpb[0];
    cin.ignore();
    cout<<"Base HP 1 max value: ";
    cin>>hpb[1];
    cin.ignore();
    hpb[2]=((hpb[1]-hpb[0])/(255-lvls));

    cout<<"Base HP 2 start value: ";
    cin>>hpc[0];
    cin.ignore();
    cout<<"Base HP 2 max value: ";
    cin>>hpc[1];
    cin.ignore();
    hpc[2]=((hpc[1]-hpc[0])/(255-lvls));

    cout<<"Base Mana start value: ";
    cin>>mana[0];
    cin.ignore();
    cout<<"Base Mana max value: ";
    cin>>mana[1];
    cin.ignore();
    mana[2]=((mana[1]-mana[0])/(255-lvls));

    cout<<"Base Armor start value: ";
    cin>>armor[0];
    cin.ignore();
    cout<<"Base armor max value: ";
    cin>>armor[1];
    cin.ignore();
    armor[2]=((armor[1]-armor[0])/(255-lvls));

    ofstream SQLfile;
    SQLfile.open ("Creature_Class_Stats.sql");
    SQLfile << "REPLACE INTO `creature_classlevelstats` (`level`, `class`, `basehp0`, `basehp1`, `basehp2`, `basemana`, `basearmor`) VALUES\n\n";
    SQLfile <<"\n--Class "<< cclass <<" levels: "<< lvls <<"-255";

        for(l=lvls;l<=255;l=l+1)
           {
                SQLfile << ",\n("<< l <<", "<< cclass <<", "<< hpa[0] <<", "<< hpb[0] <<", "<< hpc[0] <<", "<< mana[0] <<", "<< armor[0] <<")";
                hpa[0]=(hpa[0]+hpa[2]);
                hpb[0]=(hpb[0]+hpb[2]);
                hpc[0]=(hpc[0]+hpc[2]);
                mana[0]=(mana[0]+mana[2]);
                armor[0]=(armor[0]+armor[2]);
           }
    SQLfile << ";\n";
    SQLfile.close();

return 0;

}
