#include <iostream>

using namespace std;

int Statcnt;
int a;
int ClassName[10][3];
int DispId[10][8];
int InvData[8][2];
int StatData[10][4];

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
            cout<<"Stat type: ";
            cin>>StatData[a][1];
            cin.ignore();
            cout<<"Stat "<< a <<"  start Minimum amount: ";
            cin>>StatData[a][2];
            cin.ignore();
            cout<<"Stat "<< a <<" end Maximum amount: ";
            cin>>StatData[a][3];
            cin.ignore();
            StatData[a][4]=StatData[a][3]/Tiers;
        }
};

