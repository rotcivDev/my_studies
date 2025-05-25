//
// Created by rotciv on 5/22/25.
//

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "common/db_connection.h"

namespace weblead {
namespace infrastructure {

struct Lead {
    int id;
    std::string name;
    std::string email;
    std::string phone;
    std::string source;
    std::string status;
    std::string created_at;
};

struct LeadInputDTO {
    int id;
    std::string name;
    std::string email;
    std::string phone;
    std::string source;
    std::string status;
};

class LeadRepository {
public:
    explicit LeadRepository(std::shared_ptr<common::DBConnection> db_connection);

    bool add(const LeadInputDTO& lead);
    std::vector<Lead> getAll();
    std::vector<Lead> search(const std::string& keyword);
    bool deleteById(int id);
    std::string exportAsJson();

private:
    std::shared_ptr<common::DBConnection> db_connection_;
};

} // namespace infrastructure
} // namespace weblead
