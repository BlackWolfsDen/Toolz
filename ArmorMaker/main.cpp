#include <iostream>

using namespace std;
int main()

{
    int EntryIdStrt;
    int Tiers;
    int Pclass;
    int8_t Tclass;
    cout<<"Hello noob!\n";
    cout<<"Welcome to a stupid little tool.\n";
    cout<<"Enter Starting Id for Item entry Id:";
    cin>>EntryIdStrt;
    cin.ignore();
//    cout<<"Starting entryID: "<<EntryIdStrt<<"\n";
    cout<<"How many tiers(bundles):";
    cin>>Tiers;
   cin.ignore();
  //   cout<<"Tiers: "<<Tiers<<"\n";
    cout<<"Player Class6(1-10):";
    cin>>Pclass;
    cin.ignore();

struct Tclass
{
    uint8_t Classid, Cbitmask;
    std::string Classname;
    uint8_t Carmorbit;
};

Tclass Xclass [] =
{
{1, 1, "Warrior", 4 },
{2, 2, "Paladin", 4 },
{3, 4, "Hunter", 3 },
{4, 8, "Rogue", 2 },
{5, 16, "Priest", 1 },
{6, 32, "DeathKnight", 4 },
{7, 64, "Shaman", 3 },
{8, 128, "Mage", 1 },
{9, 256, "Warlock", 1 },
{10, 1024, "Druid", 2 },
};

}
