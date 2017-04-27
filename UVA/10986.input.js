function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate(n) {
	var m = Math.min(rand(n, n*(n-1)>>1), 50000);

	log (n, m, rand(0, n), rand(0, n));

	var tr = [];

	for (var i=0; i<m; i++) {
		do {
			var u = rand(0, n),
				v = rand(0, n);
		} while (tr[u*n + v] || tr[v*n + u]);
		
		tr[u*n + v] = true;
		log (u, v, rand(1, 10000));
	}
	log();
}

log(1);
generate(20000);

//for (var i=0; i<10; i++)
//	generate(rand(4, 10));
