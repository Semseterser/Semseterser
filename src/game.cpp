#include "game.hpp"

using namespace std;
using namespace chrono;

Game::Game(int64_t updatesPerSecond)
{
  this->updatesPerSec = updatesPerSecond;
}

Game::~Game()
{}

void Game::start()
{
  int64_t nsPerUpdate = 1.0 / this->updatesPerSec * 1000000;
  time_point<steady_clock>    current,
                              previous = steady_clock::now();

  duration<int64_t, nano> elapsed;

  int64_t     lag = 0.0;

  while (true) {
      current = steady_clock::now();
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
