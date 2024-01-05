#include "out.h"

int main() {

    const int width = 256;
    const int height = 256;

    Buffer buffer(height, width);
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0.0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            buffer << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    buffer.flush();
}