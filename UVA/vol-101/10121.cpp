#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Move {
    int type;
    int damage;
    int poison;
    double confusion;
    double accuracy;

    bool operator<(const Move &m) const {
        if (type != m.type)
            return type > m.type;

        if (type == 2)
            return confusion*accuracy > m.confusion*m.accuracy;

        return damage*accuracy + 3*poison > m.damage*m.accuracy + 3*m.poison;
    }
};
Move moves[4];
double run[5];
double bp[6] = { 0.2, 0.18, 0.15, 0.1, 0.05, 0 };
int k, l, g, maxHp, balls[6];


double play1(int i, int hp1, int hp2, int p1, int p2, int sr, int smi, int pr, int poison);
double play2(int i, int hp1, int hp2, int p1, int p2, int sr, int smi, int pr, int poison) {
    int hp2b = hp2;
    if (pr > 0) hp2 -= poison;
    if (run[i]==1 || hp1<=0 || hp2<=0) return 0;

    double pf = 1-run[i];
    int sr2 = sr ? sr-1 : 0,
        pr2 = pr ? pr-1 : 0;

    if (hp2b<=150 && p2>0)
        return pf*play1(i+1, hp1, hp2+200, p1, p2-1, sr2, smi, pr2, poison);

    double c = moves[smi].confusion;

    double noAttack = play1(i+1, hp1, hp2, p1, p2, sr2, smi, pr2, poison);
    if (sr>0 && !c) return pf*noAttack;

    double attackMe = play1(i+1, hp1-300, hp2, p1, p2, sr2, smi, pr2, poison);
    if (!sr) return pf * (0.3*attackMe + 0.7*noAttack);

    double attackSelf = play1(i+1, hp1, hp2-300, p1, p2, sr2, smi, pr2, poison);
    double res = c*attackSelf + (1-c)*attackMe;
    return pf * (0.3*res + 0.7*noAttack);
}



double play1(int i, int hp1, int hp2, int p1, int p2, int sr, int smi, int pr, int poison) {
    if (hp1<=0 || hp2<=0) return 0;
    double best = 0, val;


    // If he is going to run, dont bother with these
    if (run[i] < 1) {

        // Do Nothing
        double nothing = best = play2(i, hp1, hp2, p1, p2, sr, smi, pr, poison);

        // Moves & Attacks
        for (int j=0; j<k; j++) {
            Move &m = moves[j];

            if (m.type == 1)
                val = play2(i, hp1, hp2 - m.damage, p1, p2, sr, smi, pr, poison);

            else if (m.type == 2 && !sr)
                val = play2(i, hp1, hp2, p1, p2, 3, j, pr, poison);

            else if (m.type == 3)
                if (pr) val = play2(i, hp1, hp2 - m.damage, p1, p2, sr, smi, pr, poison);
                else val = play2(i, hp1, hp2 - m.damage, p1, p2, sr, smi, 3, m.poison);

            else continue;

            val = m.accuracy*val + (1-m.accuracy)*nothing;
            if (val > best) best = val;
        }


        // Use Hyper Potion
        if (p1 > 0 && hp1 < maxHp) {
            val = play2(i, min(hp1+200, maxHp), hp2, p1-1, p2, sr, smi, pr, poison);
            if (val > best) best = val;
        }
    }


    // Use Balls
    double bonus = 0;
    if (hp2 <= 50) bonus += 0.1;
    else if (hp2 <= 100) bonus += 0.05;
    if (pr > 0) bonus += 0.1;
    if (sr > 0) bonus += 0.05;

    for (int j=0; j<6; j++)
        if (balls[j]>0) {
            double cp = bp[j] + bonus;
            if (cp > 0) {
                balls[j]--;
                val = cp + (1-cp)*play2(i, hp1, hp2, p1, p2, sr, smi, pr, poison);
                balls[j]++;

                if (val > best) best = val;
            }
        }

    return best;
}



int main(){
    int p1, p2;
    while (cin>>l>>g>>maxHp && (l||g||maxHp)) {
        for (int i=0; i<5; i++) {
            cin >> run[i];
            run[i] /= 100.0;
        }

        cin >> p1 >> p2;
        for (int i=4; i>=0; i--)
            cin >> balls[i];

        if (g == 0) {
            balls[5] = balls[0];
            balls[0] = 0;
        }
        if (l <=50) {
            balls[3] += balls[1];
            balls[1] = 0;
        }

        cin >> k;
        for (int i=0; i<k; i++) {
            Move m;
            cin >> m.type;

            // Normal Attack
            if (m.type == 1)
                cin >> m.damage >> m.accuracy;

            // Status Change (confusion=0 -> Sleepy)
            else if (m.type == 2)
                cin >> m.confusion >> m.accuracy;

            // Poison Attack
            else
                cin >> m.damage >> m.poison >> m.accuracy;

            m.confusion /= 100.0;
            m.accuracy /= 100.0;
            moves[i] = m;
        }

        printf("%.4f\n", play1(0, maxHp, 999, p1, p2, 0, 0, 0, 0));
    }
}
