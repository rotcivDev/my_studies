#pragma once

#include <string>
#include <vector>
#include <memory>
#include "services/lead_service.h"

namespace acatamento_pedidos {
namespace app {

class Dispatcher {
public:
    explicit Dispatcher(std::shared_ptr<services::LeadService> lead_service);
    
    void dispatch(const std::string& command, const std::vector<std::string>& args);
    
private:
    std::shared_ptr<services::LeadService> lead_service_;
    
    void handleAdd(const std::vector<std::string>& args);
    void handleList();
    void handleSearch(const std::vector<std::string>& args);
    void handleDelete(const std::vector<std::string>& args);
    void handleExport();
    void showHelp();
};

} // namespace app
} // namespace acatamento_pedidos