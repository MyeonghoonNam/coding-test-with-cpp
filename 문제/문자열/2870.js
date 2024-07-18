const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `4
01bond
02james007
03bond
04austinpowers000`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const N = Number(input());
  const regex = /[^0-9]/g;
  const ret = [];

  for (let i = 0; i < N; i++) {
    const line = input();
    const matches = line
      .replace(regex, "/")
      .split("/")
      .filter(Boolean)
      .map(BigInt);

    for (let number of matches) {
      ret.push(number);
    }
  }
  ret.sort((a, b) => {
    return a >= b ? 1 : -1;
  });

  console.log(ret.join("\n"));
}

solution();
