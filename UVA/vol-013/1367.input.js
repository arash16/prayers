function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n, m) {
    var ks = rand(2, 20),
        kl = rand(2, 30);

    log(n, m, ks, kl);
    for (var i=0; i<ks+kl; ++i)
        log(rand(0, n), rand(0, m));

    log('');
}

for (var i=0; i<100; i++)
    generate(rand(10, 1000), rand(10, 1000));

log(0, 0, 0, 0);
