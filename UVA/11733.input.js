function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n, m, c) {
	log (n, m, rand(1, 100));
	for (var i=0; i<m; ++i)
		log (rand(1,6), rand(4, 10), rand(1,100));
	log('');
}


log(3000);
for (var i=0; i<3000; ++i)
	generate(10, 30);

//generate(10000, 100000, 100);
