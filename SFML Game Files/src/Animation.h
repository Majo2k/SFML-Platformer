#pragma once

#include "all_headers.h"

class Animation
{
private:
    struct Frame {
        sf::IntRect rect;
        double duration; // in seconds
    };

    vector <Frame> frames;
    double totalLength;
    double progress;
    Sprite& target;

public:
    Animation(Sprite& target);
    ~Animation();
    void AddFrame(Frame&& frame);
    void Update(double elapsed, bool loop);
    const double getLength() const { return totalLength; }
};

