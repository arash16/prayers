function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);


function generate(n) {
    var w=rand(73, 121),
        u=rand(3, 13),
        v=rand(3, 13),
        t1=rand(0, 100),
        t2=rand(t1, t1+500);
    console.log(n, w, u, v, t1, t2);

    for (var i=0; i<n; ++i) {
        var W = rand(0, 1),
            m = rand(0, 5);

        var str = (W ? 'W ' : 'E ') + m;

        var p = 0;
        for (var j=0; j<m; ++j) {
            var l = rand(1, 100);
            p += rand(0, 100);
            str += ' ' + l + ' ' + p;
            p += l;
        }
        console.log(str);
    }
    console.log('');
}

for (var i=0; i<100; i++)
    generate(rand(0, 5));
