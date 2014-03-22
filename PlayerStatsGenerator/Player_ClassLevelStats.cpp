// another stupid lil tool from the mad scientist of emudevs.com slp13at420
// this will create an sql of creatur class level stats. 1 class at a time
// just enter data and poof an sqll file in you working /dir/.

#include <iostream>
#include <fstream>

using namespace std;

int cclass,lvls,lvlf,hps,hpf,manas,manaf,l,bhp,bmn;

int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a player class level stat values from lvl x to xxx in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";
    cout<<"use this to populate the unpopulated levels of creatures for a better lvl 255 experience.\n";
    cout<<"(1=Warrior ::2=Paladin ::3=Hunter ::4=Rogue ::5=Priest ::6=DK ::7=Shaman ::8=Mage ::9=Warlock ::11=Druid)\n";

    cout<<"Enter Class Id: ";
    cin>>cclass;
    cin.ignore();

    cout<<"Enter start Level: ";
    cin>>lvls;
    cin.ignore();

    cout<<"Enter end Level: ";
    cin>>lvlf;
    cin.ignore();

    cout<<"Enter start HP: ";
    cin>>hps;
    cin.ignore();
    bhp=hps;

    cout<<"Enter end HP: ";
    cin>>hpf;
    cin.ignore();

    cout<<"Enter start Mana: ";
    cin>>manas;
    cin.ignore();
    bmn=manas;

    cout<<"Enter end Mana: ";
    cin>>manaf;
    cin.ignore();

    ofstream SQLfile;
    SQLfile.open ("Player_Class_Level_Stats.sql");
    SQLfile << "REPLACE INTO `player_classlevelstats` (`class`, `level`, `basehp`, `basemana`) VALUES\n";
    SQLfile <<"\n-- Class "<< cclass <<" levels: "<< lvls <<"-"<< lvlf <<"";

        for(l=lvls;l<=lvlf;l=l+1)
           {
                SQLfile << ",\n("<< cclass <<", "<< l <<", "<< bhp <<", "<< bmn <<")";
                bhp=bhp+((hpf-hps)/(lvlf-lvls));
                bmn=bmn+((manaf-manas)/(lvlf-lvls));
           }
    SQLfile << ";\n";
    SQLfile.close();

return 0;

}


