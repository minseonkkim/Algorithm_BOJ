const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n').map(arr => arr.split(' '));

const dx = [-1, 0, 0, 1];
const dy = [0, -1, 1, 0];

let set = new Set();

function dfs(x, y, str){
  if(str.length === 6){
    set.add(str);
  } else{
    for(let i = 0; i < 4; i++){
      let nx = x + dx[i];
      let ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
      dfs(nx, ny, str + input[x][y]);
    }
  }
}

for(let i = 0; i < 5; i++){
  for(let j = 0; j < 5; j++){
    dfs(i, j, "");
  }
}

console.log(set.size);
