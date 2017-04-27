function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
    // level            gender        hp
    log (rand(1,100), rand(0, 1), rand(200, 999));

    var runs = [rand(0, 10)];
    for (var i=0; i<3; i++)
        runs.push(runs[runs.length-1] + rand(0, 20));
    log (runs.join(' '), 100);

    // potions
    log (rand(1,5), rand(1, 5));

    //balls
    var balls = [];
    for (var i=0; i<5; i++)
        balls.push(rand(1, 3));
    log (balls.join(' '));


    log (n);
    for (var i=0; i<n; i++) {
        var tp = rand(1, 3),
            ac = rand(1, 100);

        if (tp == 1) log (tp, rand(10, 999), ac);

        if (tp == 2)
            if (rand(1,2) == 1)
                 log (tp, rand(1, 100), ac);
            else log (tp, 0, ac);

        if (tp == 3)
            log (tp, rand(10, 999), rand(10, 300), ac);
    }

    log();
}

for (var i=0; i<100; i++)
    generate(4);

log (0, 0, 0);
