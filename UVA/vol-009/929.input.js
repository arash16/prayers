function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);


function generate(n, m) {
	log(n);
	log(m);
	
	for (var i=0; i<n; ++i) {
		var str = rand(0, 9);
		for (var j=1; j<m; ++j)
			str += ' ' + rand(0,9);
		log(str);
	}
}

log(30);
for (var i=0; i<30; i++) 
	generate(1000, 1000);
