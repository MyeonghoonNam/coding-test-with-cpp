const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `1
1 20:00`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const N = Number(input());
  let sum1 = 0;
  let sum2 = 0;
  let score1 = 0;
  let score2 = 0;
  let prev = "";

  const ret = [];

  function print(time) {
    const m = String(parseInt(time / 60));
    const s = String(time % 60);

    return `${m.padStart(2, "0")}:${s.padStart(2, "0")}`;
  }

  function changeToInt(time) {
    return Number(time.substr(0, 2)) * 60 + Number(time.substr(3, 2));
  }

  function go(time) {
    return changeToInt(time) - changeToInt(prev);
  }

  for (let i = 0; i < N; i++) {
    const [team, time] = input().split(" ");

    if (score1 > score2) {
      sum1 += go(time);
    } else if (score2 > score1) {
      sum2 += go(time);
    }

    team === "1" ? score1++ : score2++;
    prev = time;
  }

  if (score1 > score2) {
    sum1 += go("48:00");
  } else if (score2 > score1) {
    sum2 += go("48:00");
  }

  ret.push(print(sum1));
  ret.push(print(sum2));

  return ret.join("\n");
}

console.log(solution());
