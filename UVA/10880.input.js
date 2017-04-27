function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
	var s = '';
	for (var i=0; i<n; i++)
		s += String.fromCharCode(65+rand(0, 25));
	log(s);
}

var k = 0;
for (var i=0; i<100; ++i)
	for (var j=0; j<=i; ++j) {
		log(i, j);
		k++;
	}
log(k);
