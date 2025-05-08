const fs = require('fs');
const [info, ...move] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [k, r, n] = info.split(' ').map((v, i) => i == 2 ? parseInt(v) : v);


const cmd = {
    "R": [0, 1],
    "L": [0, -1],
    "B": [1, 0],
    "T": [-1, 0],
    "RT": [-1, 1],
    "LT": [-1, -1],
    "RB": [1, 1],
    "LB": [1, -1]
};

let king = [8 - parseInt(k.substr(1)), k.charCodeAt(0) - 'A'.charCodeAt(0)];
let rock = [8 - parseInt(r.substr(1)), r.charCodeAt(0) - 'A'.charCodeAt(0)];

for(let i = 0; i < n; i++){
    const cur = cmd[move[i]];
    const nking = [king[0] + cur[0], king[1] + cur[1]];
    const nrock = (nking[0] === rock[0] && nking[1] === rock[1])? [rock[0] + cur[0], rock[1] + cur[1]] : [...rock];

    if(nking[0] < 0 || nking[0] >= 8 || nking[1] < 0 || nking[1] >= 8 ||
      nrock[0] < 0 || nrock[0] >= 8 || nrock[1] < 0 || nrock[1] >= 8) continue;

    king = [...nking];
    rock = [...nrock];
}

console.log(`${String.fromCharCode('A'.charCodeAt(0) + king[1])}${8 - king[0]}`);
console.log(`${String.fromCharCode('A'.charCodeAt(0) + rock[1])}${8 - rock[0]}`);
