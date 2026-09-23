#include "exercise_08.hpp"

int main() {
    Pipeline<float> pipeline;

    pipeline = pipeline.pipe([](const float& number){
        return number * number;
    });
    pipeline = pipeline.pipe([](const float& number){
        return number + 3.14f;
    });
    pipeline = pipeline.pipe([](const float& number){
        return number / 2.0f;
    });

    std::cout << pipeline.executeOne() << std::endl;
    std::cout << pipeline.execute() << std::endl;
    return 0;
}