#include "out.h"
#include "color.h"

int main() {

    const int width = 256;
    const int height = 256;

    Buffer buffer(height, width);
    for (int j = 0; j < height; ++j) {
        std::clog << "\rScanlines remaining: " << (height - j - 1)  << ' ' << std::flush;
        for (int i = 0; i < width; ++i) {
            auto pixel_color = Color((double)i / (width - 1), (double)j / (height - 1), 0);
            buffer << pixel_color;
        }
    }

    buffer.flush();
    std::clog << "\rDone.                 \n";
}