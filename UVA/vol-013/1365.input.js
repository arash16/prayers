function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n, m) {
    log(n, m);
    var seen = {};
    for (var i=0; i<n; i++) {
        do {
            var a = rand(1, m),
                b = rand(1, m),
                c = rand(1, m);
        }
        while (seen[a + ',' + b + ',' + c]);
        seen[a + ',' + b + ',' + c] = 1;
        log(a, b, c);
    }
    log();
}

for (var i=0; i<20; i++) {
    var m = rand(2, 50000);
    generate(rand(2, Math.min(50, m*m*m)), m);
}

log(0, 0);
