#include <cassert>
#include <iostream>

#include "IntegralImage.h"

void testIntegralImage() {
  uint32_t side = 5;
  Image<float> image(side, side);

  for (uint32_t x = 0; x < image.width(); x++)
    for (uint32_t y = 0; y < image.height(); y++)
      image.set(x, y, x + y);

  const IntegralImage<float, float> integralImage(image);

  for (uint32_t x = 0; x < integralImage.width(); x++) {
    for (uint32_t y = 0; y < integralImage.height(); y++)
      std::cout << integralImage.get(x, y) << " ";
    std::cout << std::endl;
  }

  for (uint32_t x = 0; x < image.width(); x++) {
    for (uint32_t y = 0; y < image.height(); y++)
      std::cout << image.get(x, y) << " ";
    std::cout << std::endl;
  }

  for (uint32_t x = 0; x + 1 < image.width(); x++) {
    for (uint32_t y = 0; y + 1 < image.height(); y++)
      std::cout << integralImage.rectangle(x, y, x + 1, y + 1) << " ";
    std::cout << std::endl;
  }

  for (uint32_t x = 0; x + 1 < image.width(); x++) {
    for (uint32_t y = 0; y + 1 < image.height(); y++)
      assert(image.get(x + 1, y + 1) ==
             integralImage.rectangle(x, y, x + 1, y + 1));
  }
}

int main() { testIntegralImage(); }
