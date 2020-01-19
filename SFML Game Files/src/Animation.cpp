#include "Animation.h"

Animation::Animation(sf::Sprite& target) :target(target)
{
    progress = totalLength = 0.0;
}

Animation::~Animation()
{
    /* STUFF */
}

void Animation::AddFrame(Frame&& frame)
{
    totalLength += frame.duration;
    frames.push_back(std::move(frame));
}

void Animation::Update(double elapsed, bool loop)
{
    progress += elapsed;
    double p = progress;

    for (size_t i = 0; i < frames.size(); i++) 
    {
        p -= frames[i].duration;

        // if we have progressed OR if we're on the last frame, apply and stop.
        if (loop && p > 0.0 && &(frames[i]) == &(frames.back())) 
        {
            i = -1;    // start over from the beginning
            continue; // break off the loop and start where 'i' is
        }
        else if (p <= 0.0 || &(frames[i]) == &frames.back())
        {
            target.setTextureRect(frames[i].rect);
            break; // found frame
        }
    }
}