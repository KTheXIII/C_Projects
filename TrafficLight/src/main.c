#ifdef _WIN32
#include <Windows.h>
#define sleep(x) Sleep(x * 1000)
#else
#include <unistd.h>
#endif

#include <stdio.h>
#include <stdint.h>

typedef enum TRAFFIC_STATE { RED, YELLOW, RED_YELLOW, GREEN } TRAFFIC_STATE;

const int32_t tick_interval = 1;  // in seconds
static int32_t ticks;

void tick() {
    sleep(tick_interval);
    ticks++;
}

void reset_tick() { ticks = 0; }

int32_t get_tick() { return ticks; }

void print_state(TRAFFIC_STATE state) {
    static char traffic_light[][12] = {"RED", "YELLOW", "RED_YELLOW\0",
                                       "GREEN"};

    printf("LIGHT: %s - %d\n", traffic_light[state], get_tick());
}

int main(int argc, char const *argv[]) {
    TRAFFIC_STATE current_state = RED;
    TRAFFIC_STATE next_state = current_state;

    while (1) {
        tick();
        print_state(current_state);

        switch (current_state) {
            case RED:
                if (get_tick() >= 15) {
                    reset_tick();
                    next_state = RED_YELLOW;
                }
                break;
            case RED_YELLOW:
                if (get_tick() >= 3) {
                    reset_tick();
                    next_state = GREEN;
                }
                break;
            case YELLOW:
                if (get_tick() >= 6) {
                    reset_tick();
                    next_state = RED;
                }
                break;
            case GREEN:
                if (get_tick() >= 10) {
                    reset_tick();
                    next_state = YELLOW;
                }
                break;
        }

        current_state = next_state;
    }

    return 0;
}
