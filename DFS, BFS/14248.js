const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = parseInt(input[0]);
const jump = input[1].split(' ').map((v) => parseInt(v));
const s = parseInt(input[2]);

let visited = new Array(n + 1).fill(false);
let queue = [];
let head = 0;
queue.push(s);
visited[s] = true;
while(head < queue.length){
    const cur = queue[head++];
    const nxt1 = cur + jump[cur - 1];
    if(nxt1 <= n && !visited[nxt1]){
        visited[nxt1] = true;
        queue.push(nxt1);
    }
    const nxt2 = cur - jump[cur - 1];
    if(nxt2 >= 1 && !visited[nxt2]){
        visited[nxt2] = true;
        queue.push(nxt2);
    }
}
let cnt = 0;
for(let i = 1; i <= n; i++){
    if(visited[i]) cnt++;
}
console.log(cnt);
