function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n, m) {
    log(n, m);

    var H = [];
    for (var i=0; i<n; ++i)
        H.push(rand(0, 100), rand(0, 100));

    var A = [];
    for (var i=0; i<m; ++i)
        A.push(rand(0, 100), rand(0, 50));

    console.log.apply(console, H);
    console.log.apply(console, A);

    for (var i=0; i<n; ++i) {
        var L = [];
        for (var j=0; j<m; ++j)
            L.push(rand(1, 50));
        console.log.apply(console, L);
    }
}

for (var i=0; i<200; ++i) {
    var sz = rand(2, 7);
    generate(sz, sz);
}

for (var i=0; i<10; ++i) {
    var sz = rand(100, 249);
    generate(sz, sz);
}

console.log(0,0)
