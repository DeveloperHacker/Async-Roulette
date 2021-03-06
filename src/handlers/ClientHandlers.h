#pragma once

#include "Handlers.h"
#include "json/src/json.hpp"

using json = nlohmann::json;

class Client;

class ClientHandlers : public Handlers<void, Client &, json &> {
public:
    ClientHandlers();
};
