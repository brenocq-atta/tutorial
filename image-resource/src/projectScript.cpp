//--------------------------------------------------
// Image Resource
// projectScript.cpp
// Date: 2022-08-19
// By Breno Cunha Queiroz
//--------------------------------------------------
#include "projectScript.h"
#include <atta/component/interface.h>
#include <atta/resource/interface.h>
#include <atta/resource/resources/image.h>
#include <chrono>

namespace rsc = atta::resource;
namespace cmp = atta::component;
const cmp::Entity plane(0);

void Project::onLoad() {
    rsc::Image::CreateInfo info;
    info.width = 100;
    info.height = 100;
    info.format = rsc::Image::Format::RGBA8;
    rsc::Image* img = rsc::create<rsc::Image>("animation", info);
    rsc::Image* gameOfLife = rsc::create<rsc::Image>("gameOfLife", info);

    // Init gameOfLife as white
    uint8_t* data = gameOfLife->getData();
    for (int i = 0; i < info.width * info.height * 4; i++)
        data[i] = 255;

    std::vector<atta::vec2i> blinkers = {{10, 10}, {20, 20}, {10, 20}, {20, 10}};
    std::vector<atta::vec2i> gliders = {{30, 30}, {20, 50}, {10, 5}, {5, 5}, {80, 30}, {40, 90}, {90, 10}, {90, 50}};
    std::vector<atta::vec2i> liveCells = {};

    for (atta::vec2i blinker : blinkers) {
        liveCells.push_back(blinker + atta::vec2i(0, 0));
        liveCells.push_back(blinker + atta::vec2i(1, 0));
        liveCells.push_back(blinker + atta::vec2i(0, 1));
    }

    for (atta::vec2i glider : gliders) {
        liveCells.push_back(glider + atta::vec2i(0, -1));
        liveCells.push_back(glider + atta::vec2i(1, 0));
        liveCells.push_back(glider + atta::vec2i(-1, 1));
        liveCells.push_back(glider + atta::vec2i(0, 1));
        liveCells.push_back(glider + atta::vec2i(1, 1));
    }

    for (atta::vec2i cell : liveCells) {
        unsigned idx = (cell.y * info.width + cell.x) * 4;
        data[idx] = data[idx + 1] = data[idx + 2] = 0;
    }

    gameOfLife->update();
}

void Project::onAttaLoop() {
    updateAnimation();
    updateGameOfLife();
}

void Project::updateAnimation() {
    static auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 50;

    // Change random pattern with time
    rsc::Image* img = rsc::get<rsc::Image>("animation");
    uint32_t w = img->getWidth();
    uint32_t h = img->getHeight();
    uint8_t* data = img->getData();
    for (int i = 0; i < w * h * 4; i++)
        data[i] = 255;

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            int X = x + time;
            int Y = y + time * 2;
            X %= w;
            Y %= h;
            uint32_t idx = (w * Y + X) * 4;
            data[idx + 0] = 255 * sin(x / float(w) * M_PI * 5);
            data[idx + 1] = 255 * sin(y / float(h) * M_PI * 5);
            data[idx + 2] = 255;
        }
    img->update();
}

void Project::updateGameOfLife() {
    static auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    int time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()/100;

    // Update every second
    if (time > 0) {
        start = end;

        rsc::Image* gameOfLife = rsc::get<rsc::Image>("gameOfLife");
        uint32_t w = gameOfLife->getWidth();
        uint32_t h = gameOfLife->getHeight();
        uint8_t* data = gameOfLife->getData();

        uint8_t* backup = new uint8_t[w * h * 4];
        for (int i = 0; i < w * h * 4; i++)
            backup[i] = data[i];

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int idx = (y * w + x) * 4;
                int numNeighbors = 0;
                bool isAlive = backup[idx] == 0;
                // Count neightbors
                for (int yn = y - 1; yn <= y + 1; yn++)
                    for (int xn = x - 1; xn <= x + 1; xn++) {
                        // Ignore center
                        if (yn == y && xn == x)
                            continue;
                        // Wrap coord
                        int X = (xn + w) % w;
                        int Y = (yn + h) % h;
                        if (backup[(Y * w + X) * 4] == 0)
                            numNeighbors++;
                    }

                // Update cell
                if (isAlive && (numNeighbors == 2 || numNeighbors == 3))
                    continue;
                else if (!isAlive && numNeighbors == 3)
                    data[idx] = data[idx + 1] = data[idx + 2] = 0;
                else
                    data[idx] = data[idx + 1] = data[idx + 2] = 255;
            }
        }
        delete[] backup;
        gameOfLife->update();
    }
}
