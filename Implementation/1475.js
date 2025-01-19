const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim();

let count = Array(10).fill(0);

for (let i = 0; i < input.length; i++) {
  const num = parseInt(input[i]);
  count[num]++;
}

if ((count[6] + count[9]) % 2 === 0) count[6] = Math.floor((count[6] + count[9]) / 2);
else count[6] = Math.floor((count[6] + count[9]) / 2) + 1;

count[9] = 0;

console.log(Math.max(...count));
