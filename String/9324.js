const fs = require('fs');
const [n, ...messages] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n')
    .map((v, i) => i == 0 ? parseInt(v) : v);

for(let i = 0; i < messages.length; i++){
    const message = messages[i];

    let cnt = new Array(26).fill(0);
    let isReal = true;
    for(let j = 0; j < message.length; j++){
        let code = message.charCodeAt(j) - "A".charCodeAt(0);
        cnt[code]++;
        if(cnt[code] === 3){
            if(j === message.length - 1 || message[j] !== message[j + 1]){
                isReal = false;
                break;
            }
            cnt[code] = 0;
            j++;
        }
    }
    if(isReal) console.log("OK");
    else console.log("FAKE");
}
