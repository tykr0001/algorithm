#include <iostream>
#include <string>

using namespace std;

int N;
int team[3];
int time[3];
int min, sec;
int flag;
int state; // 이전 상태 0:동점 1:1팀이이김 2:2팀이이김

string inp;
int prev_time;

int main(void) {
    cin >> N;
    while (N--) {
        cin >> flag;
        cin >> inp;
        int next_time = 60 * stoi(inp.substr(0, 2)) + stoi(inp.substr(3, 2));

        if (flag == 1) {
            team[1]++;
        }
        else {
            team[2]++;
        }

        if (state == 0) {
            prev_time = next_time;
            state = flag;
        }
        else if (state == 1) {
            if (team[1] == team[2]) {
                time[1] += next_time - prev_time;
                state = 0;
            }
        }
        else if (state == 2) {
            if (team[1] == team[2]) {
                time[2] += next_time - prev_time;
                state = 0;
            }
        }
    }
    if (state == 1) {
        time[1] += 60 * 48 - prev_time;
    }
    else if (state == 2) {
        time[2] += 60 * 48 - prev_time;
    }

    printf("%02d:%02d\n", time[1] / 60, time[1] % 60);
    printf("%02d:%02d\n", time[2] / 60, time[2] % 60);

    return 0;
}