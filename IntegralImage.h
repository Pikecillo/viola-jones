#include "Image.h"

template <class PixelSum, class Pixel>
class IntegralImage : public Image<PixelSum> {
public:
  IntegralImage(const Image<Pixel> &image);

  PixelSum rectangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1) const;
};

template <class PixelSum, class Pixel>
IntegralImage<PixelSum, Pixel>::IntegralImage(const Image<Pixel> &image)
    : Image<PixelSum>(image.width(), image.height()) {
  for (uint32_t x = 0; x < image.width(); x++) {
    PixelSum columnSum = 0;
    for (uint32_t y = 0; y < image.height(); y++) {
      this->set(x, y,
                columnSum + (x > 0 ? this->get(x - 1, y) : 0) +
                    image.get(x, y));
      columnSum += image.get(x, y);
    }
  }
}

template <class PixelSum, class Pixel>
PixelSum IntegralImage<PixelSum, Pixel>::rectangle(uint32_t x0, uint32_t y0,
                                                   uint32_t x1,
                                                   uint32_t y1) const {
  return this->get(x1, y1) + this->get(x0, y0) - this->get(x0, y1) -
         this->get(x1, y0);
}
