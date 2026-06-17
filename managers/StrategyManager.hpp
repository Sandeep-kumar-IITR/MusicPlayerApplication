#pragma once
#include<iostream>

#include "../strategies/IPlayStrategies.hpp"
#include "../strategies/RandomPlayStrategy.hpp"
#include "../strategies/SequentialPlayStrategy.hpp"
#include "../strategies/CustomQueueStrategy.hpp"
#include "../enums/PlayStrategytype.hpp"

class StrategyManager{
    static StrategyManager* instance;
    SequentialPlay* sq;
    RandomPlay* rp;
    CustomQueuePlay* cq;

    StrategyManager(){
        sq = new SequentialPlay();
        rp = new RandomPlay();
        cq = new CustomQueuePlay();
    };

    public:
    static StrategyManager* getinstance()
    {
        if(!instance)
        {
            instance = new StrategyManager();
        }
        return instance;
    }
    IplayStrategies* getStrategy(PlayStrategytype pls)
    {
        if(pls ==PlayStrategytype::SEQUENTIAL)
        {
            return instance->sq;
        }
        if(pls==PlayStrategytype::RANDOM)
        {
            return instance->rp;
        }
        if(pls==PlayStrategytype::CUSTOM_QUEUE)
        {
            return instance->cq;
        }
        return nullptr;
    }

};

StrategyManager* StrategyManager::instance = nullptr;