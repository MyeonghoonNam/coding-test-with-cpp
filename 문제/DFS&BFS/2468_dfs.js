const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const N = Number(input());
  const map = [];
  let visited = [];

  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  let result = 1;

  function dfs(y, x, h) {
    visited[y][x] = 1;

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

      if (map[ny][nx] > h && !visited[ny][nx]) {
        dfs(ny, nx, h);
      }
    }
  }

  for (let i = 0; i < N; i++) {
    const row = input().split(" ").map(Number);
    map.push(row);
  }

  for (let h = 1; h < 101; h++) {
    let count = 0;
    visited = Array.from(new Array(N), () => new Array(N).fill(0));

    for (let i = 0; i < N; i++) {
      for (let j = 0; j < N; j++) {
        if (map[i][j] > h && !visited[i][j]) {
          dfs(i, j, h);
          count += 1;
        }
      }
    }

    result = Math.max(result, count);
  }

  return result;
}

console.log(solution());
