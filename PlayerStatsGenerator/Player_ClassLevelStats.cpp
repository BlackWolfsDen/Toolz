// another stupid lil tool from the mad scientist of Emudevs.com slp13at420
// creates player class stats for level a to level z (health and mana)
// testing for level 1-80 health i found 0.08438 for modifier is kinda close to blizzlike kinda
// but i set this up so you may do small blocks for fine tuning the level curve.

#include <iostream>
#include <fstream>

using namespace std;

int cclass,lvls,lvle,bhp,bm,l;
float bhpm,bmm;
int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a player class level stats values from level x to lvl x in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";
    cout<<"use this to populate the unpopulated levels of player class(health,mana) for a better lvl 255 experience.\n";

    cout<<"\nPlayer Class ID's:";
    cout<<"\n(1=Warrior) (2=Paladin) (3=Hunter) (4=Rogue) (5=Priest)";
    cout<<"\n(6=Death Knight)(7=Shaman) (8=Mage) (9=Warlock) (11=Druid)\n";

    cout<<"\nEnter Class Id: ";
    cin>>cclass;
    cin.ignore();

    cout<<"\nStart level: ";
    cin>>lvls;
    cin.ignore();
    cout<<"Stop level: ";
    cin>>lvle;
    cin.ignore();

    cout<<"\nBase HP start value: ";
    cin>>bhp;
    cin.ignore();
    cout<<"HP % modifier(~0.08438) value: ";
    cin>>bhpm;
    cin.ignore();

    cout<<"\nBase mana start value: ";
    cin>>bm;
    cin.ignore();

    cout<<"Mana % modifier(~0.08438) value: ";
    cin>>bmm;
    cin.ignore();

    ofstream SQLfile;
        SQLfile.open ("player_ClasslevelStats.sql");
        SQLfile << "REPLACE INTO `player_classlevelstats` (`class`, `level`, `basehp`, `basemana`) VALUES\n";
        SQLfile <<"\n-- Class "<< cclass <<" levels: "<< lvls <<"-"<< lvle <<"";

            for(l=lvls;l<=lvle;l=l+1)
            {
                SQLfile << ",\n("<< cclass <<", "<< l <<", "<< bhp <<", "<< bm <<")";
                bhp=(bhp+(bhp*bhpm));
                bm=(bm+(bm*bmm));
            }

    SQLfile << ";\n";
    SQLfile.close();

return 0;

}

