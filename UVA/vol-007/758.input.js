function rand(a, b){ return Math.floor(a + Math.random() * (b-a+1)); }
var log = console.log.bind(console);

var colors = 'RGB';
function generate() {
	log('');
	for (var i=0; i<10; i++) {
		var str = '';
		for (var j=0; j<15; ++j)
			str += colors[rand(0,2)]
		
		log(str);
	}
}

log(100);
for (var i=0; i<100; i++) 
	generate();
