const fs = require('fs');
const [a, b] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = Number(a.split(' ')[0]);
const newscore = Number(a.split(' ')[1]);
const p = Number(a.split(' ')[2]);
if(n == 0){
    console.log(1);
    return;
}
const rank = b.split(' ').map((v) => Number(v));
if(n == p && rank[n - 1] >= newscore){
    console.log(-1);
    return;
}
let answer = 1;
for (let i = 0; i < n; i++) {
    if (rank[i] > newscore) {
        answer++;
    } else {
        break;
    }
}
console.log(answer);
