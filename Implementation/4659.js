const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');

function isVowel(ch){
    if(ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u') return true;
    else return false;
}

for(let i = 0; i < input.length; i++){
    const pwd = input[i];
    if(pwd === "end") break;
    let cond1 = false;
    let cond2 = true;
    let cond3 = true;
    for(let j = 0; j < pwd.length; j++){
        const ch = pwd[j];
        const vowel = ch === 'a' || ch === 'e' || ch === 'i' || ch === 'o' || ch === 'u';
        if(vowel) cond1 = true;
        if(j !== 0) {
            if(ch != 'e' && ch != 'o'){
                if(ch === pwd[j - 1]) {
                    cond2 = false;
                    break;
                }
            }
        }
        if(j >= 2){
            const l1 = isVowel(pwd[j - 1]);
            const l2 = isVowel(pwd[j - 2]);
            if(l1 === l2 && l2 === vowel){
                cond3 = false;
                break;
            }
        }
    }
    if(cond1 && cond2 && cond3) console.log(`<${pwd}> is acceptable.`);
    else console.log(`<${pwd}> is not acceptable.`);
}
