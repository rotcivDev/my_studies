//
// Created by rotciv on 5/22/25.
//
#pragma once

#include <string>
#include <vector>
#include <memory>
#include "app/dispatcher.h"

namespace weblead {
namespace cli {

class CLI {
public:
    explicit CLI(std::shared_ptr<app::Dispatcher> dispatcher);

    void run(int argc, char* argv[]);
    void interactive();

private:
    std::shared_ptr<app::Dispatcher> dispatcher_;
    std::vector<std::string> parseCommandLine(const std::string& line);
};

} // namespace cli
} // namespace weblead
