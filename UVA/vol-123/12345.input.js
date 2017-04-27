function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

log (50000, 5000);
for (var i=0; i<50000; i++)
    log(rand(1, 1000000));

for (var i=0; i<5000; i++) {
    var a = rand(0, 50000);
    log('Q', a, rand(a+1, 50000));
}
