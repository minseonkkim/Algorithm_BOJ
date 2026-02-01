const fs = require('fs');
const [nm, ...input] = fs.readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, m] = nm.trim().split(' ').map(Number);

let students = [];
let cnt = Array(n + 1).fill(0);
for(let i = 0; i < input.length; i++){
	let [clss, name] = input[i].trim().split(' ');
	let cls = Number(clss);
	if(cls === 0) break;
	let team; // 청팀: 1, 백팀: 2
	if(cls % 2 === 0) team = 2;
	else team = 1;
	
	let student = {
		team: team,
		cls: cls,
		name: name
	};
	if(cnt[cls] < m){
		students.push(student);
		cnt[cls]++;
	}
}
students.sort((a, b) => {
	if(a.cls === b.cls) {
		if(a.name.length == b.name.length) return a.name - b.name;
		else return a.name.length - b.name.length;
	}
	if(a.team === b.team) return a.cls - b.cls;
	return a.team - b.team;
});

for(let i = 0; i < students.length; i++){
 	console.log(students[i].cls + ' ' + students[i].name);
}
