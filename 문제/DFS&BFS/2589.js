const fs = require("fs");
const stdin = (
  process.platform === "linux"
    ? fs.readFileSync("/dev/stdin").toString()
    : `5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW`
).split("\n");

const input = (() => {
  let line = 0;
  return () => stdin[line++];
})();

class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  enqueue(value) {
    const newNode = new Node(value);

    if (this.size === 0) {
      this.head = this.tail = newNode;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
    }

    this.size++;
  }

  dequeue() {
    const popNode = this.head;
    this.head = popNode.next;

    if (this.length === 1) {
      this.tail = null;
    }

    this.size--;

    return popNode.value;
  }

  isEmpty() {
    return this.size === 0;
  }
}

function solution() {
  const [N, M] = input().split(" ").map(Number);
  const map = [];
  let visited = Array.from(new Array(N), () => new Array(M).fill(0));
  let ret = 0;

  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];

  for (let i = 0; i < N; i++) {
    map.push(input());
  }

  function bfs(y, x) {
    const queue = new Queue();
    queue.enqueue([y, x, 0]);
    visited[y][x] = 1;

    let maxDist = 0;

    while (!queue.isEmpty()) {
      const [y, x, d] = queue.dequeue();

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

        if (map[ny][nx] === "L" && !visited[ny][nx]) {
          queue.enqueue([ny, nx, d + 1]);
          visited[ny][nx] = 1;
          maxDist = d + 1;
        }
      }
    }

    return maxDist;
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (map[i][j] === "L" && !visited[i][j]) {
        ret = Math.max(bfs(i, j), ret);
        visited = Array.from(new Array(N), () => new Array(M).fill(0));
      }
    }
  }

  return ret;
}

console.log(solution());
