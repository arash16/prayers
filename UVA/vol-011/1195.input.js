function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate() {
    var a = rand(1, 10),
        b = rand(a, 10);
    log (rand(5, 100000), a, b);
}

for (var i=0; i<10000; i++)
    generate();

log(0,0,0);
