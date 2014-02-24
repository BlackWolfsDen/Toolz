// another stupid lil tool from the mad scientist of emudevs.com slp13at420
// this will create an sql of creatur class level stats. 1 class at a time
// just enter data and poof an sqll file in you working /dir/.

#include <iostream>
#include <fstream>

using namespace std;

int l,lvls,cclass;
int hpa[3]={0,0,0};
int hpb[3]={0,0,0};
int hpc[3]={0,0,0};
int mana[3]={0,0,0};
int armor[3]={0,0,0};
int matp[3]={0,0,0};
int ratp[3]={0,0,0};
int damageB[3]={0,0,0};
int lvlf=255;
int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a Creature level stat values from xxx up to 255 in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";
    cout<<"use this to populate the unpopulated levels of creatures for a better lvl 255 experience.\n";
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
    hpa[2]=((hpa[1]-hpa[0])/(lvlf-lvls));

    cout<<"Base HP 1 start value: ";
    cin>>hpb[0];
    cin.ignore();
    cout<<"Base HP 1 max value: ";
    cin>>hpb[1];
    cin.ignore();
    hpb[2]=((hpb[1]-hpb[0])/(lvlf-lvls));

    cout<<"Base HP 2 start value: ";
    cin>>hpc[0];
    cin.ignore();
    cout<<"Base HP 2 max value: ";
    cin>>hpc[1];
    cin.ignore();
    hpc[2]=((hpc[1]-hpc[0])/(lvlf-lvls));

    cout<<"Base Mana start value: ";
    cin>>mana[0];
    cin.ignore();
    cout<<"Base Mana max value: ";
    cin>>mana[1];
    cin.ignore();
    mana[2]=((mana[1]-mana[0])/(lvlf-lvls));

    cout<<"Base Armor start value: ";
    cin>>armor[0];
    cin.ignore();
    cout<<"Base armor max value: ";
    cin>>armor[1];
    cin.ignore();
    armor[2]=((armor[1]-armor[0])/(lvlf-lvls));

    cout<<"Base melee Attack power Start value: ";
    cin>>matp[0];
    cin.ignore();
    cout<<"Base melee Attack power MAX value: ";
    cin>>matp[1];
    cin.ignore();
    matp[2]=((matp[1]-matp[0])/(lvlf-lvls));

    cout<<"Base range Attack power Start value: ";
    cin>>ratp[0];
    cin.ignore();
    cout<<"Base range Attack power MAX value: ";
    cin>>ratp[1];
    cin.ignore();
    ratp[2]=((ratp[1]-ratp[0])/(lvlf-lvls));

    cout<<"Base damage Start value: ";
    cin>>damageB[0];
    cin.ignore();
    cout<<"Base damage MAX value: ";
    cin>>damageB[1];
    cin.ignore();
    damageB[2]=((damageB[1]-damageB[0])/(lvlf-lvls));

    ofstream SQLfile;
    SQLfile.open ("Creature_Class_Stats.sql");
    SQLfile << "REPLACE INTO `creature_classlevelstats` (`level`, `class`, `basehp0`, `basehp1`, `basehp2`, `basemana`, `basearmor`, `attackpower`, `rangedattackpower`, `damage_base`) VALUES\n";
    SQLfile <<"\n-- Class "<< cclass <<" levels: "<< lvls <<"-"<< lvlf <<"";

        for(l=lvls;l<=lvlf;l=l+1)
           {
                SQLfile << ",\n("<< l <<", "<< cclass <<", "<< hpa[0] <<", "<< hpb[0] <<", "<< hpc[0] <<", "<< mana[0] <<", "<< armor[0] <<", "<< matp[0] <<", "<< ratp[0] <<", "<< damageB[0] <<")";
                hpa[0]=(hpa[0]+hpa[2]);
                hpb[0]=(hpb[0]+hpb[2]);
                hpc[0]=(hpc[0]+hpc[2]);
                mana[0]=(mana[0]+mana[2]);
                armor[0]=(armor[0]+armor[2]);
                matp[0]=(matp[0]+matp[2]);
                ratp[0]=(ratp[0]+ratp[2]);
                damageB[0]=(damageB[0]+damageB[2]);
           }
    SQLfile << ";\n";
    SQLfile.close();

return 0;

}
