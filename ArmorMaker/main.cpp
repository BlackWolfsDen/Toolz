#include <iostream>

using namespace std;

int Statcnt;
int a;
int DispId[10][8];
int InvData[8][2];
int StatData[10][4];
char ClassName[11][12]={{""},{"Warrior"},{"Paladin"},{"Hunter"},{"Rogue"},{"Priest"},{"DeathKnight"},{"Shaman"},{"Mage"},{"Warlock"},{"Druid"}};
int ClassData[11][2]={{0,0},{1,4},{2,4},{4,3},{8,2},{16,1},{32,4},{64,3},{128,1},{256,1},{1024,2}};

int main()
{
    int EntryIdStrt;
    int Tiers;
    int Pclass;
    int Tclass;
    cout<<"Hello noob!\n";
    cout<<"Welcome to a stupid little tool.\n";
    cout<<"Enter Starting Id for Item entry Id: ";
    cin>>EntryIdStrt;
    cin.ignore();
    cout<<"How many tiers(bundles): ";
    cin>>Tiers;
    cin.ignore();
    cout<<"Player Class(1-10): ";
    cin>>Pclass;
    cin.ignore();
    cout<<"How many Stats(max 10): ";
    cin>>Statcnt;
    cin.ignore();
         for(a=1;a<=Statcnt;a=a+1)
         {
            cout<<"Class "<< ClassName[Pclass] <<"\n";
            cout<<"Stat "<< a <<" type: ";
            cin>>StatData[a][1];
            cin.ignore();
            cout<<"Stat "<< a <<"  start Minimum amount: ";
            cin>>StatData[a][2];
            cin.ignore();
            cout<<"Stat "<< a <<" end Maximum amount: ";
            cin>>StatData[a][3];
            cin.ignore();
            StatData[a][4]=StatData[a][3]/Tiers;
            cout<<""<< StatData[a][4] <<"\n";
        }

};

