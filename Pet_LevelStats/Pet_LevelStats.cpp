// another stupid lil tool from the mad scientist of Emudevs.com slp13at420
// creates pet level stats for level a to level z

#include <iostream>
#include <fstream>

using namespace std;

int pet,lvls,lvlf,armors,armorf,hps,hpf,manas,manaf,strs,strf,agis,agif,stas,staf,intes,intef,spis,spif,l;

int main()
{
    cout<<"Hello noob!\n";
    cout<<"slp13at420 of EmuDevs.com here with another stupid lil tool for the stonerz tool box.\n";
    cout<<"This will belch out a Pet_LevelStats values from level x to lvl xxx in an sql file.\n";
    cout<<"fill in the blanks and it it will make a file in working /dir\n";
    cout<<"open the sql to grind it in. have fun :D\n\n";
    cout<<"use this to populate the unpopulated levels of Pet_LevelStats for a better lvl 255 experience.\n";
    cout<<"I recommend you refer to your db for the proper pet IDs.\n";

    cout<<"\nPet ID:";
    cin>>pet;
    cin.ignore();

    cout<<"\nEnter level Start: ";
    cin>>lvls;
    cin.ignore();

    cout<<"\nEnter level finish: ";
    cin>>lvlf;
    cin.ignore();

    cout<<"\nEnter HP Start: ";
    cin>>hps;
    cin.ignore();
    int hpv=hps;
    cout<<"\nEnter HP finish: ";
    cin>>hpf;
    cin.ignore();

    cout<<"\nEnter Mana Start: ";
    cin>>manas;
    cin.ignore();
    int manav=manas;
    cout<<"\nEnter Mana finish: ";
    cin>>manaf;
    cin.ignore();

    cout<<"\nEnter Armor Start: ";
    cin>>armors;
    cin.ignore();
    int armorv=armors;
    cout<<"\nEnter Armor finish: ";
    cin>>armorf;
    cin.ignore();

    cout<<"\nEnter Strength Start: ";
    cin>>strs;
    cin.ignore();
    int strv=strs;
    cout<<"\nEnter Strength finish: ";
    cin>>strf;
    cin.ignore();

    cout<<"\nEnter Agility Start: ";
    cin>>agis;
    cin.ignore();
    int agiv=agis;
    cout<<"\nEnter Agility finish: ";
    cin>>agif;
    cin.ignore();

    cout<<"\nEnter Stamina Start: ";
    cin>>stas;
    cin.ignore();
    int stav=stas;
    cout<<"\nEnter Stamina finish: ";
    cin>>staf;
    cin.ignore();

    cout<<"\nEnter Intellect Start: ";
    cin>>intes;
    cin.ignore();
    int intev=intes;
    cout<<"\nEnter Intellect finish: ";
    cin>>intef;
    cin.ignore();

    cout<<"\nEnter Spirit Start: ";
    cin>>spis;
    cin.ignore();
    int spiv=spis;
    cout<<"\nEnter Spirit finish: ";
    cin>>spif;
    cin.ignore();

    ofstream SQLfile;
        SQLfile.open ("Pet_LevelStats.sql");
        SQLfile << "REPLACE INTO `pet_levelstats` (`creature_entry`, `level`, `hp`, `mana`, `armor`, `str`, `agi`, `sta`, `inte`, `spi`) VALUES\n";
        SQLfile <<"\n-- creature "<< pet <<" level "<< lvls <<"-"<< lvlf <<"";

            for(l=lvls;l<=lvlf;l=l+1)
            {
                SQLfile << ",\n("<< pet <<", "<< l <<", "<< hpv <<", "<< manav <<", "<< armorv <<", "<< strv <<", "<< agiv <<", "<< stav <<", "<< intev <<", "<< spiv <<")";

                hpv=hpv+((hpf-hps)/(lvlf-lvls));
                manav=manav+((manaf-manas)/(lvlf-lvls));
                armorv=armorv+((armorf-armors)/(lvlf-lvls));
                strv=strv+((strf-strs)/(lvlf-lvls));
                agiv=agiv+((agif-agis)/(lvlf-lvls));
                stav=stav+((staf-stas)/(lvlf-lvls));
                intev=intev+((intef-intes)/(lvlf-lvls));
                spiv=spiv+((spif*spis)/(lvlf-lvls));
          }

    SQLfile << ";\n";
    SQLfile.close();

return 0;

}







