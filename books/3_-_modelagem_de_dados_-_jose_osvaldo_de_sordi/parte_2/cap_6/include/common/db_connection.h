//
// Created by rotciv on 5/22/25.
//
#pragma once

#include <string>
#include <pqxx/pqxx>

namespace acatamento_pedidos {
namespace common {

class DBConnection {
public:
    DBConnection(const std::string& connection_string);
    ~DBConnection();

    pqxx::connection* getConnection();
    void disconnect();  // Explicitly disconnects the database

private:
    std::string connection_string_;
    pqxx::connection* conn_;
};

} // namespace common
} // namespace acatamento_pedidos