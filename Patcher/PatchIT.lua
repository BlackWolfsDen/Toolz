-- Laurea version stable and extrememly fast ... EXTREMELY FAST !! not quite sure how . i tried to make my own version like this 
-- and it would crash at last second but would create all but last entry lol oh well its all for the learning :D
-- this will rebuild a whole new item.dbc file with ALL entries. (may not be sequential). output found in world folder.
-- just replace into your patch file and your dbc folder, empty cache and restart world.exe's. no more `?`'s.
local RequiredRank = 5 --3 is default admin rank on TC

--template function
--encodes 'val' to a string of length 'size'
--if rev is true, uses big-endian format. otherwise uses little-endian
--returns string if successful, nil otherwise
local function format(val, size, rev)
	val = tonumber(val);
	size = tonumber(size) or 4;
	if (not val or size < 1 or size > 4) then return; end
		
	local f = {};
	for i = 0, size-1 do
		table.insert(f, rev and 1 or #f+1, string.char(bit32.extract(val, i*8, 8)));
	end
	return table.concat(f);
end

local function main(event, player, msg)
	if (player:GetGMRank() == RequiredRank and msg:lower() == Command:lower()) then
		local query = WorldDBQuery("SELECT `entry`, `class`, `subclass`, `SoundOverrideSubclass`, `displayid`, `InventoryType`, `Material`, `sheath` FROM item_template")
		if (query and query:GetRowCount() > 0) then
			local startTime = os.clock();
			local file = assert(io.open("item.dbc", "w+b"), "Couldn't create new item.dbc in server directory!");
			file:setvbuf("no");
			
			local rowCount = query:GetRowCount();
			--No, the last two concatinations aren't needed. it's just easier to see the individual bytes that way
			file:write("WDBC" .. format(rowCount) .. "\8\0\0\0" .. "\32\0\0\0" .."\1\0\0\0");
			
			for i = 1, rowCount do
				local entry = query:GetUInt32(0);
				local class = query:GetUInt8(1);
				local subclass = query:GetUInt8(2);
				local sound = query:GetInt8(3);
				local material = query:GetInt8(6);
				local display = query:GetUInt32(4);
				local invtype = query:GetUInt8(5);
				local sheath = query:GetUInt8(7);
				
				local row = {format(entry), format(class), format(subclass), format(sound), format(material), format(display), format(invtype), format(sheath)};
				file:write(table.concat(row));
				
				query:NextRow();
			end
			
			file:write("\0");
			file:flush();
			file:close();
			
			player:SendBroadcastMessage(string.format("Recreated item.dbc with %u rows. Time taken: %0.02f seconds.", rowCount, os.clock() - startTime));
		end
	end
end

if (RegisterPlayerEvent) then
	RegisterPlayerEvent(18, main);
else
	RegisterServerHook(18, main);
end
