Write-Output "Start Compile Process"
g++ -std=c++11 ./classes/action.cpp ./classes/character.cpp ./classes/game.cpp ./classes/invokeAction.cpp ./classes/magikill.cpp ./classes/magikillMinionUpdate.cpp ./classes/miner.cpp ./classes/minerAction.cpp ./classes/minerUpdate.cpp ./classes/update.cpp main.cpp -o game.exe
Write-Output "Compiled Successfully!"
./game.exe
