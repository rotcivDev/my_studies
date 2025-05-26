#pragma once

#include <vector>
#include <string>
#include <memory>
#include "infrastructure/lead_repository.h"

namespace acatamento_pedidos {
namespace services {

class LeadService {
public:
    explicit LeadService(std::shared_ptr<infrastructure::LeadRepository> lead_repository);
    
    bool addLead(const infrastructure::LeadInputDTO& lead);
    std::vector<infrastructure::Lead> getAllLeads();
    std::vector<infrastructure::Lead> searchLeads(const std::string& keyword);
    bool deleteLead(int id);
    std::string exportLeads();
    
private:
    std::shared_ptr<infrastructure::LeadRepository> lead_repository_;
};

} // namespace services
} // namespace acatamento_pedidos