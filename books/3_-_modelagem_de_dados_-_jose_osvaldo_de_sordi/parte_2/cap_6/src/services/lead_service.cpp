#include "services/lead_service.h"
#include <sstream>

namespace acatamento_pedidos {
    namespace services {

        LeadService::LeadService(std::shared_ptr<infrastructure::LeadRepository> lead_repository)
            : lead_repository_(std::move(lead_repository)) {}

        bool LeadService::addLead(const infrastructure::LeadInputDTO& lead) {
            return lead_repository_->add(lead);
        }

        std::vector<infrastructure::Lead> LeadService::getAllLeads() {
            return lead_repository_->getAll();
        }

        std::vector<infrastructure::Lead> LeadService::searchLeads(const std::string& keyword) {
            return lead_repository_->search(keyword);
        }

        bool LeadService::deleteLead(int id) {
            return lead_repository_->deleteById(id);
        }

        std::string LeadService::exportLeads() {
            auto leads = getAllLeads();
            std::ostringstream oss;
            oss << "ID,Name,Email,Phone\n";  // Adjust columns as per Lead definition

            for (const auto& lead : leads) {
                // Assuming Lead has id, name, email, and phone fields
                oss << lead.id << ","
                    << lead.name << ","
                    << lead.email << ","
                    << lead.phone << "\n";
            }

            return oss.str();
        }

    } // namespace services
} // namespace acatamento_pedidos