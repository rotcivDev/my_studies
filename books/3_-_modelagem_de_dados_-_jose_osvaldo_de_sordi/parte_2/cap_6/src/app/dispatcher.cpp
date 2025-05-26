#include "app/dispatcher.h"
#include "infrastructure/lead_repository.h"
#include <iostream>

namespace acatamento_pedidos {
namespace app {

Dispatcher::Dispatcher(std::shared_ptr<services::LeadService> lead_service)
    : lead_service_(std::move(lead_service)) {}

void Dispatcher::dispatch(const std::string& command, const std::vector<std::string>& args) {
    if (command == "add") {
        handleAdd(args);
    } else if (command == "list") {
        handleList();
    } else if (command == "search") {
        handleSearch(args);
    } else if (command == "delete") {
        handleDelete(args);
    } else {
        showHelp();
    }
}

void Dispatcher::handleAdd(const std::vector<std::string>& args) {
    if (args.size() < 5) {
        std::cerr << "Usage: add <id> <name> <email> <phone> <source> <status> \n";
        return;
    }

    infrastructure::LeadInputDTO lead;
    try {
        lead.id = std::stoi(args[0]);
    } catch (...) {
        std::cerr << "Invalid ID format.\n";
        return;
    }

    lead.name       = args[1];
    lead.email      = args[2];
    lead.phone      = args[3];
    lead.source     = args[4];
    lead.status     = args[5];

    lead_service_->addLead(lead);

    std::cout << "Lead added: " << lead.name << " (" << lead.email << ")\n";
}

void Dispatcher::handleList() {
    auto leads = lead_service_->getAllLeads();
    if (leads.empty()) {
        std::cout << "No leads found.\n";
        return;
    }
    for (const auto& lead : leads) {
        std::cout << "ID: " << lead.id
                  << ", Name: " << lead.name
                  << ", Email: " << lead.email
                  << ", Phone: " << lead.phone
                  << ", Source: " << lead.source
                  << ", Status: " << lead.status
                  << ", Created At: " << lead.created_at << "\n";
    }
}

void Dispatcher::handleSearch(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "Usage: search <query>\n";
        return;
    }
    std::string query = args[0];
    auto results = lead_service_->searchLeads(query);
    if (results.empty()) {
        std::cout << "No results for query: " << query << "\n";
    } else {
        for (const auto& lead : results) {
            std::cout << "ID: " << lead.id
                      << ", Name: " << lead.name
                      << ", Email: " << lead.email
                      << ", Phone: " << lead.phone
                      << ", Source: " << lead.source
                      << ", Status: " << lead.status
                      << ", Created At: " << lead.created_at << "\n";
        }
    }
}

    void Dispatcher::handleDelete(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "Usage: delete <id>\n";
        return;
    }

    int id;
    try {
        id = std::stoi(args[0]);
    } catch (...) {
        std::cerr << "Invalid ID format.\n";
        return;
    }

    if (lead_service_->deleteLead(id)) {
        std::cout << "Lead with ID " << id << " deleted.\n";
    } else {
        std::cerr << "Lead not found with ID: " << id << "\n";
    }
}

void Dispatcher::showHelp() {
    std::cout << "Available commands:\n"
              << "  add <name> <email>\n"
              << "  list\n"
              << "  search <query>\n"
              << "  delete <email>\n";
}

} // namespace app
} // namespace acatamento_pedidos
