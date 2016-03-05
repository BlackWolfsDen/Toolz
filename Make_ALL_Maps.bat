rem Does ALL the map, vmaps and mmaps without you having run each map tool
rem i just start it in the evening and find everything done in the morning :D

mapextractor.exe

vmap4extractor.exe

md vmaps

vmap4assembler.exe Buildings vmaps

md mmaps

mmaps_generator.exe

pause
