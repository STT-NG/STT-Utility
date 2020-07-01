#pragma once

#include <GeomRel>
#include <iostream>
#include <fstream>
#include <array>
#include <memory>
#include "utils.h"

struct TubeDescription {
    int id = 0;
    std::array<int, 3> position = {1, 2, 3};
    std::array<int, 3> direction = {4, 5, 6};
    int length = 7;
};

namespace STTUtil::PANDA {

using namespace GeomRel;

std::pair<bool, std::vector<std::unique_ptr<GRNode>>> csvToNodes(const std::string &csvPath, std::string *error)
{
    std::ifstream in(csvPath);

    std::vector<std::unique_ptr<GRNode>> nodes;

    if (!in) {
        *error = "Failed to open csv file for reading.";
        return {false, std::move(nodes)};
    }

    auto data = readCSV(in);

    TubeDescription desc;

    try {
        for (int i = 1; i < data.size(); ++i) {
            auto &columns = data.at(i);
            int id = std::stoi(columns.at(desc.id));
            GRVector3 position  = {std::stod(columns.at(desc.position[0])),
                                   std::stod(columns.at(desc.position[1])),
                                   std::stod(columns.at(desc.position[2]))
                                  };
            GRVector3 direction = {std::stod(columns.at(desc.direction[0])),
                                   std::stod(columns.at(desc.direction[1])),
                                   std::stod(columns.at(desc.direction[2]))
                                  };
            double length = std::stod(columns.at(desc.length));

            nodes.push_back(std::make_unique<GRCylinder>(id, position, direction, length, 0.5));
        }
    } catch (std::out_of_range &e) {
        *error = e.what();
        return {false, std::move(nodes)};
    }

    return {true, std::move(nodes)};
}

std::pair<bool, std::vector<std::unique_ptr<GRNode>>> csvToRelation(const std::string &csvPath, std::string *error, int order = 0, double tolerance = 1.0)
{
    auto [ok, nodes] = csvToNodes(csvPath, error);

    if (!ok) {
        return {false, std::move(nodes)};
    }

    GRBuilder builder;

    std::vector<GRNode *> node_ptrs;
    for (auto &node : nodes) {
        node_ptrs.push_back(node.get());
    }

    builder.setNodes(node_ptrs);
    builder.build(order, tolerance);

    return {true, std::move(nodes)};
}

}
