#include <iostream>
#include <fstream>

using namespace std;

int Statcnt;
int a;
int t;
int EntryIdStrt;
int Tiers;
int Pclass;
int Armor;
int DispId[11][8]={
{1,2,3,4,5,6,7,8},
{1111,1112,1113,1114,1115,1116,1117,1118},
{2221,2222,2223,2224,2225,2226,2227,2228},
{3221,3222,3223,3224,3225,3226,3227,3228},
{4221,4422,4443,4444,4445,4446,4447,4448},
{5551,5552,5553,5554,5555,5556,5557,5558},
{6661,6662,6663,6664,6665,6666,6667,6668},
{7771,7772,7773,7774,7775,7776,7777,7778},
{8881,8882,8883,8884,8885,8886,8887,8888},
{9991,9992,9993,9994,9995,9996,9997,9998},
{1011,1012,1013,1014,1015,1016,1017,1018}
		};
int InvData[9]={0,1,3,5,6,7,8,9,10};
char InvName[8][10]={{"Head"},{"Shoulder"},{"Chest"},{"Waist"},{"legs"},{"Feet"},{"Wrists"},{"Hands"}};
char ClassName[11][12]={{""},{"Warrior"},{"Paladin"},{"Hunter"},{"Rogue"},{"Priest"},{"DeathKnight"},{"Shaman"},{"Mage"},{"Warlock"},{"Druid"}};
int ClassData[11][2]={{0,0},{1,4},{2,4},{4,3},{8,2},{16,1},{32,4},{64,3},{128,1},{256,1},{1024,2}};
int StatData[11][4]={{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

int main()
{
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
    cout<<"Armor Items Level: ";
    cin>>Armor;
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
            cout<<"Stat "<< a <<" Minimum amount: ";
            cin>>StatData[a][2];
            cin.ignore();
            cout<<"Stat "<< a <<" Maximum amount: ";
            cin>>StatData[a][3];
            cin.ignore();
            StatData[a][4]=StatData[a][3]/Tiers;
            cout<<""<< StatData[a][4] <<"\n";
        }
  ofstream SQLfile;
  SQLfile.open ("Armor.sql");
  SQLfile << "REPLACE INTO `item_template` (`entry`, `class`, `subclass`, `name`, `displayid`, `Quality`, `BuyCount`, `InventoryType`, `AllowableClass`, `ItemLevel`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `armor`, `socketColor_1`, `socketColor_2`, `socketColor_3`) VALUES\n\n";
            for(t=1;t<=Tiers;t=t+1)
                SQLfile <<"Tier-"<< t <<"\n";
  SQLfile.close();
  return 0;

};

