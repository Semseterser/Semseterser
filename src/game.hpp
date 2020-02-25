#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>

class Game {
  private:
    int64_t updatesPerSec;

  public:
    Game(int64_t updatesPerSecond);
    ~Game();
    void start();
};

#endif /* GAME_HPP */
