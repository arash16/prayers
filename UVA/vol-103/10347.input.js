function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate() {
	log(rand(1, 100), rand(1, 100), rand(1, 100));
}

for (var i=0; i<50000; i++) 
	generate();
	
