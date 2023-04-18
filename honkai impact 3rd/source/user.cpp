//
// Created by 13360 on 2023/4/9.
//
#include "../header/user.h"
#include <stdexcept>
#include <iostream>

std::any User::getProperty(int key) {
    try {
        auto re = properties.at(key);
        return re;
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: Property not found, key = " << key << "\n";
        throw e;
    }
}

void User::setProperty(int key, const std::any &value) {
    properties[key] = value;
}

std::any User::getCoin(int key) {
    try {
        auto re = coins.at(key);
        return re;
    } catch (const std::out_of_range &e) {
        std::cerr << "Error: Coin not found, key = " << key << "\n";
        throw e;
    }
}

void User::setCoin(int key, const std::any &value) {
    coins[key] = value;
}