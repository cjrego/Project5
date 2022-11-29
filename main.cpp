#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Streamer.h"
using namespace std;
#include <iomanip>
#include <iostream>
#include <string>

string ObjToName(Streamer s) {
    return s.getName();
}

int main() {
    vector<Streamer> streamers;
    string file = "../twitchdata-update.csv";
    getDataFromFile(file, streamers);

    const unsigned long TABLE_SIZE = 1000;
/*
    SeparateChaining<int> sepChain(TABLE_SIZE, intToString);
    for(int i =0; i<streamers.size()-1; i++){
        sepChain.insert()
    } */

    SeparateChaining<Streamer> sepChainOne(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainTwo(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainThree(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainFour(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainFive(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainSix(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainSeven(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainEight(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainNine(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainTen(TABLE_SIZE, ObjToName);


    for(int i=0; i<streamers.size()-1;i++){
        sepChainOne.insert(streamers.at(i));
    }
    sepChainOne.printTable();

    DoubleHash<Streamer> dubChainOne(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainTwo(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainThree(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainFour(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainFive(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainSix(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainSeven(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainEight(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainNine(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainTen(TABLE_SIZE, ObjToName);


    for(int i=0; i < streamers.size()-1; i++){
        dubChainOne.insert(streamers.at(i));
    }
    dubChainOne.printTable();

    sepChainOne.find(streamers.at(22).getName());


    return 0;
}
