#pragma once
#include <vector>
#include <memory>
#include "exercise_06_section.h"
#include "exercise_06_zoo_keeper.h"

class Zoo {
private:
    // Zoo притежава секциите (полиморфни, затова raw Section* + delete в деструктора)
    // и пазачите (shared_ptr). Секциите наблюдават пазач през суров указател, без
    // да го притежават, затова Rule of Zero не важи за секциите.
    std::vector<Section*> sections;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;

public:
    Zoo() = default;
    Zoo(const Zoo& other) = delete;
    Zoo& operator = (const Zoo& other) = delete;
    ~Zoo();

    void addSection(Section* section);
    std::shared_ptr<ZooKeeper> addKeeper(const char* name,
        const size_t employeeID, const size_t experience);
    void removeKeeper(const size_t employeeID);

    void printAll() const;
    const Animal* search(const char* name) const;
};
