function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

function generate() {
	var r = Math.random()*19999+1;
	log(parseInt(r*100)/100, rand(2, 19999));
}

for (var i=0; i<500; i++) 
	generate();
	
