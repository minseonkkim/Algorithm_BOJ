const fs = require('fs');
const input = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const n = parseInt(input[0]);
const students = input.slice(1).map(line => {
    const [name, d, m, y] = line.split(" ");
    const date = new Date(y, m - 1, d);
    return { name, date };
});

students.sort((a, b) => a.date - b.date);

console.log(students[n - 1].name);
console.log(students[0].name);
