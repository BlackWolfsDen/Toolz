#include <iostream>
#include <fstream>

using namespace std;

int lvls,lvlf,xps,xpf,l;

int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a player exp for level values from x up to xxx in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql edit to fine tune then grind it in. have fun :D\n\n";
    cout<<"use this to populate the unpopulated levels of needed experience for a better lvl 255 experience.\n";

    cout<<"\n\n lvl start value: ";
    cin>>lvls;
    cin.ignore();

    cout<<"\n\n lvl end value: ";
    cin>>lvlf;
    cin.ignore();

    cout<<"\n\n Experience start value: ";
    cin>>xps;
    cin.ignore();

    cout<<"\n Experiance end value: ";
    cin>>xpf;
    cin.ignore();
    int xpr=xps;

    ofstream SQLfile;
    SQLfile.open ("player_xp_for_level.sql");
    SQLfile << "REPLACE INTO `player_xp_for_level` (`lvl`, `xp_for_next_level`) VALUES\n";
    SQLfile <<"\n-- ";
            for(l=lvls;l<=lvlf;l=l+1)
            {
                 SQLfile << ",\n("<< l <<", "<< xpr <<")";
                 xpr=xpr+((xpf-xps)/(lvlf-lvls));

            }
    SQLfile << ";\n";
    SQLfile.close();

return 0;

}

