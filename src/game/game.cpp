#include "game.hpp"

namespace chrono = std::chrono;

semseterser::Game::Game() : updatesPerSec{90} {}

semseterser::Game::Game(int64_t updatesPerSecond)
  : updatesPerSec{updatesPerSecond}
{}

void semseterser::Game::start()
{
  int64_t nsPerUpdate = 1.0 / this->updatesPerSec * 1000000;
  chrono::time_point<chrono::steady_clock>    current,
                              previous = chrono::steady_clock::now();

  chrono::duration<int64_t, std::nano> elapsed;

  int64_t     lag = 0.0;

  while (true) {
      current = chrono::steady_clock::now();
      elapsed = current - previous;
      previous = current;
      lag += elapsed.count();

      // process input(s)

      // keep the update interval constant
      while (lag >= nsPerUpdate) {
          // update physics & stuff
          lag -= nsPerUpdate;
      }

      // render dynamically
  }
}
