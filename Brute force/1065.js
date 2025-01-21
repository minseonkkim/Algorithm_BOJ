const fs = require('fs');
const n = parseInt(fs.readFileSync('/dev/stdin', 'utf8').trim());

let cnt = 0;
for(let i = 1; i <= n; i++){
    const str = i.toString();
    if(str.length <= 2) {
        cnt++;
        continue;
    }
    if((parseInt(str[1]) - parseInt(str[0])) === (parseInt(str[2]) - parseInt(str[1]))) cnt++;
}
console.log(cnt);
