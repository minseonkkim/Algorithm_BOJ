const fs = require('fs');
const [m, n] = fs.readFileSync('/dev/stdin', 'utf8').trim().split(' ').map(Number);

const toEng = {
  '0': 'zero',
  '1': 'one',
  '2': 'two',
  '3': 'three',
  '4': 'four',
  '5': 'five',
  '6': 'six',
  '7': 'seven',
  '8': 'eight',
  '9': 'nine',
};

let readnum = [];
for(let i = m; i <= n; i++){
  let num = i.toString();
  let toStr = "";
  for(let j = 0; j < num.length; j++){
      toStr += toEng[num[j]];
      if(j != num.length - 1) toStr += " ";
  }
  readnum.push([i, toStr]);
}

readnum.sort((a, b) => {
    if(a[1] > b[1]) return 1;
    if(a[1] < b[1]) return -1;
});

let answer = "";
for(let i = 0; i < readnum.length; i++){
  answer += readnum[i][0].toString();
  if((i + 1) % 10 === 0) answer += "\n";
  else answer += " ";
}
console.log(answer);
