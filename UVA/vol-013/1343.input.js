function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(major) {
    var r = [];
    for (var i=0; i<24; ++i)
        if (rand(1,2)==1)
            r.push(major);
        else r.push(rand(1, 3));
    console.log.apply(console, r);
}

for (var i=0; i<500; i++)
    generate(rand(1,3));
console.log(0);
