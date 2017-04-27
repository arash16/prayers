function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
    log (n);
    for (var i=0; i<n; i++)
        log(rand(1, 100), rand(1, 100));
}

generate(10000);
//for (var i=0; i<100; i++)
//    generate(4);

generate(0);
