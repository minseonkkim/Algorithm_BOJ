const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = parseInt(input[0]);
const [...students] = input.slice(1).map((v) => v.split(' ').map(Number));

students.sort((a, b) => b[2] - a[2]);

console.log(students[0][0], students[0][1]);
console.log(students[1][0], students[1][1]);
if(students[0][0] === students[1][0]){
    for(let i = 2; i < students.length; i++){
        if(students[i][0] !== students[0][0]){
            console.log(students[i][0], students[i][1]);
            break;
        }
    }
} else{
    console.log(students[2][0], students[2][1]);
}
