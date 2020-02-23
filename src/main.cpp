#include <chrono>

using namespace std;
using namespace chrono;

int64_t NS_PER_UPDATE = 1.0 / 90.0 * 1000000;

int main()
{
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
        while (lag >= NS_PER_UPDATE) {
            // update physics & stuff
            lag -= NS_PER_UPDATE;
        }

        // render dynamically
    }

    return 0;
}
