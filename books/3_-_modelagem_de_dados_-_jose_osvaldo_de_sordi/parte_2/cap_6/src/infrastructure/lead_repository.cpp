#include "infrastructure/lead_repository.h"
#include <iostream>

namespace weblead {
namespace infrastructure {

LeadRepository::LeadRepository(std::shared_ptr<common::DBConnection> db_connection)
    : db_connection_(db_connection) {
}

bool LeadRepository::add(const LeadInputDTO& lead) {
    try {
        auto conn = db_connection_->getConnection();
        pqxx::work txn(*conn);

        txn.exec_params(
            "INSERT INTO leads (name, email, phone, source, status) VALUES ($1, $2, $3, $4, $5)",
            lead.name, lead.email, lead.phone, lead.source, lead.status);

        txn.commit();
        std::cout << "Lead added successfully.\n";
        return true;
    } catch (const std::exception& e) {
        std::cerr << "Error adding lead: " << e.what() << std::endl;
        return false;
    }
}

std::vector<Lead> LeadRepository::getAll() {
    std::vector<Lead> leads;
    try {
        auto conn = db_connection_->getConnection();
        pqxx::work txn(*conn);
        pqxx::result r = txn.exec(
            "SELECT id, name, email, phone, source, status, created_at FROM leads");

        for (auto row : r) {
            Lead lead;
            lead.id = row["id"].as<int>();
            lead.name = row["name"].c_str();
            lead.email = row["email"].c_str();
            lead.phone = row["phone"].c_str();
            lead.source = row["source"].c_str();
            lead.status = row["status"].c_str();
            lead.created_at = row["created_at"].c_str();
            leads.push_back(lead);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error fetching leads: " << e.what() << std::endl;
    }
    return leads;
}

std::vector<Lead> LeadRepository::search(const std::string& keyword) {
    std::vector<Lead> leads;
    try {
        auto conn = db_connection_->getConnection();
        pqxx::work txn(*conn);

        // Search across multiple columns
        std::string query =
            "SELECT id, name, email, phone, source, status, created_at FROM leads "
            "WHERE name ILIKE $1 OR email ILIKE $1 OR phone ILIKE $1 OR source ILIKE $1";

        std::string pattern = "%" + keyword + "%";
        pqxx::result r = txn.exec_params(query, pattern);

        for (auto row : r) {
            Lead lead;
            lead.id = row["id"].as<int>();
            lead.name = row["name"].c_str();
            lead.email = row["email"].c_str();
            lead.phone = row["phone"].c_str();
            lead.source = row["source"].c_str();
            lead.status = row["status"].c_str();
            lead.created_at = row["created_at"].c_str();
            leads.push_back(lead);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error searching leads: " << e.what() << std::endl;
    }
    return leads;
}

bool LeadRepository::deleteById(int id) {
    try {
        auto conn = db_connection_->getConnection();
        pqxx::work txn(*conn);

        pqxx::result r = txn.exec_params("DELETE FROM leads WHERE id = $1 RETURNING id", id);
        txn.commit();

        // If we got a result back, the deletion was successful
        return !r.empty();
    } catch (const std::exception& e) {
        std::cerr << "Error deleting lead: " << e.what() << std::endl;
        return false;
    }
}

} // namespace infrastructure
} // namespace weblead
