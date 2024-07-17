const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `9 77
11 33 11 77 54 11 25 25 33`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const [N, C] = input().split(" ").map(Number);
  const arr = input().split(" ").map(Number);
  const map = {};
  const sortArr = [];
  const ret = [];

  for (let i = 0; i < N; i++) {
    const value = arr[i];

    if (!map[value]) {
      map[value] = {
        count: 1,
        order: i,
        value,
      };
    } else {
      map[value].count += 1;
    }
  }

  for (let key in map) {
    sortArr.push(map[key]);
  }

  sortArr.sort((a, b) => b.count - a.count || a.order - b.order);

  for (let obj of sortArr) {
    const { count, value } = obj;

    for (let i = 0; i < count; i++) {
      ret.push(value);
    }
  }

  return ret.join(" ");
}

console.log(solution());
