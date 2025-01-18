const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, m] = input[0].split(' ').map(Number);
const j = parseInt(input[1]);

let left = 1;
let right = m;
let answer = 0;

for(let i = 2; i < 2 + j; i++){
    const fall = parseInt(input[i]);
	if(fall >= left && fall <= right) continue;
	
	if(fall > right){
		const offset = fall - right;
		left += offset;
		right += offset;
		answer += offset;
	} else if(fall < left){
		const offset = left - fall;
		left -= offset;
		right -= offset;
		answer += offset;
	}
}
console.log(answer);
