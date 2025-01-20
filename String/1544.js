const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = parseInt(input[0]);

let check = new Set();
let answer = 0;

for(let i = 1; i <= n; i++){
    if(!check.has(input[i])) answer++;
    else continue;

    check.add(input[i]);
    for(let j = 1; j < input[i].length; j++){
        let newword = input[i].substr(j) + input[i].substr(0, j);
        check.add(newword);
    }
}

console.log(answer);
