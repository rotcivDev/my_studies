#include <memory>
#include <iostream>
#include "cli/cli.h"
#include "app/dispatcher.h"
#include "services/lead_service.h"
#include "infrastructure/lead_repository.h"
#include "common/db_connection.h"

int main(int argc, char* argv[]) {
    try {
        // Create dependencies
        auto db_connection = std::make_shared<weblead::common::DBConnection>(
            "postgresql://user:pass@db:5432/webleads");

        auto lead_repository = std::make_shared<weblead::infrastructure::LeadRepository>(db_connection);
        auto lead_service = std::make_shared<weblead::services::LeadService>(lead_repository);
        auto dispatcher = std::make_shared<weblead::app::Dispatcher>(lead_service);
        auto cli = std::make_shared<weblead::cli::CLI>(dispatcher);

        // Run the CLI
        if (argc > 1) {
            cli->run(argc, argv);
        } else {
            cli->interactive();
        }

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}