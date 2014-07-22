-- by slp13at420 of Emudevs.com for blackwolfsden.dyndns-free.com
-- this will build full armor set tier by tier with scaled stats
-- only does 1 class at a time and then restart to do next class
-- could be modified to use input live ingame to build each class without restarting
-- maybe if i dont get too high and ... wander  .....off......
local Start = 500000 -- item Id start point
local Class = 1 --(value 1-10 of ClassName)
local Tiers = 2 --(how many to make. math minimum is 1 :: MAX = 10)
	if(Tiers > 10)then -- math'd for up to only 10 tiers per class
		Tiers = 10
	end
local Level = 80 -- item level
local Statcnt = 10 -- how many stats
local Stat1 = 32 -- stat type value
local Stat1a = 1000 -- stat value start(lowest value for stat scaling)
local Stat1z = 10000 -- stat value for finish(highest value for stat scaling)
local Stat1stp = (Stat1z/Tiers)
local Stat2 = 0 -- stat type value
local Stat2a = 0 -- stat value start(lowest value for stat scaling)
local Stat2z = 0 -- stat value for finish(highest value for stat scaling)
local Stat2stp = (Stat2z/Tiers)
local Stat3 = 0 -- stat type value
local Stat3a = 0 -- stat value start(lowest value for stat scaling)
local Stat3z = 0 -- stat value for finish(highest value for stat scaling)
local Stat3stp = (Stat3z/Tiers)
local Stat4 = 0 -- stat type value
local Stat4a = 0 -- stat value start(lowest value for stat scaling)
local Stat4z = 0 -- stat value for finish(highest value for stat scaling)
local Stat4stp = (Stat4z/Tiers)
local Stat5 = 0 -- stat type value
local Stat5a = 0 -- stat value start(lowest value for stat scaling)
local Stat5z = 0 -- stat value for finish(highest value for stat scaling)
local Stat5stp = (Stat5z/Tiers)
local Stat6 = 0 -- stat type value
local Stat6a = 0 -- stat value start(lowest value for stat scaling)
local Stat6z = 0 -- stat value for finish(highest value for stat scaling)
local Stat6stp = (Stat6z/Tiers)
local Stat7 = 0 -- stat type value
local Stat7a = 0 -- stat value start(lowest value for stat scaling)
local Stat7z = 0 -- stat value for finish(highest value for stat scaling)
local Stat7stp = (Stat7z/Tiers)
local Stat8 = 0 -- stat type value
local Stat8a = 0 -- stat value start(lowest value for stat scaling)
local Stat8z = 0 -- stat value for finish(highest value for stat scaling)
local Stat8stp = (Stat8z/Tiers)
local Stat9 = 0 -- stat type value
local Stat9a = 0 -- stat value start(lowest value for stat scaling)
local Stat9z = 0 -- stat value for finish(highest value for stat scaling)
local Stat9stp = (Stat9z/Tiers)
local Stat10 = 0 -- stat type value
local Stat10a = 0 -- stat value start(lowest value for stat scaling)
local Stat10z = 0 -- stat value for finish(highest value for stat scaling)
local Stat10stp = (Stat10z/Tiers)
local ItemClass = 4
local Quality = 4
local Armora = 1000 -- armor minimum
local Armorz = 10000 -- armor max
local Armorstp = (Armorz/Tiers)
local Socket1 = 1 -- socket type
local Socket2 = 1
local Socket3 = 1
-- step = tier 1 - 10, display id by inv data - head, shoulder, chest,........etc
-- this is where you will input your display ids for no more than 10 tiers
DispId = {};
DispId = {
	[1] = {1111,1112,1113,1114,1115,1116,1117,1118},
	[2] = {2221,2222,2223,2224,2225,2226,2227,2228},
	[3] = {3221,3222,3223,3224,3225,3226,3227,3228},
	[4] = {4221,4422,4443,4444,4445,4446,4447,4448},
	[5] = {5551,5552,5553,5554,5555,5556,5557,5558},
	[6] = {6661,6662,6663,6664,6665,6666,6667,6668},
	[7] = {7771,7772,7773,7774,7775,7776,7777,7778},
	[8] = {8881,8882,8883,8884,8885,8886,8887,8888},
	[9] = {9991,9992,9993,9994,9995,9996,9997,9998},
	[10] = {1011,1012,1013,1014,1015,1016,1017,1018}
		};
