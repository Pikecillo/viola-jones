#include <cstdint>
#include <vector>

template <class Pixel> class Image {
public:
  Image(uint32_t width, uint32_t height);

  const Pixel &get(uint32_t x, uint32_t y) const;

  void set(uint32_t x, uint32_t y, const Pixel &pixel);

  uint32_t width() const;

  uint32_t height() const;

protected:
  uint32_t m_width;
  uint32_t m_height;
  std::vector<Pixel> m_data;
};

template <typename Pixel>
Image<Pixel>::Image(uint32_t width, uint32_t height)
    : m_width(width), m_height(height), m_data(width * height, Pixel()) {}

template <typename Pixel> uint32_t Image<Pixel>::width() const {
  return m_width;
}

template <typename Pixel> uint32_t Image<Pixel>::height() const {
  return m_height;
}

template <typename Pixel>
const Pixel &Image<Pixel>::get(uint32_t x, uint32_t y) const {
  return m_data[x + y * m_width];
}

template <typename Pixel>
void Image<Pixel>::set(uint32_t x, uint32_t y, const Pixel &pixel) {
  m_data[x + y * m_width] = pixel;
}
