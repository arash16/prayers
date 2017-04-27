function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
	var s = '';
	for (var i=0; i<n; i++)
		s += String.fromCharCode(65+rand(0, 25));
	log(s);
}

for (var len=1; len<=1000; len++)
	for (var i=0; i<2; i++) 
		generate(len);
log('end');
