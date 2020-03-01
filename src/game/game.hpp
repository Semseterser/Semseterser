#ifndef SEMSETERSER_GAME_HPP
#define SEMSETERSER_GAME_HPP

#include <chrono>

namespace semseterser {
  class Game {
    private:
      int64_t updatesPerSec;

    public:
      Game();
      explicit Game(int64_t updatesPerSecond);
      void start();
  };
}  // namespace semseterser

#endif /* SEMSETERSER_GAME_HPP */