-- no touchy touchy
-- enter base item display ids in next table
-- step = invtype, disp id(this will apply to all tiers of that slot item) name
Invdata = {};
Invdata = {
	[1] = {1,"head"},
	[2] = {3,"shoulder"},
	[3] = {5,"chest"},
	[4] = {6,"waist"},
	[5] = {7,"legs"},
	[6] = {8,"feet"},
	[7] = {9,"wrists"},
	[8] = {10,"hands"}
		};
-- no touchy touchy
-- step = value 1-10, class flag, class name, item subclass (1=cloth :: 2=leather :: 3=Mail :: 4=Plate)
ClassName = {};
ClassName = {
	[1] = {1,"1230warrior",4},
	[2] = {2,"paladin",4},
	[3] = {4,"hunter",3},
	[4] = {8,"rogue",2},
	[5] = {16,"priest",1},
	[6] = {32,"deathknight",4},
	[7] = {64,"shaman",3},
	[8] = {128,"mage",1},
	[9] = {256,"warlock",1},
	[10] = {1024,"druid",2}
			};
tiercnt = 0
EntryId = Start
local File = io.open("lua_scripts/ADMIN/"..ClassName[Class][2].."_armour.sql", "w")
File:write("REPLACE INTO `item_template` (`entry`, `class`, `subclass`, `name`, `displayid`, `Quality`, `BuyCount`, `InventoryType`, `AllowableClass`, `ItemLevel`, `StatsCount`, `stat_type1`, `stat_value1`, `stat_type2`, `stat_value2`, `stat_type3`, `stat_value3`, `stat_type4`, `stat_value4`, `stat_type5`, `stat_value5`, `stat_type6`, `stat_value6`, `stat_type7`, `stat_value7`, `stat_type8`, `stat_value8`, `stat_type9`, `stat_value9`, `stat_type10`, `stat_value10`, `armor`, `socketColor_1`, `socketColor_2`, `socketColor_3`) VALUES\n\n")

--[[
	for c = 1, 10 do -- this will belch out entries for all classes USING stat data provided above DONT USE unless u understand what this does
		local Class = c
]]--		
		File:write("-- "..ClassName[Class][2].."\n")
			for t = 1, Tiers do
				File:write("-- Tier "..t.."\n")
	
					for i = 1, 8 do
						File:write("("..(EntryId+((10*t)-10)+i)+((Class*100)-(100))..", "..ItemClass..", "..ClassName[Class][3]..", '"..ClassName[Class][2].."_"..Invdata[i][2].."_T"..t.."', "..DispId[t][i]..", "..Quality..", 1, "..Invdata[i][1]..", "..ClassName[Class][1]..", "..Level..", "..Statcnt..", "..Stat1..", "..(Stat1a+((Stat1stp*t)-Stat1stp))..", "..Stat2..", "..(Stat2a+((Stat2stp*t)-Stat2stp))..", "..Stat3..", "..(Stat3a+((Stat3stp*t)-Stat3stp))..", "..Stat4..", "..(Stat4a+((Stat4stp*t)-Stat4stp))..", "..Stat5..", "..(Stat5a+((Stat5stp*t)-Stat5stp))..", "..Stat6..", "..(Stat6a+((Stat6stp*t)-Stat6stp))..", "..Stat7..", "..(Stat7a+((Stat7stp*t)-Stat7stp))..", "..Stat8..", "..(Stat8a+((Stat8stp*t)-Stat8stp))..", "..Stat9..", "..(Stat9a+((Stat9stp*t)-Stat9stp))..", "..Stat10..", "..(Stat10a+((Stat10stp*t)-Stat10stp))..", "..(Armora+((Armorstp*t)-Armorstp))..", "..Socket1..", "..Socket2..", "..Socket3.."),\n")
						print("Class: "..ClassName[Class][2].." :: tier: "..t.." :: item: "..i)
					end
				local EntryId = EntryId+2 -- cause a 2 entry air gap between tiers. syncronicity across class's for top o the head in-game .add item
			end
--	end	
File:write("-- NOW AT THE END OF THE LINE ABOVE ^ CHANGE THE LAST COMMA `,` TO A SEMI_COLON `;` .")
File:close()
print("Done")
