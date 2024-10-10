const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `6
100 70 90 10
30 55 10 8 100
60 10 10 2 70
10 80 50 0 50
40 30 30 8 60
60 10 70 2 120
20 70 50 4 4`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const N = Number(input());
  const [mp, mf, ms, mv] = input().split(" ").map(Number);
  const foods = {};
  let ret = Number.MAX_SAFE_INTEGER;
  let retArr = [];

  for (let i = 1; i <= N; i++) {
    const [p, f, s, v, c] = input().split(" ").map(Number);

    foods[i] = {
      p,
      f,
      s,
      v,
      c,
    };
  }

  for (let i = 1; i < 1 << N; i++) {
    const selected = [];
    let [p, f, s, v, sum] = [0, 0, 0, 0, 0];

    for (let j = 0; j < N; j++) {
      if (i & (1 << j)) {
        const idx = j + 1;
        selected.push(idx);
        p += foods[idx].p;
        f += foods[idx].f;
        s += foods[idx].s;
        v += foods[idx].v;
        sum += foods[idx].c;
      }
    }

    if (p >= mp && f >= mf && s >= ms && v >= mv) {
      if (ret >= sum) {
        if (ret > sum) retArr = [];

        ret = sum;
        retArr.push(selected.join(" "));
      }
    }
  }

  if (ret === Number.MAX_SAFE_INTEGER) {
    return -1;
  } else {
    retArr.sort();
    return [ret, retArr[0]].join("\n");
  }
}

console.log(solution());
