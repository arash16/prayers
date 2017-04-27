function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(m, n) {
    log(m, n);
    for (var i=0; i<m; i++) {
        var line='';
        for (var j=0; j<n; j++)
            line += rand(0,10)<9 ? '?' : '.';
        log(line);
    }
}

for (var i=0; i<100; i++)
    generate(rand(5, 100), rand(5, 80));

log(0, 0);
