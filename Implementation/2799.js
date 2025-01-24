const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [m, n] = input[0].split(' ').map(Number);

let typecnt = Array(5).fill(0);
for(let i = 0; i < m; i++){
    for(let j = 0; j < n; j++){
        const startx = 2 + i * 5;
        const starty = 1 + j * 5;
        let cnt = 0;
        for(let k = startx; k < startx + 4; k++){
            if(input[k][starty] === '*') cnt++;
            else break;
        }
        typecnt[cnt]++;
    }
}

let answer = "";
for(let i = 0; i < 5; i++){
    answer += typecnt[i] + " ";
}
console.log(answer.trim());
