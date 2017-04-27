function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
	log (n);

	var x = 0;
	log (0, 0);
	for (var i=0; i<n; i++) 
		log (x += rand(1, 5), rand(0, 10));
	log(x+5, 0);


	x = 5;
	for (var i=0; i<n; i++)
		log (rand(1, 10), rand(1, 10), x += rand(1, 5));
}

for (var i=0; i<500; i++)
	generate(rand(4, 10));
