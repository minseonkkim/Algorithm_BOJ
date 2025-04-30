const fs = require('fs');
const [n, ...board] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n')
    .map((v, i) => i == 0 ? parseInt(v) : v.split(' ').map(Number));

let maxnum = 0, maxcnt = 0;
for(let i = 0; i < n; i++){
    let same = new Array(n).fill(false);
    for(let j = 0; j < 5; j++){
        for(let k = 0; k < n; k++){
            if(i === k) continue;
            if(board[i][j] == board[k][j]) same[k] = true;
        }
    }
    let cnt = 0;
    for(let j = 0; j < n; j++){
        if(same[j]) cnt++;
    }
    if(cnt > maxcnt) {
        maxcnt = cnt;
        maxnum = i;
    }
}
console.log(maxnum + 1);
