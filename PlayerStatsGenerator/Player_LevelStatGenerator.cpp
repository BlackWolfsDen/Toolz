// another stupid lil tool from the mad scientist of Emudevs.com slp13at420
// creates player level stats for level a to level z

#include <iostream>
#include <fstream>

using namespace std;

int race,cclass,lvls,lvlf,strs,strf,strm,agis,agif,agim,stas,staf,stam,intes,intef,intem,spis,spif,spim,l;

int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a player_LevelStats values from level x to lvl xxx in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";
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

    cout<<"\nEnter level finish: ";
    cin>>lvlf;
    cin.ignore();

    cout<<"\nEnter strength Start: ";
    cin>>strs;
    cin.ignore();
    cout<<"Enter strength end: ";
    cin>>strf;
    cin.ignore();
    strm=((strf-strs)/((lvlf-lvls)-1));

    cout<<"\nEnter Agility Start: ";
    cin>>agis;
    cin.ignore();
    cout<<"Enter Agility end: ";
    cin>>agif;
    cin.ignore();
    agim=((agif-agis)/((lvlf-lvls)-1));

    cout<<"\nEnter Stamina Start: ";
    cin>>stas;
    cin.ignore();
    cout<<"Enter Stamina end: ";
    cin>>staf;
    cin.ignore();
    stam=((staf-stas)/((lvlf-lvls)-1));

    cout<<"\nEnter Intellect Start: ";
    cin>>intes;
    cin.ignore();
    cout<<"Enter Intellect end: ";
    cin>>intef;
    cin.ignore();
    intem=((intef-intes)/((lvlf-lvls)-1));

    cout<<"\nEnter Spirit Start: ";
    cin>>spis;
    cin.ignore();
    cout<<"Enter Spirit end: ";
    cin>>spif;
    cin.ignore();
    spim=((spif-spis)/((lvlf-lvls)-1));

    ofstream SQLfile;
        SQLfile.open ("Player_LevelStats.sql");
        SQLfile << "REPLACE INTO `player_levelstats` (`race`, `class`, `level`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES\n";
        SQLfile <<"\n-- Race "<< race <<" Class "<< cclass <<" levels: "<< lvls <<"-"<< lvlf <<"";

            for(l=lvls;l<=lvlf;l=l+1)
            {
                SQLfile << ",\n("<< race <<", "<< cclass <<", "<< l <<", "<< strs <<", "<< agis <<", "<< stas <<", "<< intes <<", "<< spis <<")";
                strs=(strs+strm);
                agis=(agis+agim);
                stas=(stas+stam);
                intes=(intes+intem);
                spis=(spis+spim);
          }

    SQLfile << ";\n";
    SQLfile.close();

return 0;

}
