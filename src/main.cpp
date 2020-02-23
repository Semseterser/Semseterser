#include <chrono>

using namespace std;
using namespace chrono;

int64_t NS_PER_UPDATE = 1.0 / 90.0 * 1000000;

int main()
{
    time_point  current = steady_clock::now(),
                previous = steady_clock::now();

    duration    elapsed = current - previous;

    int64_t     lag = 0.0;

    while (true) {
        current = steady_clock::now();
        elapsed = current - previous;
        previous = current;
        lag += elapsed.count();

        // process input(s)

        // keep the update interval constant
        while (lag >= NS_PER_UPDATE) {
            // update physics & stuff
            lag -= NS_PER_UPDATE;
        }

        // render dynamically
    }

    return 0;
}
