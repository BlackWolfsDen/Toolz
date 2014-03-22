// Enter file contents here
// another stupid lil tool from the mad scientist of Emudevs.com slp13at420
// creates player level stats for level a to level z

#include <iostream>
#include <fstream>

using namespace std;

int race,cclass,lvls,str,agi,sta,inte,spi,l;
float strm,agim,stam,intem,spim;
int lvle=255;
int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a player_LevelStats values from level x to lvl x in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n";
    cout<<"this will take some time for you to create each and every combination race/class.\n";
    cout<<"use this to populate the unpopulated levels of player_LevelStats for a better lvl 255 experience.\n";

    cout<<"\nPlayer Race ID's:";
    cout<<"\n(1=Human) (2=Orc) (3=Dwarf) (4=Night Elf) (5=Undead)";
    cout<<"\n(6=Tauren)(7=Gnome) (8=Troll) (10=Blood Elf) (11=Draenei)\n";
    cout<<"\nEnter Race Id: ";
    cin>>race;
    cin.ignore();

    cout<<"\nPlayer Class ID's:";
    cout<<"\n(1=Warrior) (2=Paladin) (3=Hunter) (4=Rogue) (5=Priest)";
    cout<<"\n(6=Death Knight)(7=Shaman) (9=Mage) (10=Warlock) (11=Druid)\n";
    cout<<"\nEnter Class Id: ";
    cin>>cclass;
    cin.ignore();

    cout<<"\nEnter level Start: ";
    cin>>lvls;
    cin.ignore();

    cout<<"\nEnter Agility Start: ";
    cin>>agi;
    cin.ignore();

    cout<<"\nEnter Agility % modifier x.xxxx: ";
    cin>>agim;
    cin.ignore();

    cout<<"\nEnter Stamina Start: ";
    cin>>sta;
    cin.ignore();
    cout<<"\nEnter Stamina % modifier x.xxxx: ";
    cin>>stam;
    cin.ignore();

    cout<<"\nEnter Intellect Start: ";
    cin>>inte;
    cin.ignore();
    cout<<"\nEnter Intellect % modifier x.xxxx: ";
    cin>>intem;
    cin.ignore();

    cout<<"\nEnter Spirit Start: ";
    cin>>spi;
    cin.ignore();
    cout<<"\nEnter Spirit % modifier x.xxxx: ";
    cin>>spim;
    cin.ignore();

    ofstream SQLfile;
        SQLfile.open ("Player_LevelStats.sql");
        SQLfile << "REPLACE INTO `player_levelstats` (`race`, `class`, `level`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES\n";
        SQLfile <<"\n-- Race "<< race <<" Class "<< cclass <<" levels: "<< lvls <<"-"<< lvle <<"";

            for(l=lvls;l<=lvle;l=l+1)
            {
                SQLfile << ",\n("<< race <<", "<< cclass <<", "<< l <<", "<< str <<", "<< agi <<", "<< sta <<", "<< inte <<", "<< spi <<")";
                str=(str+(str*strm));
                agi=(agi+(agi*agim));
                sta=(sta+(sta*stam));
                inte=(inte+(inte*intem));
                spi=(spi+(spi*spim));
          }

    SQLfile << ";\n";
    SQLfile.close();

return 0;

}
