#ifndef DEFS_HPP
#define DEFS_HPP

#include <functional>
#include <random>

const int FIELD_WIDTH = 800;
const int FIELD_HEIGHT = 800;
const int ENTITIES_NUMBER = 50;
const int GOODS_NUMBER = 500;
const int HUNTING_NUMBER = 150;
const int RELEASE_NUMBER = 250;
const int EATING_NUMBER = 10;
const int DIE_NUMBER = 5;

static std::default_random_engine generator(time(nullptr));
static std::uniform_int_distribution<int> distribution1(-2, 2);
static std::uniform_int_distribution<int> distribution2(0, FIELD_HEIGHT);
static std::uniform_int_distribution<int> distribution3(50, 200);
static std::uniform_int_distribution<int> distribution5(0, 2);
static std::binomial_distribution<int> distribution4(1000, 0.25);
static auto dice_roll1 = std::bind(distribution1, generator);
static auto dice_roll2 = std::bind(distribution2, generator);
static auto dice_roll3 = std::bind(distribution4, generator);
static auto dice_roll4 = std::bind(distribution5, generator);

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

#endif // DEFS_HPP
