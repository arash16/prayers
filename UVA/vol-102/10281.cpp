#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char line[100];
    double otime=0, offset=0;
    int speed=0;
    while (cin.getline(line, 100)) if (line[0]) {
        int h, m, s, sp;
        int tp = sscanf(line, "%d:%d:%d %d", &h, &m, &s, &sp);
        double tm = h + m/60.0 + s/3600.0;

        if (tp == 4) {
            offset += (tm - otime) * speed;
            speed = sp;
            otime = tm;
        }

        else printf("%02d:%02d:%02d %.2f km\n", h,m,s,  offset+(tm - otime)*speed);
    }
}
