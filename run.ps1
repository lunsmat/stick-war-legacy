Write-Output "Start Compile Process"
g++ -std=c++11 ./classes/action.cpp ./classes/character.cpp ./classes/game.cpp main.cpp -o game.exe
Write-Output "Compiled Successfully!"
./game.exe
