const fs = require('fs');
const [N, M, ...input] = fs.readFileSync('/dev/stdin', 'utf8').split('\n');
const n = Number(N);
const m = Number(M);

let size = [0, ];
for(let i = 0; i < n; i++){
	if(input[i] == 'S') size.push(0);
	else if(input[i] == 'M') size.push(1);
	else size.push(2);
}

let used = Array(size.length).fill(false);
let answer = 0;
for(let i = n; i < n + m; i++){
	let [tp, nb] = input[i].split(' ');
	let num = Number(nb);
	let sz;
	if(tp == 'S') sz = 0;
	else if(tp == 'M') sz = 1;
	else sz = 2;
	
	if(size[num] >= sz && !used[num]){
		used[num] = true;
		answer++;
	}
}
console.log(answer);
