function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

var sq2 = 1.414213562373;

function generate() {
    var x = rand(100, 2000),
        y = rand(100, 2000);

    var str = x+','+y;
    if (y < x) {
        var t = y;
        y = x;
        x = t;
    }


    var w1 = rand(x, 2000) + 50,
        w2 = parseInt((2*x + y)/sq2 - w1);

    for (var i=-1; i<5; ++i)
        str += ' ' + w1 + ',' + (w2 + i*80);

    log(str);
}

for (var i=0; i<100; i++)
    generate();
