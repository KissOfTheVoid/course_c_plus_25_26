/*
    Works with vector library
    Image processing system in which filters are implemented as nested classes and operations are composed of a chain of methods.
*/

#include <iostream>
#include <vector>

class Image {
public:
    class Filter {
        int intensity;
    public:
        Filter(int i) : intensity(i) {}

        int apply(int pixel) const {
            return pixel + this->intensity;
        }
    };

private:
    int width;
    int height;
    std::vector<int> pixels;

public:
    Image(int w, int h, int init)
        : width(w), height(h), pixels(w * h, init) {}


    Image(int w, int h)
        : Image(w, h, 0) {}

    Image& applyBrightness(int delta) {
        for (int& p : pixels) {
            p += delta;
        }
        return *this;
    }

    Image& applyFilter(const Filter& f) {
        for (int& p : pixels) {
            p = f.apply(p);
        }
        return *this;
    }

    void show() const {
        std::cout << "Image " << width << "x" << height << ":\n";
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << pixels[y * width + x] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {
    Image img(10, 30, 20);

    img.applyBrightness(10).applyFilter(Image::Filter(3)).applyBrightness(-1);

    img.show();
    /*
    Image 10x30:
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32 
    32 32 32 32 32 32 32 32 32 32
    */
    return 0;
}
