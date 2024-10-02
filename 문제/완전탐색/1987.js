const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5 5
IEFCJ
FHFKC
FFALF
HFGCF
HMCHH`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

function solution() {
  const [R, C] = input().split(" ").map(Number);
  const board = [];
  const visited = new Array(26).fill(0);
  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];
  let result = 0;

  for (let i = 0; i < R; i++) {
    const row = input().split("");
    board.push(row);
  }

  function go(y, x, cnt) {
    result = Math.max(result, cnt);

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;

      if (visited[board[ny][nx].charCodeAt() - "A".charCodeAt()] === 0) {
        visited[board[ny][nx].charCodeAt() - "A".charCodeAt()] = 1;
        go(ny, nx, cnt + 1);
        visited[board[ny][nx].charCodeAt() - "A".charCodeAt()] = 0;
      }
    }
  }

  visited[board[0][0].charCodeAt() - "A".charCodeAt()] = 1;
  go(0, 0, 1);

  return result;
}

console.log(solution());
