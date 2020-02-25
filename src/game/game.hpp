#ifndef GAME_HPP
#define GAME_HPP

#include <chrono>

namespace semseterser {
  class Game {
    private:
      int64_t updatesPerSec;

    public:
      Game();
      Game(int64_t updatesPerSecond);
      void start();
  };
}

#endif /* GAME_HPP */
